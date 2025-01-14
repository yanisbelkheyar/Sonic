#include <stdlib.h>
#include <stdio.h>
#include "check_compatibility.h"

#define one(x,i) ((x>>i)&1)

//print the binary representation of state of size
void print_bin(state* s){
  for(int i=0;i<s->size_64;i++){
    for(int j=0;j<64;j++){
        if(one(s->data_64[i],j)==1)
            printf("1");
        else
            printf("-");
        }
  }
}

void copy(const state* s, state* res){

    for(int i=0;i<s->size_64;i++)
        res->data_64[i] = s->data_64[i];

}

void XOR(state* s1,state* s2){

    for(int i=0;i<s1->size_64;i++)
        s1->data_64[i%(s1->size_64)] ^= s2->data_64[i%(s1->size_64)];

}

void OR(state* s1,state* s2){

    for(int i=0;i<s1->size_64;i++)
        s1->data_64[i%(s1->size_64)] |= s2->data_64[i%(s1->size_64)];
}

void NOT(state* s1){

     for(int i=0;i<s1->size_64;i++)
        s1->data_64[i%(s1->size_64)] = ~s1->data_64[i%(s1->size_64)];

}

void AND(state* s1, state* s2){

    for(int i=0;i<s1->size_64;i++)
        s1->data_64[i] &= s2->data_64[i];

}

void shift(int shift,state* s,state* res){

    int dec = (shift / 64) % s->size_64;
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

//return the element at postion i in the state 
uint8_t get(state* s,int i){
    return (s->data_64[((i%(s->size_64*64))/64) % (s->size_64)] >> (i%64)) & (uint64_t)1;
}

//set the element at postition i in the state to the value 1
void set(state *s,int i){
    s->data_64[((i%(s->size_64*64))/64)%(s->size_64)] ^= (uint64_t)1<<(i%64);
}

//compute the weight of an input difference
int compute_weight(state* b,int shift1,int shift2,int shift3){
    int weight = 0;
    for(int i=0;i<(b->size_64*64);i++){
        uint8_t bi = get(b,i+shift1);
        uint8_t bi1 = get(b,i+shift2);
        uint8_t bi2 = get(b,i+shift3);
        if(bi==0 && bi1==0 && bi2==1)
            weight++;
        if(bi==1)   
            weight++;
    }
    return weight;
}

//return the hamming weight of state of size
int hw(uint64_t d,int size){
  int weight = 0;
  for(int i=0;i<size;i++)
    if(one(d,i))
      weight++;
  return weight;
}


//generate for a specific input difference the offset of the affine space containing all compatible output difference.
state* generate_offset(state* b,state* offset,int shift1,int shift2,int shift3){
    for(int i=0;i<b->size_64;i++)
        offset->data_64[i] = 0;
    for(int i=0;i<(b->size_64*64);i++){
        uint8_t bi = get(b,i+shift1);
        uint8_t bi1 = get(b,i+shift2);
        uint8_t bi2 = get(b,i+shift3);
        if(bi==1 && bi1==0 && bi2==0)
            set(offset,i);
        //else if(bi==1 && bi1==1 && bi2==0 && get(b,i+3)==1)
        //    set(offset,i);
    }

    return offset;
}

//generate for an input difference and an index the corresponding vector basis 
state* generate_vector(state* b,state* vect, int i,int shift1,int shift2,int shift3){
    for(int j=0;j<b->size_64;j++)
        vect->data_64[j] = 0;

    uint8_t bi1 = get(b,i+shift1);
    uint8_t bi2 = get(b,i+shift2);
    uint8_t bi3 = get(b,i+shift3);
    
    //printf("\nbit number %d : %d %d %d \n",i,bi1,bi2,bi3);

    int size = vect->size_64*64;

    //if(bi1==1 && bi2==0 && bi3==1){
    //    set(vect,i-1);
    //    set(vect,i);
    //    vect->weight = 2;
    //    printf("case 0\n");
    //    return vect;
    //}
    if((bi2==1 && bi3==0) || (bi2==1 && bi3==1) || (bi2==0 && bi3==1)){
        set(vect,i);
        vect->weight = 1;
        //printf("case 1\n");
        return vect;
    }
    //else if((bi1==0 && bi2==0 && bi3==1) ){
    //    set(vect,i);
    //    vect->weight = 1;
    //    printf("case 2\n");
    //    return vect;
    //}
    else{
        vect->weight = 0;
        return vect;
    }
}

//generate for an input difference b, a basis of the affine space of compatible output differences
int generate_basis(state* b,state** basis,state* offset,int shift1,int shift2,int shift3){

    offset = generate_offset(b,offset,shift1,shift2,shift3);
    /*
    printf("offset :\n");
    print_bin(offset);
    printf("\n");
    */
    int size_basis = 0;

    state* v = malloc(sizeof(state));
    v->data_64 = malloc(sizeof(uint64_t)*b->size_64);
    v->size_64 = b->size_64;
    v->weight = 0;
    XOR(v,v);

    for(int i=0;i<b->size_64*64;i++){

        v = generate_vector(b,v,i,shift1,shift2,shift3);

        if(v->weight != 0){
            basis[size_basis] = malloc(sizeof(state));
            basis[size_basis]->data_64 = malloc(sizeof(uint64_t)*b->size_64);
            basis[size_basis]->size_64 = b->size_64;

            for(int j=0;j<v->size_64;j++)
                basis[size_basis]->data_64[j] = v->data_64[j];
            basis[size_basis]->weight = v->weight;
            //print_bin(basis[size_basis]);
            //printf("\n");
            size_basis++;
        }
        XOR(v,v);
    }

    free(v->data_64);
    free(v);

    return size_basis;
}

//return the vectore i where i is the binary representation of the linear combinazon of basis vector + offset
state* vectore_from_basis(state** basis,int size_basis,state* offset,int index,state* res){

    res->data_64[0] = 0;
    res->data_64[1] = 0;
    XOR(res,offset);

    //printf("offset:\n");
    //print_bin(offset);
    //printf("\n basis vectors added:\n");
    for(int i=0;i<size_basis;i++){
        if((index & (uint64_t)1<<i)!=0){
            //printf("add vector nbr %d :\n",i);
            //print_bin(basis[i]);
            //printf("\n");
            XOR(res,basis[i]);
        }
    }
    return res;

}

//TODO check the conner cases when the ones appear at strange position like the first few positionn where it could affect the last position
//searche for an output difference a and an input difference b if a belong to the affine space off possible output difference generate by b
int in(state* a,state* b,int shift1,int shift2,int shift3){

    state* offset = malloc(sizeof(state));
    offset->data_64 = malloc(sizeof(uint64_t)*a->size_64);
    offset->size_64 = a->size_64;
    offset->weight = 0;

    state* v = malloc(sizeof(state));
    v->data_64 = malloc(sizeof(uint64_t)*a->size_64);
    v->size_64 = a->size_64;
    v->weight = 0;

    offset = generate_offset(b,offset,shift1,shift2,shift3);

    //bitwise xor of the offset and the fixed ouput difference
    XOR(offset,a);

    for(int i=0;i<(a->size_64*64);i++){
        if(get(offset,i)==1){

            XOR(v,v);
            v = generate_vector(b,v,i,shift1,shift2,shift3);

            if(v->weight==0){
                /*
                printf("case 0 for bit %d in \n",i);
                print_bin(b);
                printf("\n");
                print_bin(offset);
                printf("\n");
                print_bin(v);
                */
                free(offset->data_64);
                free(offset);
                free(v->data_64);
                free(v);
                return 0;
            }else if(v->weight==1)
                XOR(offset,v);
            else{
                if(get(offset,i+(a->size_64*64)-1)==0){
                    /*
                    printf("case 1 for bit %d in \n",i);
                    print_bin(b);
                    printf("\n");
                    print_bin(offset);
                    printf("\n");
                    print_bin(v);
                    */
                    free(offset->data_64);
                    free(offset);
                    free(v->data_64);
                    free(v);
                    return 0;
                }else
                    XOR(offset,v);

            }
        }

    }

    free(offset->data_64);
    free(offset);
    free(v->data_64);
    free(v);
    return 1;
}


int in_2(state* a,state* b,int shift1,int shift2,int shift3){

    state* offset = malloc(sizeof(state));
    offset->data_64 = malloc(sizeof(uint64_t)*a->size_64);
    offset->size_64 = a->size_64;
    offset->weight = 0;

    state* v = malloc(sizeof(state));
    v->data_64 = malloc(sizeof(uint64_t)*a->size_64);
    v->size_64 = a->size_64;
    v->weight = 0;

    offset = generate_offset(b,offset,shift1,shift2,shift3);

    shift(255,b,v);
    OR(v,b);
    NOT(v);
    XOR(a,offset);

    AND(a,v);
    
    for(int i=0;i<a->size_64;i++){
        if(a->data_64[i]!=0){
            free(offset->data_64);
            free(offset);
            free(v->data_64);
            free(v);
            return 0;
        }
    }

    free(offset->data_64);
    free(offset);
    free(v->data_64);
    free(v);
    return in(a,b,shift1,shift2,shift3);
}

//generate for an input difference a random output difference with non-zero probability
state* random_differential(state* b,state* res,int shift1,int shift2,int shift3){

    state* alpha = malloc(sizeof(state));
    alpha->data_64 = malloc(sizeof(uint64_t)*b->size_64);
    alpha->size_64 = b->size_64;

    for(int i=0;i<b->size_64;i++)
        alpha->data_64[i] = rand() % 1000;

    state* tmp = malloc(sizeof(state));
    tmp->size_64 = b->size_64;
    tmp->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);
    XOR(tmp,tmp);

    state* tmp1 = malloc(sizeof(state));
    tmp1->size_64 = b->size_64;
    tmp1->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);
    XOR(tmp1,tmp1);

    state* tmp2 = malloc(sizeof(state));
    tmp2->size_64 = b->size_64;
    tmp2->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);
    XOR(tmp2,tmp2);

    state* tmp3 = malloc(sizeof(state));
    tmp3->size_64 = b->size_64;
    tmp3->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);
    XOR(tmp3,tmp3);

    shift(shift1,b,tmp);
    shift(shift2,b,tmp1);
    shift(shift3,b,tmp2);
    AND(tmp,tmp1);
    XOR(tmp,tmp2);

    XOR(alpha,b);
    
    shift(shift1,alpha,tmp1);
    shift(shift2,alpha,tmp2);
    shift(shift3,alpha,tmp3);

    AND(tmp1,tmp2);
    XOR(tmp1,tmp3);

    XOR(tmp,tmp1);

    copy(tmp,res);

    free(alpha->data_64);
    free(tmp->data_64);
    free(tmp1->data_64);
    free(tmp2->data_64);
    free(tmp3->data_64);
    free(tmp);
    free(tmp1);
    free(tmp2);
    free(tmp3);
    free(alpha);

    return res;

}

/*
int main(){

    int size = 2;

    state* a = malloc(sizeof(state));
    state* b = malloc(sizeof(state));

    a->data_64 = malloc(sizeof(uint64_t)*size);
    a->size_64 = size;
    a->weight = 0;

    b->data_64 = malloc(sizeof(uint64_t)*a->size_64);
    b->size_64 = a->size_64;
    b->weight = 0;

    printf("Test for Soni256 :\n");

    int nbr_test = 1;

    for(int test=0;test<nbr_test;test++){
         
        b->data_64[0] = (uint64_t)1<<2 ^ (uint64_t)1<<5 ^ (uint64_t)1<<6 ^ (uint64_t)1<<8 ^ (uint64_t)1<<9 ^ (uint64_t)1<<11;
        b->data_64[1] = 0;
        a->data_64[0] = (uint64_t)1<<2 ^ (uint64_t)1<<5 ^ (uint64_t)1<<8 ^ (uint64_t)1<<11 ^ (uint64_t)1<<8 ^ (uint64_t)1<<9 ^ (uint64_t)1<<1 ^ (uint64_t)1<<4;
        a->data_64[1] = 0;
        printf("%d",in(a,b));   

      printf("\n");
    }

}
*/
