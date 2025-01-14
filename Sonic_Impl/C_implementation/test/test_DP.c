    #include <stdio.h>
    #include <stdint.h>
    #include "../sonic.h"
    #include <time.h>
    #include <stdlib.h>


    void print_hex(uint64_t val){

    uint64_t res = 0;
    for(int i=0;i<64;i++){
        res += (val>>i & 1)<<(64-i-1);
    }
    printf("%lx ",res);

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

    int main(int argc, char *argv[]){

        int reshufle = 1;

        srand(time(NULL));   // Initialization, should only be called once.

        // test for size 256
        int size = 4;

        int nbr_round = argv[1][0]-'0';
        
        //read input difference

        //read output difference
        uint64_t* plaintext = malloc(sizeof(uint64_t)*size);
        uint64_t* plaintext_dif = malloc(sizeof(uint64_t)*size);

        uint64_t* ciphertext = malloc(sizeof(uint64_t)*size);
        uint64_t* ciphertext_dif = malloc(sizeof(uint64_t)*size);

        uint64_t* input_difference = malloc(sizeof(uint64_t)*size);
        uint64_t* output_difference = malloc(sizeof(uint64_t)*size);

	//input difference for 1 to 5 round 
        input_difference[0] = (uint64_t)0;
        input_difference[1] = (uint64_t)0;
        input_difference[2] = (uint64_t)0x8000000000000000; //9223372036854775808;
        input_difference[3] = (uint64_t)0;
        
        //output difference for 1 round differential
        if(nbr_round==1){
        reshufle = 111;
        output_difference[0] = (uint64_t)9223372036854775808;
        output_difference[1] = (uint64_t)0;
        output_difference[2] = (uint64_t)0;
        output_difference[3] = (uint64_t)0;
        }else if(nbr_round==2){
            reshufle = 33;
        //output difference for 2 round differential
        output_difference[0] = (uint64_t)0;
        output_difference[1] = (uint64_t)4398046511104;
        output_difference[2] = (uint64_t)9223372039002259456;
        output_difference[3] = (uint64_t)256;
        }else if(nbr_round==3){
            reshufle = 79;
        //output difference for 3 round differential
        output_difference[0] = (uint64_t)9223372311732715520;
        output_difference[1] = (uint64_t)2147483648;
        output_difference[2] = (uint64_t)0;
        output_difference[3] = (uint64_t)35253091565584;
        }else if(nbr_round==4){
            reshufle = 65;
        //output difference for 4 round differential
        output_difference[0] = (uint64_t)562950021054464;
        output_difference[1] = (uint64_t)0;
        output_difference[2] = (uint64_t)9223373136366403584;
        output_difference[3] = (uint64_t)9296134417846140928;
        }else if(nbr_round==5){
        //output difference for 5 round differential
	// output_difference[0] = (uint64_t)0x8000800000008040; // 9223512774343163904;
        //output_difference[1] = (uint64_t)0x8040200081400040; //9241421621904801792;
        //output_difference[2] = (uint64_t)0x2040280000102800; //2323901388189345792;
        //output_difference[3] = (uint64_t)0;
	}
	/*
	input_difference[0] = (uint64_t)0x8010200000000000;
        input_difference[1] = (uint64_t)0x80000040;
        input_difference[2] = (uint64_t)0x204000010000000; //9223372036854775808;
        input_difference[3] = (uint64_t)0x1001040000c10;

	output_difference[0] = (uint64_t)0xc080041000040800; // 9223512774343163904;
        output_difference[1] = (uint64_t)0x4815042052018034; //9241421621904801792;
        output_difference[2] = (uint64_t)0x80032211948a0110; //2323901388189345792;
        output_difference[3] = (uint64_t)0xc0a8000082250308;
    */
        for(int n=0;n<4;n++){
            for(int i=0;i<64;i++)
                (input_difference[n]>>(64-i-1)&1)==1?printf("1"):printf("-");
            if(n==1)
                printf(" ");
        }
        printf("\n");
        PI_full(reshufle,output_difference);
        for(int n=0;n<4;n++){
            for(int i=0;i<64;i++)
                (output_difference[n]>>(64-i-1)&1)==1?printf("1"):printf("-");
            if(n==1)
                printf(" ");
            printf(" ");
        }
        printf("\n");

        int nbr_test = 100000; //-log2DP
        printf("Test for Soni256 :\n");
        long double nbr_try = 10;
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
/*    
                printf("\nplaintext\n");
                for(int n=0;n<4;n++){
                    for(int i=0;i<64;i++)
                        ((plaintext[n])>>(64-i-1)&1)==1?printf("1"):printf("-");
                    if(n==1)
                        printf(" ");
                }
                printf("\nplaintextdif\n");
                for(int n=0;n<4;n++){
                    for(int i=0;i<64;i++)
                        ((plaintext_dif[n])>>(64-i-1)&1)==1?printf("1"):printf("-");
                    if(n==1)
                        printf(" ");
                }


                printf("\nplaintextdif\n");
                for(int n=0;n<4;n++){
                    for(int i=0;i<64;i++)
                        ((input_difference[n])>>(64-i-1)&1)==1?printf("1"):printf("-");
                    if(n==1)
                        printf(" ");
                }
*/

                Sonic_Encrypt_256_sub_round(plaintext,ciphertext,nbr_round);
                Sonic_Encrypt_256_sub_round(plaintext_dif,ciphertext_dif,nbr_round);
/*
                printf("\nciphertext\n");
                for(int n=0;n<4;n++){
                    for(int i=0;i<64;i++)
                        ((ciphertext[n])>>(64-i-1)&1)==1?printf("1"):printf("-");
                    if(n==1)
                        printf(" ");
                }
                printf("\nciphertextdif\n");
                for(int n=0;n<4;n++){
                    for(int i=0;i<64;i++)
                        ((ciphertext_dif[n])>>(64-i-1)&1)==1?printf("1"):printf("-");
                    if(n==1)
                        printf(" ");
                }
                printf("\ndif\n");
                for(int n=0;n<4;n++){
                    for(int i=0;i<64;i++)
                        ((ciphertext[n]^ciphertext_dif[n])>>(64-i-1)&1)==1?printf("1"):printf("-");
                    if(n==1)
                        printf(" ");
                }
                printf("\n");
*/
                PI_full(reshufle,ciphertext);
                PI_full(reshufle,ciphertext_dif);
                
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
