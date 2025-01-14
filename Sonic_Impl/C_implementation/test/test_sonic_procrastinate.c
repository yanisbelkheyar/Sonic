#include <stdio.h>
#include <stdint.h>
#include "../sonic_procrastinate.h"
#include <time.h>
#include <stdlib.h>
/*
void print_hex(uint64_t val){

  uint64_t res = 0;
  for(int i=0;i<64;i++){
    res += (val>>i & 1)<<(64-i-1);
  }
  printf("%lx ",res);

}

void print_bin(uint64_t val){
  uint64_t res = 0;
  for(int i=0;i<64;i++){
    printf("%d",(val>>(64-i-1) & 1));
  }
  printf(" ");
}
*/
int main(){

    // test for size 512
    int size = 4;

    uint64_t* plaintext = malloc(sizeof(uint64_t)*size);
    uint64_t* ciphertext = malloc(sizeof(uint64_t)*size);

    printf("Test for Sonic procrastinated :\n");

    int nbr_test = 1;

    for(int test=0;test<nbr_test;test++){
    
      printf("plaintext:  ");
      for(int i=0;i<size;i++){
        plaintext[i] = rand() ^ (uint64_t)rand()<<32 ;
        //print_hex(plaintext[i]);
        printf("%lx ",plaintext[i]);
      }
      printf("\n");
      if(size==4)
        Sonic_Encrypt_256_procrastinate(plaintext,ciphertext);
      if(size==8)
        Sonic_Encrypt_512_procrastinate(plaintext,ciphertext);

      printf("ciphertext: ");
      for(int i=0;i<size;i++){
        //print_hex(ciphertext[i]);
        printf("%lx ",ciphertext[i]);
        //if(i==0)
        //  print_bin(ciphertext[i]);
      }
      printf("\n");

      if(size==4)
        Sonic_Decrypt_256_procrastinate(ciphertext,plaintext);
      if(size==8)
        Sonic_Decrypt_512_procrastinate(ciphertext,plaintext);

      printf("plaintext:  ");
      for(int i=0;i<size;i++){
        //print_hex(plaintext[i]);
        printf("%lx ",plaintext[i]);
      }
      printf("\n");
    }
    free(plaintext);
    free(ciphertext);
    return 0;
}
