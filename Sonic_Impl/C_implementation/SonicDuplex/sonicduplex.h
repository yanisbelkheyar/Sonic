#include "Sonic512/permutation.h"
#include "Sonic512/permutation_procrastinate.h"

#include <stdlib.h>
#include <stdio.h>

#define PRINT 1
#define MASK_FULL 0xffffffffffffffff


void add( uint64_t* a, uint64_t* b,int size_64, uint64_t* output){
    for(int i=0;i<size_64;i++)
        output[i] = a[i] ^ b[i];
}

void add_byte(uint64_t* a,uint64_t* b, int size_byte,uint64_t* output){
    int rest_byte = (size_byte%8)<<3;
    int word_64 = size_byte>>3;
    for(int i=0;i<word_64;i++){
        output[i] = a[i] ^ b[i];
    }
    uint64_t mask = (uint64_t)MASK_FULL ^ (((uint64_t)1<<(64-rest_byte))-1);
    uint64_t mask2 = (((uint64_t)1<<(64-rest_byte))-1);

    output[word_64] = (a[word_64] &  mask) ^ (b[word_64] & mask) ^ (output[word_64] & mask2); 
}

void replace(uint64_t* a, int size_byte,uint64_t* output){
    int rest_byte = (size_byte%8)<<3;
    int word_64 = size_byte>>3;

    for(int i=0;i<word_64;i++){
        output[i] = a[i];
    }

    if(rest_byte!=0){
        uint64_t mask = (uint64_t)MASK_FULL ^ (((uint64_t)1<<(64-rest_byte))-1);
        uint64_t mask2 = (((uint64_t)1<<(64-rest_byte))-1);
        output[word_64] = (a[word_64] &  mask) ^ (output[word_64] & mask2); 
    }
}

//read the size bloc left most bytes in state and store them in ciphertext[index_ciohertext_bloc]
void extract_ciphertext(uint64_t* state,uint8_t* ciphertext,int index_ciphertext_bloc,int size_bloc){
    for(int i=0;i<size_bloc;i++){
        ciphertext[index_ciphertext_bloc+i] = (uint8_t) (state[i>>3]>>((8-i-1)<<3 %64));
    }
}

uint64_t* char_to_uint64(const unsigned char* input, int size_byte_input, uint64_t* output){

    output = malloc(sizeof(uint64_t)*(size_byte_input/8));
    for(int i=0;i<(size_byte_input>>3);i++)
        output[i] = 0;
    for(int j=0;j<size_byte_input;j++){
        output[j>>3] ^=(uint64_t) (input[j] << ((8-j-1)<<3 %64));
    }
    return output;
}

void set_key(uint64_t key[4], const unsigned char* k){
    for(int i=0;i<4;i++){
        for(int j=0;j<8;j++){
            key[i] ^= (uint64_t)k[j+(i<<3)]<<((8-j-1)<<3);
        }
    }
}

void set_nonce(uint64_t nonce[2], const unsigned char* npub){
    for(int i=0;i<2;i++){
        for(int j=0;j<8;j++){
            nonce[i] ^= (uint64_t)npub[j+(i<<3)]<<((8-j-1)<<3);
        }
    }
}

void set_absorb(uint64_t cur_absorb[4],const unsigned char* input, int index){
    for(int i=0;i<4;i++){
        cur_absorb[i] = 0;
        for(int j=0;j<8;j++){
            cur_absorb[i] ^= (uint64_t)input[index + j+(i<<3)]<<((8-j-1)<<3);
        }
    }
}


//Sonic Duplex
int sonic_duplex_encrypt_procrastinate(unsigned char* c, unsigned long long* clen,
    const unsigned char* m, unsigned long long mlen,
    const unsigned char* ad, unsigned long long adlen,
    const unsigned char *nsec,
    const unsigned char* npub,
    const unsigned char* k){

    *clen = mlen + 16;
    int size_64 = 8;
    int h_size_64 = 4;
    uint64_t* state = malloc(sizeof(uint64_t)*8);

    uint64_t iv[2] = {0,0};
    uint64_t key[4] =   {0,0,0,0}; //char_to_uint64(k,32,key);
    uint64_t nonce[2] = {0,0}; //char_to_uint64(npub,16,nonce);

    //set_key(key,k);
    //set_nonce(nonce,npub);
    
    //initialization

    state[4] = key[0];
    state[5] = key[1];
    state[6] = key[2];
    state[7] = key[3];

    state[0] = iv[0];
    state[1] = iv[1];
    state[2] = nonce[0];
    state[3] = nonce[1];

    sonic_512_procrastinate(state,state);
    add(state+4,key,h_size_64,state);

    uint64_t cur_absorbe[4] = {0,0,0,0};
    unsigned long long ad_id = 0;

    //absorbtion additional data
    while(adlen>=32){
        
        set_absorb(cur_absorbe,ad,ad_id);
        add(state,cur_absorbe,size_64/2,state);
        sonic_512_procrastinate(state,state);

        adlen -= 32;
        ad_id += 32;

    }

    if(adlen>=1){

        cur_absorbe[0] = 0;
        cur_absorbe[1] = 0;
        cur_absorbe[2] = 0;
        cur_absorbe[3] = 0;

        for(int i=0;i<adlen;i++){
            cur_absorbe[i>>3] ^=(uint64_t) ad[ad_id+i] << ((7-(i%8))<<3);
        }
        cur_absorbe[adlen>>3] ^= (uint64_t)80<<((7-(adlen%8))<<3);
        add(state,cur_absorbe,adlen>>3,state);
        sonic_512_procrastinate(state,state);
    }

    state[7] ^= (uint64_t)1;

    //process plaintext
    unsigned long long m_id = 0;
    while(mlen>=32){

        set_absorb(cur_absorbe,m,m_id);
        add(state,cur_absorbe,h_size_64,state);
        extract_ciphertext(state,c,m_id,32);

        sonic_512_procrastinate(state,state);

        mlen -= 32;
        m_id += 32;

    }

    if(mlen>=1){

        cur_absorbe[0] = 0;
        cur_absorbe[1] = 0;
        cur_absorbe[2] = 0;
        cur_absorbe[3] = 0;

        for(int i=0;i<mlen;i++){
            cur_absorbe[i>>3] ^= (uint64_t)m[m_id+i] << ((7-(i%8))<<3);
        }
        cur_absorbe[mlen>>3] ^= (uint64_t)0x80<<((7-(mlen%8))<<3);

        add_byte(state,cur_absorbe,mlen,state);
        extract_ciphertext(state,c,m_id,mlen);
    }else{
        cur_absorbe[0] = (uint64_t)0x80 << 56;
        add_byte(state,cur_absorbe,1,state);
    }

    //finalization

    add(state,key,size_64/2,state);

    sonic_512_procrastinate(state,state);
    add(state+4,key,size_64/2,state+4);
    extract_ciphertext(state+4,c,*clen-16,16);

    free(state);
    return 1;

}


int sonic_duplex_decrypt_procrastinate(unsigned char* m, unsigned long long *mlen,
    const unsigned char *nsec,
    const unsigned char* c, unsigned long long  clen,
    const unsigned char* ad, unsigned long long  adlen,
    unsigned char* npub,
    unsigned char* k){

    *mlen = clen - 16;

    int size_64 = 8;
    int h_size_64 = 4;
    uint64_t* state = malloc(sizeof(uint64_t)*size_64);

    uint64_t iv[2] = {0,0};
    uint64_t key[4] =   {0,0,0,0}; //char_to_uint64(k,32,key);
    uint64_t nonce[2] = {0,0}; //char_to_uint64(npub,16,nonce);

    //set_key(key,k);
    //set_nonce(nonce,npub);

    //initialization

    state[4] = key[0];
    state[5] = key[1];
    state[6] = key[2];
    state[7] = key[3];

    state[0] = iv[0];
    state[1] = iv[1];
    state[2] = nonce[0];
    state[3] = nonce[1];

    sonic_512_procrastinate(state,state);

    add(state+4,key,h_size_64,state);

    uint64_t cur_absorbe[4] = {0,0,0,0};
    unsigned long long ad_id = 0;

    //absorbtion additional data
    while(adlen>=32){
        
        set_absorb(cur_absorbe,ad,ad_id);
        add(state,cur_absorbe,size_64/2,state);
        sonic_512_procrastinate(state,state);

        adlen -= 32;
        ad_id += 32;

    }

    if(adlen>=1){

        cur_absorbe[0] = 0;
        cur_absorbe[1] = 0;
        cur_absorbe[2] = 0;
        cur_absorbe[3] = 0;

        for(int i=0;i<adlen;i++){
            cur_absorbe[i>>3] ^=(uint64_t) ad[ad_id+i] << ((7-(i%8))<<3);
        }
        cur_absorbe[adlen>>3] ^= (uint64_t)80<<((7-(adlen%8))<<3);
        add(state,cur_absorbe,adlen>>3,state);
        sonic_512_procrastinate(state,state);
    }

    state[7] ^= (uint64_t)1;

    //process plaintext
    unsigned long long m_id = 0;
    while(*mlen>=32){

        set_absorb(cur_absorbe,c,m_id);
        add(state,cur_absorbe,h_size_64,state);
        extract_ciphertext(state,m,m_id,32);
        replace(cur_absorbe,32,state);

        sonic_512_procrastinate(state,state);

        *mlen -= 32;
        m_id += 32;

    }

    if(*mlen>=1){

        cur_absorbe[0] = 0;
        cur_absorbe[1] = 0;
        cur_absorbe[2] = 0;
        cur_absorbe[3] = 0;
        for(int i=0;i<*mlen;i++){
            cur_absorbe[i>>3] ^= (uint64_t)c[m_id+i] << ((7-(i%8))<<3);
        }
        cur_absorbe[(*mlen)>>3] ^= (uint64_t)0x80<<((7-((*mlen)%8))<<3);

        add_byte(state,cur_absorbe,(*mlen),state);
        extract_ciphertext(state,m,m_id,*mlen);
        replace(cur_absorbe,(*mlen),state);

    }else{
        cur_absorbe[0] = (uint64_t)0x80 << 56;
        add_byte(state,cur_absorbe,1,state);
    }

    //finalization

    add(state,key,size_64/2,state);

    sonic_512_procrastinate(state,state);
    add(state+4,key,size_64/2,state+4);

    unsigned char* tag = malloc(sizeof(unsigned char)*16);
    for(int i=0;i<16;i++)
        tag[i] = 0;
    extract_ciphertext(state+4,tag,0,16);

    //printf("tag:   ");
    //for(int i=0;i<16;i++)
    //   printf("%x ",(tag)[i]);
    //printf("\n");

    for(int i=0;i<16;i++){
        if((tag[i])!=c[clen-16+i]){
            free(state);
            free(tag);
            return 0;
        }
    }
    free(state);
    free(tag);
    return 1;
}


int sonic_duplex_encrypt(unsigned char* c, unsigned long long* clen,
    const unsigned char* m, unsigned long long mlen,
    const unsigned char* ad, unsigned long long adlen,
    const unsigned char *nsec,
    const unsigned char* npub,
    const unsigned char* k){

    *clen = mlen + 16;
    int size_64 = 8;
    int h_size_64 = 4;
    uint64_t* state = malloc(sizeof(uint64_t)*8);

    uint64_t iv[2] = {0,0};
    uint64_t key[4] =   {0,0,0,0}; //char_to_uint64(k,32,key);
    uint64_t nonce[2] = {0,0}; //char_to_uint64(npub,16,nonce);

    //set_key(key,k);
    //set_nonce(nonce,npub);
    
    //initialization

    state[4] = key[0];
    state[5] = key[1];
    state[6] = key[2];
    state[7] = key[3];

    state[0] = iv[0];
    state[1] = iv[1];
    state[2] = nonce[0];
    state[3] = nonce[1];

    sonic_512(state,state);
    add(state+4,key,h_size_64,state);

    uint64_t cur_absorbe[4] = {0,0,0,0};
    unsigned long long ad_id = 0;

    //absorbtion additional data
    while(adlen>=32){
        
        set_absorb(cur_absorbe,ad,ad_id);
        add(state,cur_absorbe,size_64/2,state);
        sonic_512_procrastinate(state,state);

        adlen -= 32;
        ad_id += 32;

    }

    if(adlen>=1){

        cur_absorbe[0] = 0;
        cur_absorbe[1] = 0;
        cur_absorbe[2] = 0;
        cur_absorbe[3] = 0;

        for(int i=0;i<adlen;i++){
            cur_absorbe[i>>3] ^=(uint64_t) ad[ad_id+i] << ((7-(i%8))<<3);
        }
        cur_absorbe[adlen>>3] ^= (uint64_t)80<<((7-(adlen%8))<<3);
        add(state,cur_absorbe,adlen>>3,state);
        sonic_512(state,state);
    }

    state[7] ^= (uint64_t)1;

    //process plaintext
    unsigned long long m_id = 0;
    while(mlen>=32){

        set_absorb(cur_absorbe,m,m_id);
        add(state,cur_absorbe,h_size_64,state);
        extract_ciphertext(state,c,m_id,32);

        sonic_512(state,state);

        mlen -= 32;
        m_id += 32;

    }

    if(mlen>=1){

        cur_absorbe[0] = 0;
        cur_absorbe[1] = 0;
        cur_absorbe[2] = 0;
        cur_absorbe[3] = 0;

        for(int i=0;i<mlen;i++){
            cur_absorbe[i>>3] ^= (uint64_t)m[m_id+i] << ((7-(i%8))<<3);
        }
        cur_absorbe[mlen>>3] ^= (uint64_t)0x80<<((7-(mlen%8))<<3);

        add_byte(state,cur_absorbe,mlen,state);
        extract_ciphertext(state,c,m_id,mlen);
    }else{
        cur_absorbe[0] = (uint64_t)0x80 << 56;
        add_byte(state,cur_absorbe,1,state);
    }

    //finalization

    add(state,key,size_64/2,state);

    sonic_512(state,state);
    add(state+4,key,size_64/2,state+4);
    extract_ciphertext(state+4,c,*clen-16,16);

    free(state);
    return 1;

}


int sonic_duplex_decrypt(unsigned char* m, unsigned long long *mlen,
    const unsigned char *nsec,
    const unsigned char* c, unsigned long long  clen,
    const unsigned char* ad, unsigned long long  adlen,
    unsigned char* npub,
    unsigned char* k){

    *mlen = clen - 16;

    int size_64 = 8;
    int h_size_64 = 4;
    uint64_t* state = malloc(sizeof(uint64_t)*size_64);

    uint64_t iv[2] = {0,0};
    uint64_t key[4] =   {0,0,0,0}; //char_to_uint64(k,32,key);
    uint64_t nonce[2] = {0,0}; //char_to_uint64(npub,16,nonce);

    //set_key(key,k);
    //set_nonce(nonce,npub);

    //initialization

    state[4] = key[0];
    state[5] = key[1];
    state[6] = key[2];
    state[7] = key[3];

    state[0] = iv[0];
    state[1] = iv[1];
    state[2] = nonce[0];
    state[3] = nonce[1];

    sonic_512(state,state);

    add(state+4,key,h_size_64,state);

    uint64_t cur_absorbe[4] = {0,0,0,0};
    unsigned long long ad_id = 0;

    //absorbtion additional data
    while(adlen>=32){
        
        set_absorb(cur_absorbe,ad,ad_id);
        add(state,cur_absorbe,size_64/2,state);
        sonic_512(state,state);

        adlen -= 32;
        ad_id += 32;

    }

    if(adlen>=1){

        cur_absorbe[0] = 0;
        cur_absorbe[1] = 0;
        cur_absorbe[2] = 0;
        cur_absorbe[3] = 0;

        for(int i=0;i<adlen;i++){
            cur_absorbe[i>>3] ^=(uint64_t) ad[ad_id+i] << ((7-(i%8))<<3);
        }
        cur_absorbe[adlen>>3] ^= (uint64_t)80<<((7-(adlen%8))<<3);
        add(state,cur_absorbe,adlen>>3,state);
        sonic_512(state,state);
    }

    state[7] ^= (uint64_t)1;

    //process plaintext
    unsigned long long m_id = 0;
    while(*mlen>=32){

        set_absorb(cur_absorbe,c,m_id);
        add(state,cur_absorbe,h_size_64,state);
        extract_ciphertext(state,m,m_id,32);
        replace(cur_absorbe,32,state);

        sonic_512(state,state);

        *mlen -= 32;
        m_id += 32;

    }

    if(*mlen>=1){

        cur_absorbe[0] = 0;
        cur_absorbe[1] = 0;
        cur_absorbe[2] = 0;
        cur_absorbe[3] = 0;
        for(int i=0;i<*mlen;i++){
            cur_absorbe[i>>3] ^= (uint64_t)c[m_id+i] << ((7-(i%8))<<3);
        }
        cur_absorbe[(*mlen)>>3] ^= (uint64_t)0x80<<((7-((*mlen)%8))<<3);

        add_byte(state,cur_absorbe,(*mlen),state);
        extract_ciphertext(state,m,m_id,*mlen);
        replace(cur_absorbe,(*mlen),state);

    }else{
        cur_absorbe[0] = (uint64_t)0x80 << 56;
        add_byte(state,cur_absorbe,1,state);
    }

    //finalization

    add(state,key,size_64/2,state);

    sonic_512_procrastinate(state,state);
    add(state+4,key,size_64/2,state+4);

    unsigned char* tag = malloc(sizeof(unsigned char)*16);
    for(int i=0;i<16;i++)
        tag[i] = 0;
    extract_ciphertext(state+4,tag,0,16);

    //printf("tag:   ");
    //for(int i=0;i<16;i++)
    //   printf("%x ",(tag)[i]);
    //printf("\n");

    for(int i=0;i<16;i++){
        if((tag[i])!=c[clen-16+i]){
            free(state);
            free(tag);
            return 0;
        }
    }
    free(state);
    free(tag);
    return 1;
}

