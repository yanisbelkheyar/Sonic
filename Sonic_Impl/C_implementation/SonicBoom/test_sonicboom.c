#include "sonicboom.h"

#define PRINT 1

void test_SonicBoom_Encrypt(){

    int size = 4;
    uint64_t* plaintext = malloc(sizeof(uint64_t)*size);
    uint64_t* ciphertext = malloc(sizeof(uint64_t)*size);
    uint64_t* key = malloc(sizeof(uint64_t)*size);

    //test for Sonic Boom
    printf("Test for SonicBoom:\n\n");

    printf("plaintext: ");
    for(int i=0;i<size;i++){
        plaintext[i] = rand() ^ (uint64_t)rand()<<32 ;
        printf("%lx ",plaintext[i]);
    }
    printf("\n");

    printf("key:       ");
    for(int i=0;i<size;i++){
        key[i] = rand() ^ (uint64_t)rand()<<32 ;
        printf("%lx ",key[i]);
    }
    printf("\n");

    sonic_boom_encrypt(plaintext,key,ciphertext);

}

void test_SonicBoom(){

    srand(0);
    int size = 4;
    uint64_t* plaintext = malloc(sizeof(uint64_t)*size);
    uint64_t* ciphertext = malloc(sizeof(uint64_t)*size);
    uint64_t* key = malloc(sizeof(uint64_t)*size);

    //test for Sonic Boom
    printf("Test for SonicBoom:\n\n");

    printf("plaintext: ");
    for(int i=0;i<size;i++){
        plaintext[i] = rand() ^ (uint64_t)rand()<<32 ;
        printf("%lx ",plaintext[i]);
    }
    printf("\n");

    printf("key:       ");
    for(int i=0;i<size;i++){
        key[i] = rand() ^ (uint64_t)rand()<<32 ;
        printf("%lx ",key[i]);
    }
    printf("\n");

    sonic_boom_encrypt(plaintext,key,ciphertext);

    printf("ciphertext: ");
    for(int i=0;i<size;i++)
        printf("%lx ",ciphertext[i]);
    printf("\n");

    sonic_boom_decrypt(ciphertext,key,plaintext);

    printf("plaintext: ");
    for(int i=0;i<size;i++)
        printf("%lx ",plaintext[i]);
    printf("\n");

    free(plaintext);
    free(ciphertext);
    free(key);
}


void test_SonicBoom_procrastinate(){

    srand(0);
    int size = 4;
    uint64_t* plaintext = malloc(sizeof(uint64_t)*size);
    uint64_t* ciphertext = malloc(sizeof(uint64_t)*size);
    uint64_t* key = malloc(sizeof(uint64_t)*size);

    //test for Sonic Boom
    printf("\nTest for SonicBoom procrastinate version:\n\n");

    printf("plaintext: ");
    for(int i=0;i<size;i++){
        plaintext[i] = rand() ^ (uint64_t)rand()<<32 ;
        printf("%lx ",plaintext[i]);
    }
    printf("\n");

    printf("key:       ");
    for(int i=0;i<size;i++){
        key[i] = rand() ^ (uint64_t)rand()<<32 ;
        printf("%lx ",key[i]);
    }
    printf("\n");

    sonic_boom_encrypt_procrastinate(plaintext,key,ciphertext);

    printf("ciphertext: ");
    for(int i=0;i<size;i++)
        printf("%lx ",ciphertext[i]);
    printf("\n");

    sonic_boom_decrypt_procrastinate(ciphertext,key,plaintext);

    printf("plaintext: ");
    for(int i=0;i<size;i++)
        printf("%lx ",plaintext[i]);
    printf("\n");

    free(plaintext);
    free(ciphertext);
    free(key);
}



int main(){

    test_SonicBoom();
    test_SonicBoom_procrastinate();
    return 1;
}