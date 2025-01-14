/*
 * Sonic.c
 * Implementation of NSA Sonic Block Cipher
 * Copyright 2017 Michael Calvin McCoy
 * calvin.mccoy@gmail.com
 *  # The MIT License (MIT) - see LICENSE.md
*/

#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sonic.h"
#include "round.h"


void Sonic_Encrypt_x(const uint64_t *plaintext,
                        uint64_t *ciphertext,
                        int size,
                        int encryption){

    //split the plaintext in two half
    int size_half = size/128;
    
    state* left = malloc(sizeof(state));
    state* right = malloc(sizeof(state));
    left->size_64 = size_half;
    right->size_64 = size_half;
    left->data_64 = malloc(sizeof(uint64_t)*left->size_64);
    right->data_64 = malloc(sizeof(uint64_t)*right->size_64);
    
    for(int i=0;i<size_half;i++){
        left->data_64[i] = plaintext[i];
        right->data_64[i] = plaintext[i+size_half];
    }

    // call the permutation
    if(size==256 && encryption)
        sonic_256(left,right);
    else if(size==256 && !encryption)
        sonic_256_inv(left,right);
    else if(size==512 && encryption)
        sonic_512(left,right);
    else if(size==512 && !encryption)
        sonic_512_inv(left,right);

    //merge the two half in the ciphertext
    for(int i=0;i<size_half;i++){
        ciphertext[i] = left->data_64[i];
        ciphertext[i+size_half] = right->data_64[i];
    }
    
    free(left->data_64);
    free(right->data_64);
    free(left);
    free(right);
    
}


void Sonic_Encrypt_256(const uint64_t *plaintext,
                       uint64_t *ciphertext) {
    Sonic_Encrypt_x(plaintext,ciphertext,256,1);

}

void Sonic_Decrypt_256(const uint64_t *ciphertext,
                       uint64_t *plaintext) {
    Sonic_Encrypt_x(ciphertext,plaintext,256,0);

}

void Sonic_Encrypt_512(const uint64_t *plaintext,
                       uint64_t *ciphertext) {
    Sonic_Encrypt_x(plaintext,ciphertext,512,1);

}

void Sonic_Decrypt_512(const uint64_t *ciphertext,
                       uint64_t *plaintext) {
    Sonic_Encrypt_x(ciphertext,plaintext,512,0);

}



void Sonic_Encrypt_x_sub_round(const uint64_t *plaintext,
                        uint64_t *ciphertext,
                        int size,
                        int round){

    //split the plaintext in two half
    int size_half = size/128;
    
    state* left = malloc(sizeof(state));
    state* right = malloc(sizeof(state));
    left->size_64 = size_half;
    right->size_64 = size_half;
    left->data_64 = malloc(sizeof(uint64_t)*left->size_64);
    right->data_64 = malloc(sizeof(uint64_t)*right->size_64);
    
    for(int i=0;i<size_half;i++){
        left->data_64[i] = plaintext[i];
        right->data_64[i] = plaintext[i+size_half];
    }

    // call the permutation
    if(size==256)
        //sonic_256(left,right);
        sonic_256_sub_round(left,right,round);
    else if(size==512)
        sonic_512_sub_round(left,right,round);

    //merge the two half in the ciphertext
    for(int i=0;i<size_half;i++){
        ciphertext[i] = left->data_64[i];
        ciphertext[i+size_half] = right->data_64[i];
    }
    
    free(left->data_64);
    free(right->data_64);
    free(left);
    free(right);
    
}

void Sonic_Encrypt_256_sub_round(const uint64_t *plaintext,
                       uint64_t *ciphertext,
                       int round) {
    Sonic_Encrypt_x_sub_round(plaintext,ciphertext,256,round);

}

void Sonic_Encrypt_512_sub_round(const uint64_t *plaintext,
                       uint64_t *ciphertext,
                       int round) {
    Sonic_Encrypt_x_sub_round(plaintext,ciphertext,512,round);

}