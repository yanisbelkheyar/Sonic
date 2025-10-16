    #include <stdio.h>
    #include <stdint.h>
    #include <time.h>
    #include <stdlib.h>

typedef struct state{
      /* data */
    uint64_t* data_64;
    uint8_t size_64;
} state;

void print_hex(uint64_t val){

    uint64_t res = 0;
    for(int i=0;i<64;i++){
        res += (val>>i & 1)<<(64-i-1);
    }
    printf("%lx ",res);

    }


void copy(const state* s, state* res){

    for(int i=0;i<s->size_64;i++)
        res->data_64[i] = s->data_64[i];

}

void shift(int shift,const state* s,state* res){

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

void XOR(state* s1,const state* s2){

    for(int i=0;i<s1->size_64;i++)
        s1->data_64[i] ^= s2->data_64[i];

}

void AND(state* s1,const state* s2){

    for(int i=0;i<s1->size_64;i++)
        s1->data_64[i] &= s2->data_64[i];

}

void PI(int mul_shuffle,state* s){

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

void swap(state* left, state* right){

    uint64_t tmp = 0;
    for(int i=0;i<left->size_64;i++){
        tmp = left->data_64[i];
        left->data_64[i] = right->data_64[i];
        right->data_64[i] = tmp;
    }

}

void PI_full(int mul_shuffle,uint64_t* s){

        uint64_t* res = malloc(sizeof(uint64_t)*4);

        //left part

        for(int i=0;i<4;i++)
            res[i] = 0;

        int size = 2*64;
        
        for(int i=0;i<2;i++){
            res[i] = (uint64_t)0;
            for(int j=0;j<64;j++){
                int idx = (((i*64+j)*mul_shuffle)%size);
                res[i] ^= (uint64_t)(((s[idx/64]>>((size-idx-1)%64)) & (uint64_t)1)<<((size-j-1)%64));
            }
        }

        for(int i=0;i<2;i++)
            s[i] = res[i];

        //right part

        for(int i=2;i<4;i++){
            res[i] = (uint64_t)0;
            for(int j=0;j<64;j++){
                int idx = (((i*64+j)*mul_shuffle)%size) + size;
                res[i] ^= (uint64_t)(((s[idx/64]>>((size-idx-1)%64)) & (uint64_t)1)<<((size-j-1)%64));
            }
        }

        for(int i=2;i<4;i++)
            s[i] = res[i];

        free(res);
}

void Simon_encrypt_3_round(uint64_t* plaintext,uint64_t* ciphertext, int nbr_round){
   
    int size_half = 2;
    
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

    state* tmp = malloc(sizeof(state));
    tmp->size_64 = left->size_64;
    tmp->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);

    state* tmp1 = malloc(sizeof(state));
    tmp1->size_64 = left->size_64;
    tmp1->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);

    int max_round = nbr_round;
    for(int round=0;round<max_round;round++){

        shift(128-1,left,tmp);
        shift(128-8,left,tmp1);
        AND(tmp,tmp1);
        shift(128-2,left,tmp1);

        XOR(tmp,tmp1);

        XOR(right,tmp);
        if(round<max_round)
            swap(left,right);
    }

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

int main(int argc, char *argv[]){

    //int reshufle = 1;

    srand(time(NULL));   // Initialization, should only be called once.

    // test for size 256
    int size = 4;
    
    //read input difference

    //read output difference
    uint64_t* plaintext = malloc(sizeof(uint64_t)*size);
    uint64_t* plaintext_dif = malloc(sizeof(uint64_t)*size);

    uint64_t* ciphertext = malloc(sizeof(uint64_t)*size);
    uint64_t* ciphertext_dif = malloc(sizeof(uint64_t)*size);

    uint64_t* input_difference = malloc(sizeof(uint64_t)*size);
    uint64_t* output_difference = malloc(sizeof(uint64_t)*size);

    //2-bit input difference
    input_difference[0] = (uint64_t)0x0;
    input_difference[1] = (uint64_t)0x804000000000000;
    input_difference[2] = (uint64_t)0x0; //9223372036854775808;
    input_difference[3] = (uint64_t)0x0;

    output_difference[2] = (uint64_t)0x0;  // 9223512774343163904;
    output_difference[3] = (uint64_t)0x884400000000000; //9241421621904801792;
    output_difference[0] = (uint64_t)0x0; //2323901388189345792;
    output_difference[1] = (uint64_t)0x68344000000000;

    //1-bit input difference
    //input_difference[0] = (uint64_t)0x400000000000000;
    //input_difference[1] = (uint64_t)0x0;
    //input_difference[2] = (uint64_t)0x0; //9223372036854775808;
    //input_difference[3] = (uint64_t)0x0;

    //output_difference[2] = (uint64_t)0x440000000000000;  // 9223512774343163904;
    //output_difference[3] = (uint64_t)0x0; //9241421621904801792;
    //output_difference[0] = (uint64_t)0x214400000000000; //2323901388189345792;
    //output_difference[1] = (uint64_t)0x0;
	
    int nbr_round_dif = 3;

    for(int n=0;n<4;n++){
        for(int i=0;i<64;i++)
            (input_difference[n]>>(64-i-1)&1)==1?printf("1"):printf("-");
        if(n==1)
            printf(" ");
    }
    printf("\n");
    //PI_full(reshufle,output_difference);
    for(int n=0;n<4;n++){
        for(int i=0;i<64;i++)
            (output_difference[n]>>(64-i-1)&1)==1?printf("1"):printf("-");
        if(n==1)
            printf(" ");
        printf(" ");
    }
    printf("\n");

    int nbr_test = 90000000; //-log2DP
    printf("Test for Simon :\n");
    long double nbr_try = 1;
    long double sum = 0.0;
    for(int j=0;j<nbr_try;j++){

        int proba = 0;

        for(int test=0;test<nbr_test;test++){
        
            for(int i=0;i<size;i++){
                plaintext[i] = rand() ^ (uint64_t)rand()<<32 ;
                plaintext_dif[i] = plaintext[i] ^ input_difference[i] ;
                ciphertext[i] = 0;
                ciphertext_dif[i] = 0;
            }
                Simon_encrypt_3_round(plaintext,ciphertext,nbr_round_dif);
                Simon_encrypt_3_round(plaintext_dif,ciphertext_dif,nbr_round_dif);
                //PI_full(reshufle,ciphertext);
                //PI_full(reshufle,ciphertext_dif);
                
                for(int i=0;i<size;i++){
                    if(output_difference[i]==(ciphertext[i] ^ ciphertext_dif[i]) && i==size-1){
                        proba++;
                        //printf("+1");
                    }
                    else if(output_difference[i]!=((ciphertext[i] ^ ciphertext_dif[i])))
                        break;
                }
            }
            long double p = (long double)proba/(long double)nbr_test;
            printf("\n nbr = %d, nbr_test %d ",proba,nbr_test);
            printf("proba = %Lf \n",p);
            sum += p;
        }
    
        printf("\n\nproba = %Lf \n",sum/nbr_try);

        free(plaintext_dif);
        free(ciphertext_dif);
        free(plaintext);
        free(ciphertext);
        free(input_difference);
        free(output_difference);
        return 0;
    }
                         