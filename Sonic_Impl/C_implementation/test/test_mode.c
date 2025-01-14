#include "../mode_sonic.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>


void test_SonicBoom(){
    int size = 4;
    uint64_t* plaintext = malloc(sizeof(uint64_t)*size);
    uint64_t* ciphertext = malloc(sizeof(uint64_t)*size);
    uint64_t* key = malloc(sizeof(uint64_t)*size);

    //test for Sonic Boom
    printf("Test for SonicBoom:\n\n");

    printf("plaintext: ");
    for(int i=0;i<size;i++){
        plaintext[i] = rand() ^ (uint64_t)rand()<<32 ;
        printf("%lx ",plaintext[i]);
    }
    printf("\n");

    printf("key:       ");
    for(int i=0;i<size;i++){
        key[i] = rand() ^ (uint64_t)rand()<<32 ;
        printf("%lx ",key[i]);
    }
    printf("\n");

    sonic_boom_encrypt(plaintext,key,ciphertext);

    printf("ciphertext: ");
    for(int i=0;i<size;i++)
        printf("%lx ",ciphertext[i]);
    printf("\n");

    sonic_boom_decrypt(ciphertext,key,plaintext);

    printf("plaintext: ");
    for(int i=0;i<size;i++)
        printf("%lx ",plaintext[i]);
    printf("\n");

    free(plaintext);
    free(ciphertext);
    free(key);
}

void test_SoniK(){
    int size = 4;
    int nbr_bloc = 31;

    uint64_t* key = malloc(sizeof(uint64_t)*size);
    uint8_t* diversifier = malloc(sizeof(uint8_t)*nbr_bloc);
    uint64_t* output = malloc(sizeof(uint64_t)*size);

    //test for Sonik

    printf("\n\nTest for Sonik: \n\n");
    printf("diversifier: ");
    for(int i=0;i<nbr_bloc;i++){
        diversifier[i] = (uint8_t)rand()%256;
        printf("%x ",diversifier[i]);
    }
    printf("\n");

    printf("key:       ");
    for(int i=0;i<size;i++){
        key[i] = rand() ^ (uint64_t)rand()<<32 ;
        printf("%lx ",key[i]);
    }
    printf("\n");

    sonik(diversifier,nbr_bloc,key,output);

    printf("output:   ");
    for(int i=0;i<size;i++)
        printf("%lx ",output[i]);
    printf("\n");

    free(key);
    free(diversifier);
    free(output);
}


void test_Sonic_Duplex(){
    int size = 8;
    int h_size = 4;
    int nbr_bloc = 10;
    int nbr_bloc_ad = 5;

    uint64_t* key = malloc(sizeof(uint64_t)*h_size);
    uint64_t* nonce = malloc(sizeof(uint64_t)*2);
    uint8_t* ad = malloc(sizeof(uint8_t)*nbr_bloc_ad);
    uint8_t* plaintext = malloc(sizeof(uint8_t)*nbr_bloc);
    uint8_t* ciphertext = malloc(sizeof(uint8_t)*nbr_bloc);
    uint64_t* tag = malloc(sizeof(uint64_t)*h_size);

    //test for Sonik

    printf("\n\nTest for Sonic Duplex: \n\n");
    printf("ad: ");
    for(int i=0;i<nbr_bloc;i++){
        ad[i] = 0;//(uint8_t)rand()%256;
        printf("%x ",ad[i]);
    }
    printf("\n");

    printf("plaintext: ");
    for(int i=0;i<nbr_bloc;i++){
        plaintext[i] = (uint8_t)rand()%256;
        printf("%x ",plaintext[i]);
    }
    printf("\n");

    printf("nonce:     ");
    for(int i=0;i<2;i++){
        nonce[i] = 0; //rand() ^ (uint64_t)rand()<<32 ;
        printf("%lx ",nonce[i]);
    }
    printf("\n");

    printf("key:       ");
    for(int i=0;i<h_size;i++){
        key[i] = 0;//rand() ^ (uint64_t)rand()<<32 ;
        printf("%lx ",key[i]);
    }
    printf("\n");

    sonic_duplex_encrypt(plaintext,nbr_bloc,ad,nbr_bloc_ad,nonce,key,ciphertext, tag);

    printf("ciphertext:   ");
    for(int i=0;i<nbr_bloc;i++){
        plaintext[i] = 0;
        printf("%x ",ciphertext[i]);
    }   
    printf("\n");

    printf("tag:   ");
    for(int i=0;i<h_size;i++)
        printf("%lx ",tag[i]);
    printf("\n");

    sonic_duplex_decrypt(plaintext,nbr_bloc,ad,nbr_bloc_ad,nonce,key,ciphertext,tag);

    printf("plaintext: ");
    for(int i=0;i<nbr_bloc;i++){
        printf("%x ",plaintext[i]);
    }
    printf("\n");

    printf("tag:   ");
    for(int i=0;i<h_size;i++)
        printf("%lx ",tag[i]);
    printf("\n");

    free(key);
    free(ad);
    free(plaintext);
    free(ciphertext);
    free(nonce);
    free(tag);
}

int main(){

    test_SonicBoom();

    test_SoniK();
    
    test_Sonic_Duplex();
    
}