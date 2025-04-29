#include "crypto_aead.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include<unistd.h>

#define PRINT 1

void test_Sonic_Duplex(int size_input){

    int size = 1;
    int h_size = 4;

    int sizekey = 32;
    int sizem = size_input;
    int sizead = 0;

    unsigned char* key = (unsigned char*)calloc(sizekey,sizeof(unsigned char));
    unsigned char* nonce = (unsigned char*)calloc(16,sizeof(unsigned char));
    unsigned char* ad = (unsigned char*)calloc(sizead,sizeof(uint8_t));
    unsigned char* plaintext = (unsigned char*)calloc(sizem,sizeof(uint8_t));
    unsigned char* ciphertext = (unsigned char*)calloc((sizem+16),sizeof(uint8_t));
    unsigned long long* clen = (unsigned long long*)calloc(1,sizeof(unsigned long long));
    unsigned long long* mlen = (unsigned long long*)calloc(1,sizeof(unsigned long long));
    unsigned char *nsec = (unsigned char*)calloc(1,sizeof(unsigned char));

    unsigned char* ciphertext2 = (unsigned char*)calloc((sizem+16),sizeof(uint8_t));

    struct timespec tstart={0,0}, tend={0,0};
    clock_gettime(CLOCK_MONOTONIC, &tstart);
    
    srand(time(NULL));

    for(int test=0;test<100;test++){


        *mlen = sizem;

        if(PRINT){
            printf("\n\nTest for Sonic Duplex: \n\n");
            printf("ad: ");
        }
        for(int i=0;i<sizead;i++){
            ad[i] = (uint8_t)rand()%256;
            if(PRINT)
                printf("%x ",ad[i]);
        }
        if(PRINT)
            printf("\n");

        if(PRINT)
            printf("plaintext: ");
        for(int i=0;i<sizem;i++){
            plaintext[i] = (uint8_t)rand()%256;
            if(PRINT)
                printf("%x ",plaintext[i]);
        }
        if(PRINT)
            printf("\n");

        for(int i=0;i<sizem+16;i++){
            ciphertext[i] = 0;
        }

        if(PRINT)
            printf("nonce:     ");
        for(int i=0;i<16;i++){
            nonce[i] = (uint8_t)rand()%256;
            if(PRINT)
                printf("%x ",nonce[i]);
        }
        if(PRINT)
            printf("\n");

        if(PRINT)
            printf("key:       ");
        for(int i=0;i<sizekey;i++){
            key[i] = (uint8_t)rand()%256;
            if(PRINT)
                printf("%x ",key[i]);
        }
        if(PRINT)
            printf("\n");

        
        //sonic_duplex_encrypt(plaintext,sizem,ad,sizead,nonce,key,ciphertext, clen,tag);
        crypto_aead_encrypt(ciphertext,clen,plaintext,*mlen,ad,sizead,nsec,nonce,key);

        if(PRINT)
            printf("ciphertext:   ");
        for(int i=0;i<*mlen;i++){
            plaintext[i] = 0;
            if(PRINT)
                printf("%x ",ciphertext[i]);
        }
        if(PRINT)
            printf("\n");

        if(PRINT){
            printf("tag:   ");
            for(int i=0;i<16;i++)
                printf("%x ",ciphertext[i+(*mlen)]);
            printf("\n");
        }

        //ciphertext[0] ^= 1;
        int tag = crypto_aead_decrypt(plaintext,mlen,nsec,ciphertext,*clen,ad,sizead,nonce,key);
        
        if(PRINT){
            printf("plaintext: ");
            for(int i=0;i<sizem;i++){
                printf("%x ",plaintext[i]);
            }
            printf("\n");

            (tag==0)?printf("tag correct \n"):printf("tag wrong\n");
        }

        if(tag==-1){
            printf("tag wrong\n");
            sleep(1);
        }

        if(test==0){
            for(int i=0;i<*clen;i++)
                ciphertext2[i] = ciphertext[i]; 
        }else{
            for(int i=0;i<*clen;i++)
                if(ciphertext2[i] != ciphertext[i]){
                    printf("non deterministic \n");
                    exit(0);
                }
        }

    }

    clock_gettime(CLOCK_MONOTONIC, &tend);
        
    printf("total time took about %.10e seconds\n",
        (((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) - 
        ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec))/100);

    free(key);
    free(ad);
    free(plaintext);
    free(ciphertext);
    free(ciphertext2);
    free(nonce);
    free(clen);
    free(mlen);
    free(nsec);
}



int main(){

    for(int i=1;i<2;i++){
        test_Sonic_Duplex(i);
    }
    return 0;
    
}