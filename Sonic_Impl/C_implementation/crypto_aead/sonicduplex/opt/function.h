#ifndef FUNCTION
#define FUNCTION

#include <immintrin.h>

#include "struct.h"
#include "constante_procrastinate.h"

#define NBR_ROUND512 16

__attribute__((always_inline)) inline uint64_t ror_help(uint64_t x, uint64_t y, int n) { return x >> n | y << (-n & 63); }
__attribute__((always_inline)) inline uint64_t ror_help_inter(uint64_t x, int n) { return x >> n | x << (-n & 63); } 

inline void XOR2(h_state512* s1,const h_state512* s2){

    for(int i=0;i<4;i++)
        s1->data_64[i] ^= s2->data_64[i];
    
}

inline void XOR3(h_state512* s1,const h_state512* s2,const h_state512* s3){

    for(int i=0;i<4;i++)
        s1->data_64[i] ^= s2->data_64[i] ^ s3->data_64[i];

}

inline void AND_XOR(h_state512* s1, const h_state512* s2, const h_state512* s3,const h_state512* s4){
    
    for(int i=0;i<4;i++)
        s1->data_64[i] ^= (s2->data_64[i] & s3->data_64[i]) ^ s4->data_64[i];
}

inline void AND512(h_state512* s1, const h_state512* s2){

    for(int i=0;i<4;i++)
        s1->data_64[i] &= s2->data_64[i];

}
#endif