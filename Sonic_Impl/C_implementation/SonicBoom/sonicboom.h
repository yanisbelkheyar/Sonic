#include <stdlib.h>
#include <stdio.h>

#include "Sonic256/permutation.h"
#include "Sonic256/permutation_procrastinate.h"

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


//Sonic_Boom
void sonic_boom_encrypt_procrastinate( uint64_t* plaintext,  uint64_t* key, uint64_t* ciphertext){
    int size_64 = 4;
    uint64_t* plaintext_with_key = malloc(sizeof(uint64_t)*size_64);

    add(plaintext,key,size_64,plaintext_with_key);

    Sonic_Encrypt_256_procrastinate(plaintext_with_key,ciphertext);

    add(key,ciphertext,size_64,ciphertext);

    free(plaintext_with_key);
}


void sonic_boom_decrypt_procrastinate( uint64_t* ciphertext,  uint64_t* key, uint64_t* plaintext){

    int size_64 = 4;
    uint64_t* ciphertext_with_key = malloc(sizeof(uint64_t)*size_64);
    add(ciphertext,key,size_64,ciphertext_with_key);
    
    Sonic_Decrypt_256_procrastinate(ciphertext_with_key,plaintext);

    add(key,plaintext,size_64,plaintext);

    free(ciphertext_with_key);
}