/****
 * In this file we defin the round function for Sonic(256,512)
 * it should be able to handle different size of state
 * 
 * 
*/

#include <stdlib.h>
#include <stdio.h>
#include "function.h"
#include "constante_procrastinate.h"

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

    
    shift(shift_32_128[i],left,tmp);
    shift(shift_7_128[i],left,tmp1);
    XOR(tmp,tmp1);
    XOR(left,tmp);

    shift(shift_64_128[i],left,tmp);
    shift(shift_14_128[i],left,tmp1);
    XOR(tmp,tmp1);
    XOR(left,tmp);

    shift(shift_100_128[i],left,tmp);
    copy(tmp,left);

    free(tmp->data_64);
    free(tmp1->data_64);
    free(tmp);
    free(tmp1);

}


//P^-1 = P^127
//     = P^64.P^32.P^16.P^8.P^4.P^2.P 
//     = X^128.X^64.(X^160+X^128+1).(X^80+X^64+1).(X^40+X^32+1).(X^20+X^16+1).(X^10+X^8+1)
//     = X^192.(X^160+X^128+1).(X^80+X^64+1).(X^40+X^32+1).(X^20+X^16+1).(X^10+X^8+1)

void THETA512_inv_procrastinate(state* left,int i){

    state* tmp = malloc(sizeof(state));
    tmp->size_64 = left->size_64;
    tmp->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);

    state* tmp1 = malloc(sizeof(state));
    tmp1->size_64 = left->size_64;
    tmp1->data_64 = malloc(sizeof(uint64_t)*tmp1->size_64);
    
    shift(shift_32_256[i],left,tmp);
    shift(shift_7_256[i],left,tmp1);
    XOR(tmp,tmp1);
    XOR(left,tmp);

    shift(shift_64_256[i],left,tmp);
    shift(shift_14_256[i],left,tmp1);
    XOR(tmp,tmp1);
    XOR(left,tmp);

    shift(shift_128_256[i],left,tmp);
    shift(shift_28_256[i],left,tmp1);
    XOR(tmp,tmp1);
    XOR(left,tmp);

    shift(shift_200_256[i],left,tmp);
    copy(tmp,left);
    
    free(tmp->data_64);
    free(tmp1->data_64);
    free(tmp);
    free(tmp1);

}

void sonic_256_procrastinate(state *left, state* right){

    const table_cst_128 table = {.table ={c_128_f9_procr,c_128_47_procr,c_128_eb_procr,c_128_37_procr,c_128_69_procr,c_128_3b_procr,c_128_49_procr,c_128_3a_procr,c_128_b0_procr,c_128_7d_procr,c_128_5b_procr,c_128_4a_procr,c_128_32_procr,c_128_71_procr,c_128_7b_procr,c_128_4b_procr,c_128_cb_procr,c_128_36_procr,c_128_90_procr,c_128_7c_procr}, .size=20};


    state* tmp = malloc(sizeof(state));
    tmp->size_64 = left->size_64;
    tmp->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);

    state* tmp1 = malloc(sizeof(state));
    tmp1->size_64 = left->size_64;
    tmp1->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);

    for(int i=0;i<NBR_ROUND256;i++){

        int idx = 24-i;
        
        //apply F function to the right branch
        shift(shift_1_128[idx],left,tmp);
        AND(tmp,left);
        shift(shift_5_128[idx],left,tmp1);
        XOR(tmp,tmp1);
        XOR(right,tmp);        
        
        //apply theta to left branch
        shift(shift_7_128[idx],left,tmp);
        shift(shift_32_128[idx],left,tmp1);
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

    const table_cst_128 table = {.table ={c_128_f9_procr,c_128_47_procr,c_128_eb_procr,c_128_37_procr,c_128_69_procr,c_128_3b_procr,c_128_49_procr,c_128_3a_procr,c_128_b0_procr,c_128_7d_procr,c_128_5b_procr,c_128_4a_procr,c_128_32_procr,c_128_71_procr,c_128_7b_procr,c_128_4b_procr,c_128_cb_procr,c_128_36_procr,c_128_90_procr,c_128_7c_procr}, .size=20};

    state* tmp = malloc(sizeof(state));
    tmp->size_64 = left->size_64;
    tmp->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);

    state* tmp1 = malloc(sizeof(state));
    tmp1->size_64 = left->size_64;
    tmp1->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);   

    for(int i=0;i<NBR_ROUND256;i++){

        swap(left,right);

        int idx = 24-NBR_ROUND256+i+1;

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

void sonic_512_procrastinate(state *left, state* right){

    const table_cst_256 table = {.table ={c_256_f9_procr,c_256_47_procr,c_256_eb_procr,c_256_37_procr,c_256_69_procr,c_256_3b_procr,c_256_49_procr,c_256_3a_procr,c_256_b0_procr,c_256_7d_procr,c_256_5b_procr,c_256_4a_procr,c_256_32_procr,c_256_71_procr,c_256_7b_procr,c_256_4b_procr}, .size=16};

    state* tmp = malloc(sizeof(state));
    tmp->size_64 = left->size_64;
    tmp->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);

    state* tmp1 = malloc(sizeof(state));
    tmp1->size_64 = left->size_64;
    tmp1->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);

    for(int i=0;i<NBR_ROUND512;i++){
        
        int idx = 16-i;

        //apply F function to the right branch
        shift(shift_1_256[idx],left,tmp);
        AND(tmp,left);
        shift(shift_5_256[idx],left,tmp1);
        XOR(tmp,tmp1);
        XOR(right,tmp); 
        
        //apply theta to left branch
        shift(shift_7_256[idx],left,tmp);
        shift(shift_32_256[idx],left,tmp1);
        XOR(left,tmp);
        XOR(left,tmp1);      
        ADD_CST_512(i,table,left);

        swap(left,right);

    }

    //for 16 round no need to recompute since the order is 8
    //PI((shift_1_256[16-NBR_ROUND512]),left);
    //PI((shift_1_256[16-NBR_ROUND512]),right);
    free(tmp->data_64);
    free(tmp1->data_64);
    free(tmp);
    free(tmp1);

}

void sonic_512_inv_procrastinate(state *left, state* right){

    const table_cst_256 table = {.table ={c_256_f9_procr,c_256_47_procr,c_256_eb_procr,c_256_37_procr,c_256_69_procr,c_256_3b_procr,c_256_49_procr,c_256_3a_procr,c_256_b0_procr,c_256_7d_procr,c_256_5b_procr,c_256_4a_procr,c_256_32_procr,c_256_71_procr,c_256_7b_procr,c_256_4b_procr}, .size=16};

    state* tmp = malloc(sizeof(state));
    tmp->size_64 = left->size_64;
    tmp->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);

    state* tmp1 = malloc(sizeof(state));
    tmp1->size_64 = left->size_64;
    tmp1->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);   

    for(int i=0;i<NBR_ROUND512;i++){
        
        int idx = 16-NBR_ROUND512+i+1;

        swap(left,right);
        ADD_CST_512_inv(i,table,left);
        THETA512_inv_procrastinate(left,idx);

        //apply F function to the right branch
        shift(shift_1_256[idx],left,tmp);
        AND(tmp,left); 
        shift(shift_5_256[idx],left,tmp1);
        XOR(tmp,tmp1);
        XOR(right,tmp);
        
    }

    // for 16 round no need to resync since the order is 8
    //PI((shift_1_256[NBR_ROUND512]),left);
    //PI((shift_1_256[NBR_ROUND512]),right);
    
    free(tmp->data_64);
    free(tmp1->data_64);
    free(tmp);
    free(tmp1);

}
