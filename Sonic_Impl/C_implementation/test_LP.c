#include <stdio.h>
#include <stdint.h>
#include "sonic.h"
#include <time.h>
#include <stdlib.h>
#include <unistd.h>


    void print_hex(uint64_t val){

    uint64_t res = 0;
    for(int i=0;i<64;i++){
        res += (val>>i & 1)<<(64-i-1);
    }
    printf("%lx ",res);

    }

    int compute_parity(uint64_t word){
        int res = 0;
        for(int i=0;i<64;i++)
            res = (res + (word>>i) & 1)%2;
        return res;
    }

    int main(int argc, char *argv[]){

        srand(time(NULL));   // Initialization, should only be called once.  
        srandom(time(NULL));    
        srand48(time(NULL));
        // test for size 256
        int size = 4;

        int nbr_round = argv[1][0]-'0';
        
        //read input difference

        //read output difference
        uint64_t* plaintext = malloc(sizeof(uint64_t)*size);

        uint64_t* ciphertext = malloc(sizeof(uint64_t)*size);

        uint64_t* input_mask = malloc(sizeof(uint64_t)*size);
        uint64_t* output_mask = malloc(sizeof(uint64_t)*size);

        //input mask for 1 and 2 round
        //input_mask[0] = (uint64_t)0x8100000080000000;
        //input_mask[1] = (uint64_t)0;
        //input_mask[2] = (uint64_t)0;
        //input_mask[3] = (uint64_t)0;
        
        //output difference for 1 round differential
        //output_mask[0] = (uint64_t)0; 
        //output_mask[1] = (uint64_t)0; 
        //output_mask[2] = (uint64_t)0x8000000000000000; 
        //output_mask[3] = (uint64_t)0;

        //output difference for 2 round differential
        //output_mask[0] = (uint64_t)0x8000000000000000; 
        //output_mask[1] = (uint64_t)0; 
        //output_mask[2] = (uint64_t)0x100804021000000; 
        //output_mask[3] = (uint64_t)0x100800001000040;

        //input mask for 3
        //input_mask[0] = (uint64_t)0x8100000080000000;
        //input_mask[1] = (uint64_t)0x800000000000;
        //input_mask[2] = (uint64_t)0;
        //input_mask[3] = (uint64_t)0x10000000000000;

        //input mask for 4
        //input_mask[0] = (uint64_t)0x400;
        //input_mask[1] = (uint64_t)0xa0000;
        //input_mask[2] = (uint64_t)0x8000000000008000;
        //input_mask[3] = (uint64_t)0x80400000;

        //input mask for 5
        //input_mask[0] = (uint64_t)0x8100000080020000;
        //input_mask[1] = (uint64_t)0x8100814000008100;
        //input_mask[2] = (uint64_t)0x1000000000;
        //input_mask[3] = (uint64_t)0x80000002000;

        //output difference for 2 to 4 round differential
        //output_mask[0] = (uint64_t)0; 
        //output_mask[1] = (uint64_t)0; 
        //output_mask[2] = (uint64_t)0x804000008; 
        //output_mask[3] = (uint64_t)0x2000804020108;

	//test
        //input mask for 2^-12 that is in fact 2^-18
        //input_mask[0] = (uint64_t)0x4000000000000400;
        //input_mask[1] = (uint64_t)0xa0000;
        //input_mask[2] = (uint64_t)0x8000000000008000;
        //input_mask[3] = (uint64_t)0x80400000;

	//input mask for 2^-12 that is in fact 2^-8
        input_mask[0] = (uint64_t)0x400; 
        input_mask[1] = (uint64_t)0xa0000;
        input_mask[2] = (uint64_t)0x8000000000008000;
        input_mask[3] = (uint64_t)0x80400000;

	//output difference for 2 to 4 round differential
        output_mask[0] = (uint64_t)0; 
        output_mask[1] = (uint64_t)0; 
        output_mask[2] = (uint64_t)0x804000008; 
        output_mask[3] = (uint64_t)0x2000804020108;


        for(int n=0;n<4;n++){
            for(int i=0;i<64;i++)
                (input_mask[n]>>(64-i-1)&1)==1?printf("1"):printf("-");
            if(n==1)
                printf(" ");
            printf(" ");
        }
        printf("\n");

        for(int n=0;n<4;n++){
            for(int i=0;i<64;i++)
                (output_mask[n]>>(64-i-1)&1)==1?printf("1"):printf("-");
            if(n==1)
                printf(" ");
            printf(" ");
        }
        printf("\n");

        int nbr_test = 5000000; //-log2DP
        printf("Test for Soni256 :\n");
        long double nbr_try = 1;
        long double sum = 0.0;
        for(int j=0;j<nbr_try;j++){

            int cor = 0;

            for(int test=0;test<nbr_test;test++){
            
                for(int i=0;i<size;i++){
		            plaintext[i] = (uint64_t)(lrand48() %((uint64_t)1<<32)) ^ (uint64_t)(lrand48()%((uint64_t)1<<32))<<32 ; //  (uint64_t)(rand()%(1<<8)) ^ (uint64_t)(rand()%(1<<8))<<8 ^ 
                    //(uint64_t)(rand()%(1<<8))<<16 ^ (uint64_t)(rand()%(1<<8))<<24 ^ 
                    //(uint64_t)(rand()%(1<<8))<<32 ^ (uint64_t)(rand()%(1<<8))<<40 ^ 
                    //(uint64_t)(rand()%(1<<8))<<48 ^ (uint64_t)(rand()%(1<<8))<<56;
                    //sleep(0.5);
		            ciphertext[i] = 0;
                }
/*    
                printf("\nplaintext\n");
                for(int n=0;n<4;n++){
                    for(int i=0;i<64;i++)
                        ((plaintext[n])>>(64-i-1)&1)==1?printf("1"):printf("-");
                    if(n==1)
                        printf(" ");
                }
*/

                Sonic_Encrypt_256_sub_round(plaintext,ciphertext,nbr_round);
/*
                printf("\nciphertext\n");
                for(int n=0;n<4;n++){
                    for(int i=0;i<64;i++)
                        ((ciphertext[n])>>(64-i-1)&1)==1?printf("1"):printf("-");
                    if(n==1)
                        printf(" ");
                }
*/
                
                
                int parity_input = (compute_parity(input_mask[0] & plaintext[0]) 
                        + compute_parity(input_mask[1] & plaintext[1]) 
                        + compute_parity(input_mask[2] & plaintext[2])
                        + compute_parity(input_mask[3] & plaintext[3])) % 2;
                
                int parity_output = (compute_parity(output_mask[0] & ciphertext[0]) 
                            + compute_parity(output_mask[1] & ciphertext[1]) 
                            + compute_parity(output_mask[2] & ciphertext[2])
                            + compute_parity(output_mask[3] & ciphertext[3])) % 2;

                cor += ((parity_output^parity_input) == 0)?1:-1;
            }
            long double p = (long double)cor/(long double)nbr_test;
            printf("\n nbr = %d, nbr_test %d ",cor,nbr_test);
	    printf("\ncorrelation = %Lf \n",p);
            printf("squarre correlation = %Lf \n",p*p);
            sum += p*p;
        }
    
        printf("\n\nsquarre correlation = %Lf \n",sum/nbr_try);

        free(plaintext);
        free(ciphertext);
        free(input_mask);
        free(output_mask);
        return 0;
    }
