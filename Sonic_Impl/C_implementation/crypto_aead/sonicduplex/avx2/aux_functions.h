#include <stdint.h>
#include <stdio.h>

#define PRINT 0
#define MASK_FULL 0xffffffffffffffff

void add(uint64_t* a, uint64_t* b,int size_64, uint64_t* output){
    for(int i=0;i<size_64;i++)
        output[i] = a[i] ^ b[i];
}

void set_absorb(uint64_t cur_absorb[4],const unsigned char* input, int index){
    for(int i=0;i<4;i++){
        cur_absorb[i] = 0;
        for(int j=0;j<8;j++){
            cur_absorb[i] ^= (uint64_t)input[index + j+(i<<3)]<<((8-j-1)<<3);
        }
    }
}

void add_to_state(uint64_t state[8],uint64_t b[4],int start, int lenght){
    for(int i=start;i<start+lenght;i++)
        state[i] = state[i] ^ b[i-start];
}

void add_to_state_full(uint64_t state[8], const unsigned char* input,int index_start){
    for(int i=0;i<4;i++){
        for(int j=0;j<8;j++){
            state[i] ^= (uint64_t)input[index_start + j+(i<<3)]<<((8-j-1)<<3);
        }
    }
}

void add_key_to_state(uint64_t state[8],const uint64_t k[4],int start){
    for(int i=start;i<start+4;i++)
        state[i] = state[i] ^ k[i-start];
}

void add_byte(uint64_t* a,uint64_t* b, int size_byte,uint64_t* output){
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

    //printf("\n %d , %d \n",rest_byte,word_64);

    for(int i=0;i<word_64;i++){
        output[i] = a[i];
    }

    if(rest_byte!=0){
        //uint64_t mask = (uint64_t)MASK_FULL ^ (((uint64_t)1<<(64-rest_byte))-1);
        uint64_t mask2 = (((uint64_t)1<<(64-rest_byte))-1);
        output[word_64] = (a[word_64]) ^ (output[word_64] & mask2); 
    }
}


//read the size bloc left most bytes in state and store them in ciphertext[index_ciohertext_bloc]
void extract_ciphertext(uint64_t* state,uint8_t* ciphertext,int index_ciphertext_bloc,int size_bloc){
    for(int i=0;i<size_bloc;i++){
        ciphertext[index_ciphertext_bloc+i] = (uint8_t)(state[i>>3]>>(((7-(i & 7))<<3)));
    }
}

uint64_t set_word(const unsigned char* k,int word){
    uint64_t w = 0;
        for(int j=0;j<8;j++){
            w ^= (uint64_t)k[j+(word<<3)]<<((8-j-1)<<3);
        }
    return w;
}

uint64_t set_word1(const unsigned char* k,int word){
    uint64_t w = 0;
    //printf("\n in set word : ");
        for(int j=0;j<8;j++){
            //printf("%x ",k[j+(word)]);
            w ^= ((uint64_t)k[j+(word)])<<((7-j)<<3);
        }
    return w;
}

void replace(const unsigned char* a, int start, int size_byte,uint64_t* output){
    int rest_byte = (size_byte & 7)<<3;
    int word_64 = size_byte>>3;

    //printf("\n %d , %d \n",rest_byte,word_64);

    for(int i=0;i<word_64;i++){
        output[i] = set_word1(a,(i*8)+start);
    }

    if(rest_byte!=0){
        uint64_t mask = (uint64_t)MASK_FULL ^ (((uint64_t)1<<(64-rest_byte))-1);
        uint64_t mask2 = (((uint64_t)1<<(64-rest_byte))-1);
        output[word_64] = (output[word_64] & mask2);
        for(int i=0;i<rest_byte;i++){
            output[word_64] ^= (a[i+start+(word_64*8)])<<(8*i);
        }
        //output[word_64] = (a[word_64] &  mask) ^ (output[word_64] & mask2); 
    }
}
