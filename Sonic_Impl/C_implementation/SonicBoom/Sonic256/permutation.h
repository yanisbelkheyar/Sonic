
#include <stdlib.h>
#include <stdio.h>
#include "function.h"
#include "constante.h"


int reshuffle_128[19] = {5 ,65 ,13 ,105 ,21 ,81 ,93 ,121 ,101 ,97 ,45 ,9 ,53 ,113 ,125 ,25 ,5 };

void THETA_256(state* s1){
    state* tmp = malloc(sizeof(state));
    tmp->size_64 = s1->size_64;
    tmp->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);
    
    state* tmp1 = malloc(sizeof(state));
    tmp1->size_64 = s1->size_64;
    tmp1->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);


    shift(16,s1,tmp);
    shift(40,s1,tmp1);
    XOR(s1,tmp);
    XOR(s1,tmp1);

    free(tmp->data_64);
    free(tmp1->data_64);
    free(tmp);
    free(tmp1);
}

void THETA256_inv(state* left){

    state* tmp = malloc(sizeof(state));
    tmp->size_64 = left->size_64;
    tmp->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);

    state* tmp1 = malloc(sizeof(state));
    tmp1->size_64 = left->size_64;
    tmp1->data_64 = malloc(sizeof(uint64_t)*tmp1->size_64);
    
    shift(16,left,tmp);
    shift(40,left,tmp1);
    XOR(tmp,tmp1);
    XOR(left,tmp);

    shift(80,left,tmp);
    shift(32,left,tmp1);
    XOR(tmp,tmp1);
    XOR(left,tmp);

    shift(64,left,tmp);
    shift(32,left,tmp1);
    XOR(tmp,tmp1);
    XOR(left,tmp);

    shift(64,left,tmp);
    copy(tmp,left);

    free(tmp->data_64);
    free(tmp1->data_64);
    free(tmp);
    free(tmp1);

}


void sonic_256(state *left, state* right){
    const table_cst_128 table = {.table ={c_128_f9,c_128_47,c_128_eb,c_128_37,c_128_69,c_128_3b,c_128_49,c_128_3a,c_128_b0,c_128_7d,c_128_5b,c_128_4a,c_128_32,c_128_71,c_128_7b,c_128_4b,c_128_cb,c_128_36}, .size=18};

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

    PI(reshuffle_128[3],left);
    PI(reshuffle_128[3],right);

    free(tmp->data_64);
    free(tmp1->data_64);
    free(tmp);
    free(tmp1);

}


void sonic_256_inv(state *left, state* right){
    
    const table_cst_128 table = {.table ={c_128_f9,c_128_47,c_128_eb,c_128_37,c_128_69,c_128_3b,c_128_49,c_128_3a,c_128_b0,c_128_7d,c_128_5b,c_128_4a,c_128_32,c_128_71,c_128_7b,c_128_4b,c_128_cb,c_128_36}, .size=18};

    state* tmp = malloc(sizeof(state));
    tmp->size_64 = left->size_64;
    tmp->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);

    state* tmp1 = malloc(sizeof(state));
    tmp1->size_64 = left->size_64;
    tmp1->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);

    PI(89,left);
    PI(89,right);

    for(int i=0;i<NBR_ROUND256;i++){

        swap(left,right);

        PI(77,left);
        ADD_CST_256_inv(i,table,left);
        THETA256_inv(left);
        
        PI(77,right);

        //apply F function to the right branch
        shift(1,left,tmp);
        AND(tmp,left); 
        shift(5,left,tmp1);
        XOR(tmp,tmp1);
        XOR(right,tmp);
        
    }
    
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
    if(size==256 && encryption)
        sonic_256(left,right);
    else if(size==256 && !encryption)
        sonic_256_inv(left,right);
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

// --------- for testing purpuse and for computation of DP and correlation over reduce numbre of round -------

void sonic_256_sub_round(state *left, state* right,int round){

    const table_cst_128 table = {.table ={c_128_f9,c_128_47,c_128_eb,c_128_37,c_128_69,c_128_3b,c_128_49,c_128_3a,c_128_b0,c_128_7d,c_128_5b,c_128_4a,c_128_32,c_128_71,c_128_7b,c_128_4b,c_128_cb,c_128_36}, .size=18};

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
        PI(15,right);

        //apply theta to left branch
        THETA_256(left);
        PI(15,left);
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