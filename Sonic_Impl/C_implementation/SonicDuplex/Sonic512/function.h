#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

#ifndef FUNCTION_512
#define FUNCTION_512

#define NBR_ROUND512 12

void copy(const state* s, state* res){

    for(int i=0;i<s->size_64;i++)
        res->data_64[i] = s->data_64[i];

}

void shift512(int shift,h_state512* s,h_state512* res){

    shift = res->size_64*64 - shift;

    int dec = ((shift / 64) % s->size_64);
    int shift_mod = shift %64;
    uint64_t mask = (((uint64_t)1<<shift_mod)-1);
    uint64_t tmp = 0;

    for(int i=0;i<s->size_64;i++){
        
        res->data_64[i] = 0;
        res->data_64[i] = s->data_64[(s->size_64+i-dec)%s->size_64]>>shift_mod | (uint64_t)tmp<<(64-shift_mod);
        tmp = s->data_64[(s->size_64+i-dec)%s->size_64] & mask;
    }

    res->data_64[0] |= (uint64_t)tmp<<(64-shift_mod);
}

void XOR3(h_state512* s1,h_state512* s2,h_state512* s3){

    for(int i=0;i<s1->size_64;i++)
        s1->data_64[i] ^= s2->data_64[i] ^ s3->data_64[i];

}

void AND512(h_state512* s1, h_state512* s2){

    for(int i=0;i<s1->size_64;i++)
        s1->data_64[i] &= s2->data_64[i];

}

void PI(int mul_shuffle,h_state512* s){

    state* res = malloc(sizeof(state));
    res->data_64 = malloc(sizeof(uint64_t)*s->size_64);
    res->size_64 = s->size_64;

    for(int i=0;i<s->size_64;i++)
        res->data_64[i] = 0;

    int size = s->size_64*64;
    
    for(int i=0;i<s->size_64;i++){
        res->data_64[i] = (uint64_t)0;
        for(int j=0;j<64;j++){
            int idx = (((i*64+j)*mul_shuffle)%size);
            res->data_64[i] ^= (uint64_t)(((s->data_64[idx/64]>>((size-idx-1)%64)) & (uint64_t)1)<<((size-j-1)%64));
        }
    }

    for(int i=0;i<s->size_64;i++)
        s->data_64[i] = res->data_64[i];

    free(res->data_64);
    free(res);
}

//add the round constant corresponding to the round
void ADD_CST_512(int round,const table_cst_256 table,h_state512* s){
    for(int i=0;i<s->size_64;i++)
        s->data_64[i] ^= table.table[NBR_ROUND512-round-1].data_64[i];
}

void swap512(h_state512* left, h_state512* right){

    uint64_t tmp = 0;
    for(int i=0;i<left->size_64;i++){
        tmp = left->data_64[i];
        left->data_64[i] = right->data_64[i];
        right->data_64[i] = tmp;
    }

}

#endif