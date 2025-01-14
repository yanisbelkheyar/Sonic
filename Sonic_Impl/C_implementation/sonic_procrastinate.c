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
#include "round_procrastinate.h"


void Sonic_Encrypt_x_procrastinate(const uint64_t *plaintext,
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
        sonic_256_procrastinate(left,right);
        //sonic_256_procrastinate(left,right);
    else if(size==256 && !encryption)
        sonic_256_inv_procrastinate(left,right);
        //sonic_256_inv_procrastinate(left,right);
    else if(size==512 && encryption)
        sonic_512_procrastinate(left,right);
    else if(size==512 && !encryption)
        sonic_512_inv_procrastinate(left,right);

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


void Sonic_Encrypt_256_procrastinate(const uint64_t *plaintext,
                       uint64_t *ciphertext) {
    Sonic_Encrypt_x_procrastinate(plaintext,ciphertext,256,1);

}

void Sonic_Decrypt_256_procrastinate(const uint64_t *ciphertext,
                       uint64_t *plaintext) {
    Sonic_Encrypt_x_procrastinate(ciphertext,plaintext,256,0);

}

void Sonic_Encrypt_512_procrastinate(const uint64_t *plaintext,
                       uint64_t *ciphertext) {
    Sonic_Encrypt_x_procrastinate(plaintext,ciphertext,512,1);

}

void Sonic_Decrypt_512_procrastinate(const uint64_t *ciphertext,
                       uint64_t *plaintext) {
    Sonic_Encrypt_x_procrastinate(ciphertext,plaintext,512,0);

}
