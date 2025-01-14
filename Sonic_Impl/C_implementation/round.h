/****
 * In this file we defin the round function for Sonic(256,512)
 * it should be able to handle different size of state
 * 
 * 
*/

#include <stdlib.h>
#include <stdio.h>
#include "function.h"
#include "constante.h"

int reshuffle_128[25] = {1,111,33,79,65,47,97,15,1,111,33,79,65,47,97,15,1,111,33,79,65,47,97,15,1};


void THETA(state* s1){
    state* tmp = malloc(sizeof(state));
    tmp->size_64 = s1->size_64;
    tmp->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);
    
    state* tmp1 = malloc(sizeof(state));
    tmp1->size_64 = s1->size_64;
    tmp1->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);


    shift(7,s1,tmp);
    shift(32,s1,tmp1);
    XOR(s1,tmp);
    XOR(s1,tmp1);

    free(tmp->data_64);
    free(tmp1->data_64);
    free(tmp);
    free(tmp1);
}

//P^-1 = P^63 
    //     = P^32.P^16.P^8.P^4.P^2.P 
    //     = X^64.X^32.(X^80+X^64+1).(X^40+X^32+1).(X^20+X^16+1).(X^10+X^8+1)
    //     = X^96.(X^80+X^64+1).(X^40+X^32+1).(X^20+X^16+1).(X^10+X^8+1)

void THETA256_inv_old(state* left){

    state* tmp = malloc(sizeof(state));
    tmp->size_64 = left->size_64;
    tmp->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);

    state* tmp1 = malloc(sizeof(state));
    tmp1->size_64 = left->size_64;
    tmp1->data_64 = malloc(sizeof(uint64_t)*tmp1->size_64);
    
    shift(32,left,tmp);
    shift(7,left,tmp1);
    XOR(tmp,tmp1);
    XOR(left,tmp);

    shift(64,left,tmp);
    shift(14,left,tmp1);
    XOR(tmp,tmp1);
    XOR(left,tmp);

    shift(100,left,tmp);
    copy(tmp,left);

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
    
    shift(32,left,tmp);
    shift(7,left,tmp1);
    XOR(tmp,tmp1);
    XOR(left,tmp);

    shift(14,left,tmp);
    shift(64,left,tmp1);
    XOR(tmp,tmp1);
    XOR(left,tmp);

    shift(100,left,tmp);
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

void THETA512_inv_old(state* left){

    state* tmp = malloc(sizeof(state));
    tmp->size_64 = left->size_64;
    tmp->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);

    state* tmp1 = malloc(sizeof(state));
    tmp1->size_64 = left->size_64;
    tmp1->data_64 = malloc(sizeof(uint64_t)*tmp1->size_64);
    
    shift(32,left,tmp);
    shift(7,left,tmp1);
    XOR(tmp,tmp1);
    XOR(left,tmp);

    shift(64,left,tmp);
    shift(14,left,tmp1);
    XOR(tmp,tmp1);
    XOR(left,tmp);

    shift(128,left,tmp);
    shift(28,left,tmp1);
    XOR(tmp,tmp1);
    XOR(left,tmp);

    shift(200,left,tmp);
    copy(tmp,left);

    free(tmp->data_64);
    free(tmp1->data_64);
    free(tmp);
    free(tmp1);

}

void THETA512_inv(state* left){

    state* tmp = malloc(sizeof(state));
    tmp->size_64 = left->size_64;
    tmp->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);

    state* tmp1 = malloc(sizeof(state));
    tmp1->size_64 = left->size_64;
    tmp1->data_64 = malloc(sizeof(uint64_t)*tmp1->size_64);
    
    shift(7,left,tmp);
    shift(32,left,tmp1);
    XOR(tmp,tmp1);
    XOR(left,tmp);

    shift(14,left,tmp);
    shift(64,left,tmp1);
    XOR(tmp,tmp1);
    XOR(left,tmp);

    shift(28,left,tmp);
    shift(128,left,tmp1);
    XOR(tmp,tmp1);
    XOR(left,tmp);

    shift(200,left,tmp);
    copy(tmp,left);

    free(tmp->data_64);
    free(tmp1->data_64);
    free(tmp);
    free(tmp1);

}


void sonic_256(state *left, state* right){
    const table_cst_128 table = {.table ={c_128_f9,c_128_47,c_128_eb,c_128_37,c_128_69,c_128_3b,c_128_49,c_128_3a,c_128_b0,c_128_7d,c_128_5b,c_128_4a,c_128_32,c_128_71,c_128_7b,c_128_4b,c_128_cb,c_128_36,c_128_90,c_128_7c,c_128_2a,c_128_d,c_128_d9,c_128_46,c_128_12,c_128_70,c_128_82,c_128_c ,c_128_20,c_128_1}, .size=30};

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

        PI(15,right);

        //apply theta to left branch
        THETA(left);
        ADD_CST_256(i,table,left);
        PI(15,left);

        swap(left,right);

    }

    PI(reshuffle_128[NBR_ROUND256],left);
    PI(reshuffle_128[NBR_ROUND256],right);

    free(tmp->data_64);
    free(tmp1->data_64);
    free(tmp);
    free(tmp1);

}


void sonic_256_inv(state *left, state* right){
    
    const table_cst_128 table = {.table ={c_128_f9,c_128_47,c_128_eb,c_128_37,c_128_69,c_128_3b,c_128_49,c_128_3a,c_128_b0,c_128_7d,c_128_5b,c_128_4a,c_128_32,c_128_71,c_128_7b,c_128_4b,c_128_cb,c_128_36,c_128_90,c_128_7c,c_128_2a,c_128_d,c_128_d9,c_128_46,c_128_12,c_128_70,c_128_82,c_128_c ,c_128_20,c_128_1}, .size=30};

    state* tmp = malloc(sizeof(state));
    tmp->size_64 = left->size_64;
    tmp->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);

    state* tmp1 = malloc(sizeof(state));
    tmp1->size_64 = left->size_64;
    tmp1->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);

    PI(reshuffle_128[24-NBR_ROUND256],left);
    PI(reshuffle_128[24-NBR_ROUND256],right);

    for(int i=0;i<NBR_ROUND256;i++){

        swap(left,right);

        PI(111,left);
        ADD_CST_256_inv(i,table,left);
        THETA256_inv(left);
        
        PI(111,right);

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

void sonic_512(state *left, state* right){

    const table_cst_256 table = {.table ={c_256_f9,c_256_47,c_256_eb,c_256_37,c_256_69,c_256_3b,c_256_49,c_256_3a,c_256_b0,c_256_7d,c_256_5b,c_256_4a,c_256_32,c_256_71,c_256_7b,c_256_4b,c_256_cb,c_256_36,c_256_90,c_256_7c,c_256_2a,c_256_d,c_256_d9,c_256_46,c_256_12,c_256_70,c_256_82,c_256_c,c_256_20,c_256_1}, .size=30};

    state* tmp = malloc(sizeof(state));
    tmp->size_64 = left->size_64;
    tmp->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);

    state* tmp1 = malloc(sizeof(state));
    tmp1->size_64 = left->size_64;
    tmp1->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);

    for(int i=0;i<NBR_ROUND512;i++){
        
        //apply F function to the right branch
        
        shift(1,left,tmp);
        AND(tmp,left);
        shift(5,left,tmp1);
        XOR(tmp,tmp1);
        XOR(right,tmp);
        
        PI(15,right);
        
        //apply theta to left branch
        
        THETA(left);
        ADD_CST_512(i,table,left);
        PI(15,left);
        
        swap(left,right);

    }

    free(tmp->data_64);
    free(tmp1->data_64);
    free(tmp);
    free(tmp1);

}


void sonic_512_inv(state *left, state* right){

    const table_cst_256 table = {.table ={c_256_f9,c_256_47,c_256_eb,c_256_37,c_256_69,c_256_3b,c_256_49,c_256_3a,c_256_b0,c_256_7d,c_256_5b,c_256_4a,c_256_32,c_256_71,c_256_7b,c_256_4b,c_256_cb,c_256_36,c_256_90,c_256_7c,c_256_2a,c_256_d,c_256_d9,c_256_46,c_256_12,c_256_70,c_256_82,c_256_c,c_256_20,c_256_1}, .size=30};

    state* tmp = malloc(sizeof(state));
    tmp->size_64 = left->size_64;
    tmp->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);

    state* tmp1 = malloc(sizeof(state));
    tmp1->size_64 = left->size_64;
    tmp1->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);

    for(int i=0;i<NBR_ROUND512;i++){

        swap(left,right);

        PI(239,left);
        ADD_CST_512_inv(i,table,left);
        THETA512_inv(left);
        
        PI(239,right);

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


//function for testind differential propbabilities for less rounds

void sonic_256_sub_round(state *left, state* right,int round){

    const table_cst_128 table = {.table ={c_128_f9,c_128_47,c_128_eb,c_128_37,c_128_69,c_128_3b,c_128_49,c_128_3a,c_128_b0,c_128_7d,c_128_5b,c_128_4a,c_128_32,c_128_71,c_128_7b,c_128_4b,c_128_cb,c_128_36,c_128_90,c_128_7c,c_128_2a,c_128_d,c_128_d9,c_128_46,c_128_12,c_128_70,c_128_82,c_128_c ,c_128_20,c_128_1}, .size=30};

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
        THETA(left);
        PI(15,left);
        ADD_CST_256(i,table,left);

        swap(left,right);
    }

    free(tmp->data_64);
    free(tmp1->data_64);
    free(tmp);
    free(tmp1);

}


void sonic_512_sub_round(state *left, state* right,int round){

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
        
        THETA(left);
        PI(15,left);

        swap(left,right);

    }

    free(tmp->data_64);
    free(tmp1->data_64);
    free(tmp);
    free(tmp1);

}