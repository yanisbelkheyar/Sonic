#include "Sonic256/permutation.h"
#include "Sonic256/permutation_procrastinate.h"

#define PRINT 0

void add( uint64_t* a, uint64_t* b,int size_64, uint64_t* output){
    for(int i=0;i<size_64;i++)
        output[i] = a[i] ^ b[i];
}

void copy_elt(uint64_t* input,int size_64,uint64_t* copy){
    for(int i=0;i<size_64;i++)
        copy[i] = input[i];
}

void encode_prefix_free( uint8_t* diversifier,int size_diversifier,int full_bloc,int size_64,uint64_t** input_bloc){
    
    int word_index = 0;
    //printf("%d nbr full bloc \n",full_bloc);
    for(int i=0;i<full_bloc;i++){
        for(int j=0;j<28;j++){
            //printf("%x ,%d ",diversifier[word_index],((8-j-1)*8%64));
            input_bloc[i][j/8] ^=(uint64_t) diversifier[word_index] << ((8-j-1)*8%64);
            //printf("%lx \n",input_bloc[i][j/8]);
            word_index++;
        }
    }

    //for the last bloc
    input_bloc[full_bloc] = malloc(sizeof(uint64_t)*size_64);
    for(int j=0;j<size_diversifier%28;j++){
        input_bloc[full_bloc][j/8] ^=(uint64_t) diversifier[word_index] << ((8-j-1)*8%64);
        word_index++;
    }
    input_bloc[full_bloc][((size_diversifier*8+(32*full_bloc))/64)%4] ^= (uint64_t) 1<< (63-((size_diversifier*8+(32*full_bloc))%64));
    input_bloc[full_bloc][3] ^=(uint64_t) 1;

}

//SoniK
void sonik( uint8_t* diversifier, int size_diversifier, uint64_t* key,uint64_t* output){
    
    int size_64 = 4;
    uint64_t* state = malloc(sizeof(uint64_t)*size_64);
    uint64_t* state_tmp = malloc(sizeof(uint64_t)*size_64);
    state[0] = key[0];
    state[1] = key[1];
    state[2] = key[2];
    state[3] = key[3];

    state_tmp[0] = 0;
    state_tmp[1] = 0;
    state_tmp[2] = 0;
    state_tmp[3] = 0;


    //initialization round
    Sonic_Encrypt_256(state,state_tmp);

    add(key,state_tmp,size_64,state);

    //absorbtion of diversifier

    int full_bloc = size_diversifier/28;

    uint64_t** input_bloc = malloc(sizeof(uint64_t*)*(full_bloc+1));
    for(int i=0;i<full_bloc+1;i++){
        input_bloc[i] = malloc(sizeof(uint64_t)*size_64);
        input_bloc[i][0] = 0;
        input_bloc[i][1] = 0;
        input_bloc[i][2] = 0;
        input_bloc[i][3] = 0;
    }        

    encode_prefix_free(diversifier,size_diversifier,full_bloc,size_64,input_bloc);
    

    printf("paded diversifier: \n");
    for(int i=0;i<full_bloc+1;i++){
        //add input bloc
        for(int j=0;j<size_64;j++)
            printf("%lx ",input_bloc[i][j]);
        printf("\n");
        add(input_bloc[i],state,size_64,state);

        printf("after addition \n");
        for(int j=0;j<size_64;j++)
            printf("%lx ",state[j]);
        printf("\n");
        
        //apply the Sonic permutation
        Sonic_Encrypt_256(state,state_tmp);

        printf("after permutation \n");
        for(int j=0;j<size_64;j++)
            printf("%lx ",state_tmp[j]);
        printf("\n");

        //apply the feedforward
        add(state_tmp,state,size_64,state);

        printf("after feedforward \n");
        for(int j=0;j<size_64;j++)
            printf("%lx ",state[j]);
        printf("\n\n");
    }

    copy_elt(state,size_64,output);

    
    for(int i=0;i<full_bloc+1;i++)
        free(input_bloc[i]);
    free(input_bloc);
    free(state_tmp);
    free(state);
}

//SoniK
void sonik_procrastinate( uint8_t* diversifier, int size_diversifier, uint64_t* key,uint64_t* output){
    
    int size_64 = 4;
    uint64_t* state = malloc(sizeof(uint64_t)*size_64);
    uint64_t* state_tmp = malloc(sizeof(uint64_t)*size_64);
    state[0] = key[0];
    state[1] = key[1];
    state[2] = key[2];
    state[3] = key[3];

    state_tmp[0] = 0;
    state_tmp[1] = 0;
    state_tmp[2] = 0;
    state_tmp[3] = 0;


    //initialization round
    Sonic_Encrypt_256_procrastinate(state,state_tmp);

    add(key,state_tmp,size_64,state);

    //absorbtion of diversifier

    int full_bloc = size_diversifier/28;

    uint64_t** input_bloc = malloc(sizeof(uint64_t*)*(full_bloc+1));
    for(int i=0;i<full_bloc+1;i++){
        input_bloc[i] = malloc(sizeof(uint64_t)*size_64);
        input_bloc[i][0] = 0;
        input_bloc[i][1] = 0;
        input_bloc[i][2] = 0;
        input_bloc[i][3] = 0;
    }
    
    encode_prefix_free(diversifier,size_diversifier,full_bloc,size_64,input_bloc);
    

    printf("paded diversifier: \n");
    for(int i=0;i<full_bloc+1;i++){
        //add input bloc
        for(int j=0;j<size_64;j++)
            printf("%lx ",input_bloc[i][j]);
        printf("\n");
        add(input_bloc[i],state,size_64,state);

        printf("after addition \n");
        for(int j=0;j<size_64;j++)
            printf("%lx ",state[j]);
        printf("\n");
        
        //apply the Sonic permutation
        Sonic_Encrypt_256_procrastinate(state,state_tmp);

        printf("after permutation \n");
        for(int j=0;j<size_64;j++)
            printf("%lx ",state_tmp[j]);
        printf("\n");

        //apply the feedforward
        add(state_tmp,state,size_64,state);

        printf("after feedforward \n");
        for(int j=0;j<size_64;j++)
            printf("%lx ",state[j]);
        printf("\n\n");
    }

    copy_elt(state,size_64,output);
    

    for(int i=0;i<full_bloc+1;i++)
        free(input_bloc[i]);
    free(input_bloc);
    free(state_tmp);
    free(state);
}