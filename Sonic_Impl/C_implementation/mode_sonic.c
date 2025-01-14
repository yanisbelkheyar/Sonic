#include "mode_sonic.h"
#include <stdlib.h>
#include <stdio.h>

void add( uint64_t* a, uint64_t* b,int size_64, uint64_t* output){
    for(int i=0;i<size_64;i++)
        output[i] = a[i] ^ b[i];
}

void copy_elt(uint64_t* input,int size_64,uint64_t* copy){
    for(int i=0;i<size_64;i++)
        copy[i] = input[i];
}

//Sonic_Boom
void sonic_boom_encrypt( uint64_t* plaintext,  uint64_t* key, uint64_t* ciphertext){
    int size_64 = 4;
    uint64_t* plaintext_with_key = malloc(sizeof(uint64_t)*size_64);

    add(plaintext,key,size_64,plaintext_with_key);

    Sonic_Encrypt_256(plaintext_with_key,ciphertext);

    add(key,ciphertext,size_64,ciphertext);

    free(plaintext_with_key);
}

void sonic_boom_decrypt( uint64_t* ciphertext,  uint64_t* key, uint64_t* plaintext){

    int size_64 = 4;
    uint64_t* ciphertext_with_key = malloc(sizeof(uint64_t)*size_64);
    add(ciphertext,key,size_64,ciphertext_with_key);
    
    Sonic_Decrypt_256(ciphertext_with_key,plaintext);

    add(key,plaintext,size_64,plaintext);

    free(ciphertext_with_key);
}


void encode_prefix_free( uint8_t* diversifier,int size_diversifier,int full_bloc,int size_64,uint64_t** input_bloc){
    
    int word_index = 0;
    //printf("%d nbr full bloc \n",full_bloc);
    for(int i=0;i<full_bloc;i++){
        input_bloc[i] = malloc(sizeof(uint64_t)*size_64);
        for(int j=0;j<28;j++){
            //printf("%x ,%d ",diversifier[word_index],((8-j-1)*8%64));
            input_bloc[i][j/8] ^=(uint64_t) diversifier[word_index] << ((8-j-1)*8%64);
            //printf("%lx \n",input_bloc[i][j/8]);
            word_index++;
        }
    }

    //for the last bloc
    input_bloc[full_bloc] = malloc(sizeof(uint64_t)*size_64);
    for(int j=0;j<size_diversifier%28;j++){
        input_bloc[full_bloc][j/8] ^=(uint64_t) diversifier[word_index] << ((8-j-1)*8%64);
        word_index++;
    }
    input_bloc[full_bloc][size_diversifier%4] ^=(uint64_t) 1<<(8-(size_diversifier%8)-1)*8;

}

//SoniK
void sonik( uint8_t* diversifier, int size_diversifier, uint64_t* key,uint64_t* output){
    
    int size_64 = 4;
    uint64_t* state = malloc(sizeof(uint64_t)*size_64);
    uint64_t* state_tmp = malloc(sizeof(uint64_t)*size_64);
    state[0] = key[0];
    state[1] = key[1];
    state[2] = key[2];
    state[3] = key[3];

    state_tmp[0] = 0;
    state_tmp[1] = 0;
    state_tmp[2] = 0;
    state_tmp[3] = 0;


    //initialization round
    Sonic_Encrypt_256(state,state_tmp);

    add(key,state_tmp,size_64,state);

    //absorbtion of diversifier

    int full_bloc = size_diversifier/28;

    uint64_t** input_bloc = malloc(sizeof(uint64_t*)*(full_bloc+1));

    encode_prefix_free(diversifier,size_diversifier,full_bloc,size_64,input_bloc);

    printf("paded diversifier: \n");
    for(int i=0;i<full_bloc+1;i++){
        //add input bloc
        for(int j=0;j<size_64;j++)
            printf("%lx ",input_bloc[i][j]);
        printf("\n");
        add(input_bloc[i],state,size_64,state);
        
        //apply the Sonic permutation
        Sonic_Encrypt_256(state,state_tmp);

        //apply the feedforward
        add(state_tmp,state,size_64,state);
    }

    copy_elt(state,size_64,output);

    for(int i=0;i<full_bloc+1;i++)
        free(input_bloc[i]);
    free(input_bloc);
    free(state_tmp);
    free(state);
}


void pad_input(uint8_t* input,int size_input,uint64_t** output,int decryption){

    int full_bloc = size_input/32;
    int word_index = 0;
    int size_64 = 4;

    for(int i=0;i<full_bloc;i++){
        output[i] = malloc(sizeof(uint64_t)*size_64);
        for(int j=0;j<size_64;j++)
            output[i][j] = 0;
        for(int j=0;j<32;j++){
            output[i][j/8] ^=(uint64_t) input[word_index] << ((8-j-1)*8 %64);
            word_index++;
        }
    }

    //for the last bloc
    output[full_bloc] = malloc(sizeof(uint64_t)*size_64);
    for(int j=0;j<size_64;j++)
            output[full_bloc][j] = 0;
    for(int j=0;j<size_input%32;j++){
        //printf("%x ",input[word_index]);
        output[full_bloc][j/8] ^=(uint64_t) input[word_index] << ((8-j-1)*8 %64);
        //printf("%lx \n",output[full_bloc][j/8]);
        word_index++;
    }
    if(!decryption){
        if(size_input%64==0){
            output[full_bloc][(size_input%32)/8] ^=(uint64_t) (uint64_t)80;
        }else{
            output[full_bloc][(size_input%32)/8] ^=(uint64_t) (uint64_t)80<<((8-size_input-1)*8%64);
        }
    }

}

//read the size bloc left most bytes in state and store them in ciphertext[index_ciohertext_bloc]
void extract_ciphertext(uint64_t* state,uint8_t* ciphertext,int index_ciphertext_bloc,int size_bloc){
    for(int i=0;i<size_bloc;i++){
        ciphertext[index_ciphertext_bloc+i] = (uint8_t) (state[i/8]>>((8-i-1)*8 %64));
    }
}

//Sonic Duplex
void sonic_duplex_encrypt(uint8_t* plaintext,
                        int plaintext_size,
                        uint8_t* ad,
                        int ad_size,
                        uint64_t* nonce,
                        uint64_t* key,
                        uint8_t* ciphertext,
                        uint64_t* tag){

    int size_64 = 8;
    int h_size_64 = 4;
    uint64_t* state = malloc(sizeof(uint64_t)*size_64);

    uint64_t iv[2] = {0,0};

    //initialization
    
    state[0] = key[0];
    state[1] = key[1];
    state[2] = key[2];
    state[3] = key[3];
    
    state[4] = iv[0];
    state[5] = iv[1];
    state[6] = nonce[2];
    state[7] = nonce[3];

    Sonic_Encrypt_512(state,state);

    add(state+4,key,h_size_64,state);

    //absorbtion additional data
    if(ad_size>=1){

        int full_ad = ad_size/32;

        uint64_t** paded_ad = malloc(sizeof(uint64_t*)*(full_ad+1));
        pad_input(ad,ad_size,paded_ad,0);

        printf("paded ad: \n");

        int laste = (ad_size%32==0)?1:0;

        for(int i=0;i<full_ad-laste;i++){
            for(int j=0;j<h_size_64;j++)
                printf("%lx ",paded_ad[i][j]);
            printf("\n");
            add(state,paded_ad[i],size_64/2,state);
            Sonic_Encrypt_512(state,state);
        }
        
        for(int j=0;j<h_size_64;j++)
            printf("%lx ",paded_ad[full_ad][j]);
        printf("\n");
        add(state,paded_ad[full_ad],size_64/2,state);
        Sonic_Encrypt_512(state,state);
        
        for(int i=0;i<full_ad+1;i++)
            free(paded_ad[i]);
        free(paded_ad);
    }

    state[7] ^= (uint64_t)1;

    //process plaintext

    //pad the plaintext the same way as for ad
    int full_plaintext = plaintext_size/32;
    uint64_t** paded_plaintext = malloc(sizeof(uint64_t*)*(full_plaintext+1));
    pad_input(plaintext,plaintext_size,paded_plaintext,0);

    printf("paded plaintext: \n");
    int laste = (plaintext_size%32==0)?1:0;
    //absorbe plaintext, set the ciphertext bloc to the left side and apply permutation
    for(int i=0;i<full_plaintext-laste;i++){
        for(int j=0;j<h_size_64;j++)
                printf("%lx ",paded_plaintext[i][j]);
            printf("\n");
        add(state,paded_plaintext[i],h_size_64,state);
        extract_ciphertext(state,ciphertext,i*32,32);
        Sonic_Encrypt_512(state,state);
    }

    //do the same for the last part of plaintext
    for(int j=0;j<h_size_64;j++)
            printf("%lx ",paded_plaintext[full_plaintext][j]);
        printf("\n");
    add(state,paded_plaintext[full_plaintext],h_size_64,state);

    extract_ciphertext(state,ciphertext,full_plaintext,plaintext_size%32);

    for(int i=0;i<full_plaintext+1;i++){
        free(paded_plaintext[i]);
    }
    free(paded_plaintext);

    //finalization

    add(state,key,size_64/2,state);
    add(state+4,key,size_64/2,tag);

}

void sonic_duplex_decrypt(uint8_t* plaintext,
                        int ciphertext_size,
                        uint8_t* ad,
                        int ad_size,
                        uint64_t* nonce,
                        uint64_t* key,
                        uint8_t* ciphertext,
                        uint64_t* tag){

    int size_64 = 8;
    int h_size_64 = 4;
    uint64_t* state = malloc(sizeof(uint64_t)*size_64);

    uint64_t iv[2] = {0,0};

    //initialization
    
    state[0] = key[0];
    state[1] = key[1];
    state[2] = key[2];
    state[3] = key[3];
    
    state[4] = iv[0];
    state[5] = iv[1];
    state[6] = nonce[2];
    state[7] = nonce[3];

    Sonic_Encrypt_512(state,state);

    add(state+4,key,h_size_64,state);

    //absorbtion additional data
    if(ad_size>=1){

        int full_ad = ad_size/32;

        uint64_t** paded_ad = malloc(sizeof(uint64_t*)*(full_ad+1));
        pad_input(ad,ad_size,paded_ad,0);

        printf("paded ad: \n");

        int laste = (ad_size%32==0)?1:0;

        for(int i=0;i<full_ad-laste;i++){
            for(int j=0;j<h_size_64;j++)
                printf("%lx ",paded_ad[i][j]);
            printf("\n");
            add(state,paded_ad[i],size_64/2,state);
            Sonic_Encrypt_512(state,state);
        }
        
        for(int j=0;j<h_size_64;j++)
            printf("%lx ",paded_ad[full_ad][j]);
        printf("\n");
        add(state,paded_ad[full_ad],size_64/2,state);
        Sonic_Encrypt_512(state,state);
        
        for(int i=0;i<full_ad+1;i++)
            free(paded_ad[i]);
        free(paded_ad);
    }

    state[7] ^= (uint64_t)1;

    //process plaintext

    //pad the plaintext the same way as for ad
    int full_ciphertext = ciphertext_size/32;
    uint64_t** paded_ciphertext = malloc(sizeof(uint64_t*)*(full_ciphertext+1));
    pad_input(ciphertext,ciphertext_size,paded_ciphertext,1);

    printf("paded ciphertext: \n");
    int laste = (ciphertext_size%32==0)?1:0;
    for(int i=0;i<full_ciphertext-laste;i++){
        for(int j=0;j<h_size_64;j++)
                printf("%lx ",paded_ciphertext[i][j]);
        printf("\n");
        add(state,paded_ciphertext[i],h_size_64,state);
        extract_ciphertext(state,plaintext,i*32,32);
        add(state,state,h_size_64,state);
        add(state,paded_ciphertext[i],h_size_64,state);

        Sonic_Encrypt_512(state,state);
    }

    //do the same for the last part of plaintext
    for(int j=0;j<h_size_64;j++)
            printf("%lx ",paded_ciphertext[full_ciphertext][j]);
        printf("\n");

    add(state,paded_ciphertext[full_ciphertext],h_size_64,state);
    extract_ciphertext(state,plaintext,full_ciphertext,ciphertext_size%32);
    add(state,state,h_size_64,state);
    add(state,paded_ciphertext[full_ciphertext],h_size_64,state);

    for(int i=0;i<full_ciphertext+1;i++){
        free(paded_ciphertext[i]);
    }
    free(paded_ciphertext);

    //finalization

    add(state,key,size_64/2,state);
    add(state+4,key,size_64/2,tag);

}