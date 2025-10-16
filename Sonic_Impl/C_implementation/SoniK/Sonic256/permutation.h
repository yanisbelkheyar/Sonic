
#include <stdlib.h>
#include <stdio.h>
#include "function.h"
#include "constante.h"


int reshuffle_128[17] = {5 ,65 ,13 ,105 ,21 ,81 ,93 ,121 ,101 ,97 ,45 ,9 ,53 ,113 ,125 ,25 ,5 };

void THETA_256(state* s1){
    state* tmp = malloc(sizeof(state));
    tmp->size_64 = s1->size_64;
    tmp->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);
    
    state* tmp1 = malloc(sizeof(state));
    tmp1->size_64 = s1->size_64;
    tmp1->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);


    shift(18,s1,tmp);
    shift(47,s1,tmp1);
    XOR(s1,tmp);
    XOR(s1,tmp1);

    free(tmp->data_64);
    free(tmp1->data_64);
    free(tmp);
    free(tmp1);
}


void sonic_256(state *left, state* right){
    const table_cst_128 table = {.table ={c_128_f9,c_128_47,c_128_eb,c_128_37,c_128_69,c_128_3b,c_128_49,c_128_3a,c_128_b0,c_128_7d,c_128_5b,c_128_4a,c_128_32,c_128_71,c_128_7b,c_128_4b}, .size=16};

    state* tmp = malloc(sizeof(state));
    tmp->size_64 = left->size_64;
    tmp->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);

    state* tmp1 = malloc(sizeof(state));
    tmp1->size_64 = left->size_64;
    tmp1->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);

    for(int i=0;i<NBR_ROUND256;i++){
        
        //apply F function to the right branch
        shift(1,left,tmp);
        AND(tmp,left);
        shift(5,left,tmp1);
        XOR(tmp,tmp1);
        XOR(right,tmp);

        PI(5,right);

        //apply theta to left branch
        THETA_256(left);
        ADD_CST_256(i,table,left);
        PI(5,left);

        swap(left,right);

    }

    PI(reshuffle_128[1],left);
    PI(reshuffle_128[1],right);

    free(tmp->data_64);
    free(tmp1->data_64);
    free(tmp);
    free(tmp1);

}


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
        sonic_256(left,right);
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

// --------- for testing purpuse and for computation of DP and correlation over reduce numbre of round -------

void sonic_256_sub_round(state *left, state* right,int round){

    const table_cst_128 table = {.table ={c_128_f9,c_128_47,c_128_eb,c_128_37,c_128_69,c_128_3b,c_128_49,c_128_3a,c_128_b0,c_128_7d,c_128_5b,c_128_4a,c_128_32,c_128_71,c_128_7b,c_128_4b}, .size=16};

    state* tmp = malloc(sizeof(state));
    tmp->size_64 = left->size_64;
    tmp->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);

    state* tmp1 = malloc(sizeof(state));
    tmp1->size_64 = left->size_64;
    tmp1->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);

    for(int i=0;i<round;i++){
        
        //apply F function to the right branch
        shift(1,left,tmp);
        AND(tmp,left);
        shift(5,left,tmp1);
        XOR(tmp,tmp1);
        XOR(right,tmp);
        PI(5,right);

        //apply theta to left branch
        THETA_256(left);
        PI(5,left);
        ADD_CST_256(i,table,left);

        swap(left,right);
    }

    free(tmp->data_64);
    free(tmp1->data_64);
    free(tmp);
    free(tmp1);

}

void Sonic_Encrypt_256_sub_round(const uint64_t *plaintext,
                        uint64_t *ciphertext,
                        int round){

    //split the plaintext in two half
    int size_half = 2;
    
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

    sonic_256_sub_round(left,right,round);

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