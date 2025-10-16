
#include <stdlib.h>
#include <stdio.h>
#include "function.h"
#include "constante.h"


//P^-1 = P^63 
    //     = P^32.P^16.P^8.P^4.P^2.P 
    //     = X^64.X^32.(X^80+X^64+1).(X^40+X^32+1).(X^20+X^16+1).(X^10+X^8+1)
    //     = X^96.(X^80+X^64+1).(X^40+X^32+1).(X^20+X^16+1).(X^10+X^8+1)

void THETA256_inv_procrastinate(state* left,int i){

    state* tmp = malloc(sizeof(state));
    tmp->size_64 = left->size_64;
    tmp->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);

    state* tmp1 = malloc(sizeof(state));
    tmp1->size_64 = left->size_64;
    tmp1->data_64 = malloc(sizeof(uint64_t)*tmp1->size_64);

    
    shift(shift_16_128[i],left,tmp);
    shift(shift_40_128[i],left,tmp1);
    XOR(tmp,tmp1);
    XOR(left,tmp);

    shift(shift_80_128[i],left,tmp);
    shift(shift_32_128[i],left,tmp1);
    XOR(tmp,tmp1);
    XOR(left,tmp);

    shift(shift_64_128[i],left,tmp);
    shift(shift_32_128[i],left,tmp1);
    XOR(tmp,tmp1);
    XOR(left,tmp);

    shift(shift_64_128[i],left,tmp);
    copy(tmp,left);

    free(tmp->data_64);
    free(tmp1->data_64);
    free(tmp);
    free(tmp1);

}

void sonic_256_procrastinate(state *left, state* right){

    const table_cst_128 table = {.table ={c_128_f9_procr,c_128_47_procr,c_128_eb_procr,c_128_37_procr,c_128_69_procr,c_128_3b_procr,c_128_49_procr,c_128_3a_procr,c_128_b0_procr,c_128_7d_procr,c_128_5b_procr,c_128_4a_procr,c_128_32_procr,c_128_71_procr,c_128_7b_procr,c_128_4b_procr,c_128_cb_procr,c_128_36_procr}, .size=18};


    state* tmp = malloc(sizeof(state));
    tmp->size_64 = left->size_64;
    tmp->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);

    state* tmp1 = malloc(sizeof(state));
    tmp1->size_64 = left->size_64;
    tmp1->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);

    for(int i=0;i<NBR_ROUND256;i++){

        int idx = 18-i;
        
        //apply F function to the right branch
        shift(shift_1_128[idx],left,tmp);
        AND(tmp,left);
        shift(shift_5_128[idx],left,tmp1);
        XOR(tmp,tmp1);
        XOR(right,tmp);        
        
        //apply theta to left branch
        shift(shift_16_128[idx],left,tmp);
        shift(shift_40_128[idx],left,tmp1);
        XOR(left,tmp);
        XOR(left,tmp1);

        ADD_CST_256(i,table,left);

        swap(left,right);

    }

    //for 24 round no need to recompute since the order is 8
    //PI(shift_1_128[24-NBR_ROUND256],left);
    //PI(shift_1_128[24-NBR_ROUND256],right);
    free(tmp->data_64);
    free(tmp1->data_64);
    free(tmp);
    free(tmp1);

}

void sonic_256_inv_procrastinate(state *left, state* right){

    const table_cst_128 table = {.table ={c_128_f9_procr,c_128_47_procr,c_128_eb_procr,c_128_37_procr,c_128_69_procr,c_128_3b_procr,c_128_49_procr,c_128_3a_procr,c_128_b0_procr,c_128_7d_procr,c_128_5b_procr,c_128_4a_procr,c_128_32_procr,c_128_71_procr,c_128_7b_procr,c_128_4b_procr,c_128_cb_procr,c_128_36_procr}, .size=18};

    state* tmp = malloc(sizeof(state));
    tmp->size_64 = left->size_64;
    tmp->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);

    state* tmp1 = malloc(sizeof(state));
    tmp1->size_64 = left->size_64;
    tmp1->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);   

    for(int i=0;i<NBR_ROUND256;i++){

        swap(left,right);

        int idx = 18-NBR_ROUND256+i+1;

        ADD_CST_256_inv(i,table,left);
        THETA256_inv_procrastinate(left,idx);

        //apply F function to the right branch
        shift(shift_1_128[idx],left,tmp);
        AND(tmp,left); 
        shift(shift_5_128[idx],left,tmp1);
        XOR(tmp,tmp1);
        XOR(right,tmp);
        
    }

    //PI(shift_1_128[NBR_ROUND256],left);
    //PI(shift_1_128[NBR_ROUND256],right);

    free(tmp->data_64);
    free(tmp1->data_64);
    free(tmp);
    free(tmp1);

}



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
    else if(size==256 && !encryption)
        sonic_256_inv_procrastinate(left,right);
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
