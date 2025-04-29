#ifndef FUNCTION
#define FUNCTION

#include "struct.h"

#define NBR_ROUND512 16

static inline void shift512(int shift,h_state512* s,h_state512* res){

    int size = 64;
    shift = 256 - shift;

    int dec = ((shift >> 6) & 3);
    int shift_mod = shift & 63;
    uint64_t mask = (((uint64_t)1<<shift_mod)-1);
    uint64_t tmp = 0;
    int inv_dec = size-shift_mod;

    for(int i=0;i<4;i++){
        
        //res->data_64[i] = 0;
        res->data_64[i] = s->data_64[(4+i-dec) & 3]>>shift_mod | tmp<<(inv_dec);
        tmp = s->data_64[(4+i-dec) & 3] & mask;
    }

    res->data_64[0] |= tmp<<(inv_dec);
}

static inline void XOR3(h_state512* s1,h_state512* s2,h_state512* s3){

    for(int i=0;i<4;i++)
        s1->data_64[i] ^= s2->data_64[i] ^ s3->data_64[i];

}

static inline void AND512(h_state512* s1, h_state512* s2){

    for(int i=0;i<4;i++)
        s1->data_64[i] &= s2->data_64[i];

}

//add the round constant corresponding to the round
static inline void ADD_CST_512_opt(int round,const table_cst_256* table,h_state512* s){
    cst_state_256 cst = table->table[NBR_ROUND512-round-1];
    for(int i=0;i<4;i++)
        s->data_64[i] ^= cst.data_64[i];
}



#endif