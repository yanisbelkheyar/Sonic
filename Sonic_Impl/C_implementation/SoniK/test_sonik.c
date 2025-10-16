#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "sonik.h"

void test_SoniK(int nbr_bloc){

    srand(0);

    int size = 4;

    uint64_t* key = malloc(sizeof(uint64_t)*size);
    uint8_t* diversifier = malloc(sizeof(uint8_t)*nbr_bloc);
    uint64_t* output = malloc(sizeof(uint64_t)*size);

    //test for Sonik

    printf("\n\nTest for Sonik: \n\n");
    printf("diversifier: ");
    for(int i=0;i<nbr_bloc;i++){
        diversifier[i] = (uint8_t)rand()%256;
        printf("%x ",diversifier[i]);
    }
    printf("\n");

    printf("key:       ");
    for(int i=0;i<size;i++){
        key[i] = rand() ^ (uint64_t)rand()<<32 ;
        printf("%lx ",key[i]);
    }
    printf("\n");

    for(int i=0;i<size;i++){
        output[i] = 0;
    }   

    sonik(diversifier,nbr_bloc,key,output);

    printf("output:   ");
    for(int i=0;i<size;i++)
        printf("%lx ",output[i]);
    printf("\n");
    
    free(key);
    free(diversifier);
    free(output);
}

void test_SoniK_procrastinate(int nbr_bloc){

    srand(0);

    int size = 4;

    uint64_t* key = malloc(sizeof(uint64_t)*size);
    uint8_t* diversifier = malloc(sizeof(uint8_t)*nbr_bloc);
    uint64_t* output = malloc(sizeof(uint64_t)*size);

    //test for Sonik

    printf("\n\nTest for Sonik procrastinate: \n\n");
    printf("diversifier: ");
    for(int i=0;i<nbr_bloc;i++){
        diversifier[i] = (uint8_t)rand()%256;
        printf("%x ",diversifier[i]);
    }
    printf("\n");

    printf("key:       ");
    for(int i=0;i<size;i++){
        key[i] = rand() ^ (uint64_t)rand()<<32 ;
        printf("%lx ",key[i]);
    }
    printf("\n");

    for(int i=0;i<size;i++){
        output[i] = 0;
    }

    sonik_procrastinate(diversifier,nbr_bloc,key,output);

    printf("output:   ");
    for(int i=0;i<size;i++)
        printf("%lx ",output[i]);
    printf("\n");

    free(key);
    free(diversifier);
    free(output);
}

int main(){
    int nbr_bloc = 36;
    test_SoniK_procrastinate(nbr_bloc);
    
    test_SoniK(nbr_bloc);
}