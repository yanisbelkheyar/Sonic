#include "mode_sonic.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main(){

    int size = 4;
    int nbr_bloc = 150;

    uint64_t* plaintext = malloc(sizeof(uint64_t)*size);
    uint64_t* ciphertext = malloc(sizeof(uint64_t)*size);
    uint64_t* key = malloc(sizeof(uint64_t)*size);
    uint8_t* diversifier = malloc(sizeof(uint8_t)*nbr_bloc);
    uint64_t* output = malloc(sizeof(uint64_t)*size);


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

    //test for Sonik

    printf("\n\nTest for Sonik: \n\n");
    printf("diversifier: ");
    for(int i=0;i<10;i++){
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
    return 0;

}