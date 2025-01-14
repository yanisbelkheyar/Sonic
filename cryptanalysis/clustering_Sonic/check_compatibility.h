#include <stdint.h>

typedef struct state{
      /* data */
    uint64_t* data_64;
    uint8_t size_64;
    uint8_t weight;
} state;

void print_bin(state* s);

void copy(const state* s, state* res);

void shift(int shift,state* s,state* res);

//perform the XOR of s1 and s2 and store the result in s1
void XOR(state* s1,state* s2);

//return the hamming weight of state of size
int hw(uint64_t d,int size);

//generate for an input difference b, a basis of the affine space of compatible output differences
int generate_basis(state* b,state** basis,state* offset,int shift1,int shift2,int shift3);

//return the vectore i where i is the binary representation of the linear combinazon of basis vector + offset
state* vectore_from_basis(state** basis,int size_basis,state* offset,int index,state* res);

//searche for an output difference a and an input difference b 
//if a belong to the affine space off possible output difference generate by b
int in(state* a,state* b,int shift1,int shift2,int shift3);

int in_v2(state* a,state* b,int shift1,int shift2,int shift3);