#include <stdint.h>
#include <stdio.h>

#define MASK_FULL 0xffffffffffffffff

#include "struct.h"

void add_to_state_half(h_state512* half, const unsigned char* m){

    half->data_64[0] ^= (uint64_t)m[0]<<(56) ^ (uint64_t)m[1]<<(48) ^ (uint64_t)m[2]<<(40) ^ (uint64_t)m[3]<<(32) ^ (uint64_t)m[4]<<(24) ^ (uint64_t)m[5]<<(16) ^ (uint64_t)m[6]<<(8) ^ (uint64_t)m[7];     
    half->data_64[1] ^= (uint64_t)m[8]<<(56) ^ (uint64_t)m[9]<<(48) ^ (uint64_t)m[10]<<(40) ^ (uint64_t)m[11]<<(32) ^ (uint64_t)m[12]<<(24) ^ (uint64_t)m[13]<<(16) ^ (uint64_t)m[14]<<(8) ^ (uint64_t)m[15];     
    half->data_64[2] ^= (uint64_t)m[16]<<(56) ^ (uint64_t)m[17]<<(48) ^ (uint64_t)m[18]<<(40) ^ (uint64_t)m[19]<<(32) ^ (uint64_t)m[20]<<(24) ^ (uint64_t)m[21]<<(16) ^ (uint64_t)m[22]<<(8) ^ (uint64_t)m[23];     
    half->data_64[3] ^= (uint64_t)m[24]<<(56) ^ (uint64_t)m[25]<<(48) ^ (uint64_t)m[26]<<(40) ^ (uint64_t)m[27]<<(32) ^ (uint64_t)m[28]<<(24) ^ (uint64_t)m[29]<<(16) ^ (uint64_t)m[30]<<(8) ^ (uint64_t)m[31];     

}

void add_byte(uint64_t* a,const uint64_t* b, const int size_byte,uint64_t* output){
    int rest_byte = (size_byte & 7)<<3;
    int word_64 = size_byte>>3;
    for(int i=0;i<word_64;i++){
        output[i] = a[i] ^ b[i];
    }

    if(rest_byte!=0){
        uint64_t mask = (uint64_t)MASK_FULL ^ (((uint64_t)1<<(64-rest_byte))-1);
        uint64_t mask2 = (((uint64_t)1<<(64-rest_byte))-1);

        output[word_64] = (a[word_64] &  mask) ^ (b[word_64] & mask) ^ (output[word_64] & mask2); 
    }
}

void replace(uint64_t* a, int size_byte,uint64_t* output){
    int rest_byte = (size_byte & 7)<<3;
    int word_64 = size_byte>>3;

    for(int i=0;i<word_64;i++){
        output[i] = a[i];
    }

    if(rest_byte!=0){
        uint64_t mask = (uint64_t)MASK_FULL ^ (((uint64_t)1<<(64-rest_byte))-1);
        uint64_t mask2 = (((uint64_t)1<<(64-rest_byte))-1);
        output[word_64] = (a[word_64] &  mask) ^ (output[word_64] & mask2); 
    }
}

void extract_ciphertext_partial(const h_state512* left, unsigned char* c,const int size){
    for(int i=0;i<size;i++){
        c[i] = (uint8_t)(left->data_64[i>>3]>>(((7-(i & 7))<<3)));
    }
}

void extract_ciphertext_full(const h_state512* left, unsigned char* c){
    for(int i=0;i<32;i++){
        c[i] = (uint8_t)(left->data_64[i>>3]>>(((7-(i & 7))<<3)));
    }
}

void extract_tag(const h_state512* right, unsigned char* c){
    for(int i=0;i<16;i++){
        c[i] = (uint8_t)((right->data_64[2+(i>>3)])>>(((7-(i & 7))<<3)));
    }
}

uint64_t set_word(const unsigned char* m, const int start){
    uint64_t w = 0;
    for(int j=0;j<8;j++){
        w ^= ((uint64_t)m[j+start])<<((8-j-1)<<3);
    }
    return w;
}


uint64_t set_word1(const unsigned char* k,int word){
    uint64_t w = 0;
        for(int j=0;j<8;j++){
            w ^= ((uint64_t)k[j+(word)])<<((7-j)<<3);
        }
    return w;
}

void replace_full(const unsigned char* a, int start, int size_byte,h_state512* output){
    int rest_byte = (size_byte & 7)<<3;
    int word_64 = size_byte>>3;

    for(int i=0;i<word_64;i++){
        output->data_64[i] = set_word1(a,(i*8)+start);
    }

    if(rest_byte!=0){
        uint64_t mask = (uint64_t)MASK_FULL ^ (((uint64_t)1<<(64-rest_byte))-1);
        uint64_t mask2 = (((uint64_t)1<<(64-rest_byte))-1);
        output->data_64[word_64] = (output->data_64[word_64] & mask2);
        for(int i=0;i<rest_byte;i++){
            output->data_64[word_64] ^= (a[i+start+(word_64*8)])<<(8*i);
        }
    }
}