#include "diffusion_test.h"
#include "usefull/function_binary.h"

#define one(x,i) ((x>>i)&1)

#define SIZE 64
#define H_SIZE 32

typedef uint64_t (*round_function)(uint64_t);


// Left output = (right_input<<NL1 & right_input<<NL2) + right_input<<R1 + left_input
// Right output = right_input<<L1 + right_input<<L2 + right_input<<L3

static int NL1 = 0;    //first rotation for the AND
static int NL2 = 0;    //seconde rotation for the AND
static int NL3 = 0;
static int NL4 = 0;
static int R1 = 0;     //rotation for the xor after the AND
static int L1 = 0;     //first rotation for the mixing layer
static int L2 = 0;     //seconde rotation for the mixing layer
static int L3 = 0;     //third rotation for the mixing layer
static int M = 0;

//set the rotation value for the round function
void set_rotation(int nl1,
		  int nl2,
		  int nl3,
		  int nl4,
		  int r1,
		  int l1,
		  int l2,
		  int l3,
		  int M){
  NL1 = nl1;
  NL2 = nl2;
  NL3 = nl3;
  NL4 = nl4;
  R1 = r1;
  L1 = l1;
  L2 = l2;
  L3 = l3;
  M = M;
}


//cycling shift modulo size : state<<shift modulo size
uint64_t shifted(uint64_t state,
	    int shift,
	    int size){

  uint64_t mask = ((uint64_t)1<<size-shift) - 1;
  uint64_t output = (state<<size-shift) | ((state>>(shift)) & mask);
  
  return output & (((uint64_t)1<<size)-1);
}


//round function of SuperSonicX (X<=64)
uint64_t enc(uint64_t input){
  
  uint64_t L_output = 0;
  uint64_t R_output = 0;
  
  uint64_t L_input = input & (((uint64_t)1<<H_SIZE)-1);
  uint64_t R_input = (input >> (H_SIZE)) & (((uint64_t)1<<H_SIZE)-1);

  R_output = shifted(L_input,L1,H_SIZE) ^ shifted(L_input,L2,H_SIZE) ^ shifted(L_input,L3,H_SIZE);

  L_output = ((shifted(L_input,NL1,H_SIZE) & shifted(L_input,NL2,H_SIZE)) | (shifted(L_input,NL3,H_SIZE) & shifted(L_input,NL4,H_SIZE))) ^ shifted(L_input,R1,H_SIZE) ^ R_input;

  //R_output = shifted(R_output,M,H_SIZE);
  for(int i=0;i<H_SIZE;i++)
    R_input ^= one(R_output,i)<<((i*M)%H_SIZE);

  R_output = R_input;

  uint64_t output = L_output ^ R_output<<H_SIZE;
  
  return output;
}


/* //round function of SuperSonicX (X>64) */
/* int* enc_big(int* input){ */
  
/*   int* output = malloc(sizeof(int)*SIZE); */

/*   for(int i=0;i<SIZE;i++) */
/*     output[i] = 0; */
  
/*   for(int i = 0; i < H_SIZE; i++){ */
      
/*     output[(i*M)% H_SIZE] = ((input[(i+NL1)%H_SIZE] & input[(i+NL2)%H_SIZE]) | (input[(i+NL3)%H_SIZE] & input[(i+NL4)%H_SIZE])) ^ input[(i+R1)%H_SIZE] ^ input[i+H_SIZE]; */

/*     output[i+H_SIZE] = input[(i+L1) % H_SIZE] ^ input[(i+L2) % H_SIZE] ^ input[(i+L3) % H_SIZE]; */
/*   } */

/*   free(input); */
  
/*   return output; */
/* } */


//round function of SonicX (X>64)
int* enc_big(int* input){
  
  int* output = malloc(sizeof(int)*SIZE);

  for(int i=0;i<SIZE;i++)
    output[i] = 0;
  
  for(int i = 0; i < H_SIZE; i++){
      
    output[(i*M) % H_SIZE] = (input[(i+NL1) % H_SIZE] & input[(i+NL2) %H_SIZE]) ^ input[(i+R1) % H_SIZE] ^ input[i+H_SIZE];

    output[((i*M) % H_SIZE) + H_SIZE] = input[(i+L1) % H_SIZE] ^ input[(i+L2) % H_SIZE] ^ input[(i+L3) % H_SIZE];
  }

  free(input);
  
  return output;
}


//test all rotation value for nbr_round round and a sample of size_sample for SonicX (X<=64) round function
void test_all(int nbr_round,
	      int size_sample){

  double max_dep = 0.0;
  double max_weight = 0.0;//32.60;
  double max_ent = 63.90;

  for(int R1=0;R1<H_SIZE;R1++){
    printf("R1 = %d \n",R1);
    for(int NL1=1;NL1<H_SIZE;NL1++){
      for(int NL2=NL1+1;NL2<H_SIZE;NL2++){
	for(int NL3=NL3+1;NL3<H_SIZE;NL3++){
	  for(int NL4=NL3+1;NL4<H_SIZE;NL4++){
	    for(int L1=0;L1<H_SIZE-2;L1++){
	      for(int L2=L1+1;L2<H_SIZE-1;L2++){
		for(int L3=L2+1;L3<H_SIZE;L3++){
		  for(int M=2;M<H_SIZE;M++){
		  
		    set_rotation(NL1,NL2,NL3,NL4,R1,L1,L2,L3,M);
		    //set_rotation(NL1,NL1+1,R1,L1,L2,L3);
		  
		    struct matrix* m = test_dif(nbr_round,
						SIZE,
						enc,
						size_sample);
		  
		    double cur_dep = min_avalanche_dependence(m,size_sample);
		    double cur_weight = min_avalanche_weight(m,size_sample);
		    double cur_ent = min_avalanche_entropy(m,size_sample);
		  
		    if(cur_ent>=max_ent && cur_weight>max_weight){
		    
		      max_dep = cur_dep;
		      //max_weight = cur_weight;
		      //max_ent = cur_ent;
		    
		      printf("for %d , (%d,%d) | (%d,%d) , X^%d+X^%d+X^%d %d\n",R1,NL1,NL2,NL3,NL4,L1,L2,L3,M);
		      printf("the min avalanche dependence is %f, the min avalanche weight is %f, the min avalanche entropy is %f for %d round \n",cur_dep,cur_weight,cur_ent,nbr_round);
		    
		    }
		  
		    free_matrix(m);
		  }
		}
	      }
	    }
	  }
	}
      }
    }
  }
}

//test a specific set of rotation value for SonicX (X<=64)
void test_one(int nbr_round,
	      int NL1,
	      int NL2,
	      int NL3,
	      int NL4,
	      int R1,
	      int L1,
	      int L2,
	      int L3,
	      int M,
	      int size_sample){
  
  set_rotation(NL1,NL2,NL3,NL4,R1,L1,L2,L3,M);
  
  struct matrix* m = test_dif(nbr_round,
			      SIZE,
			      enc,
			      size_sample);
	      
  double cur_dep = min_avalanche_dependence(m,size_sample);
  double cur_weight = min_avalanche_weight(m,size_sample);
  double cur_ent = min_avalanche_entropy(m,size_sample);

  printf("for %d , (%d,%d) | (%d,%d) , X^%d+X^%d+X^%d %d\n",R1,NL1,NL2,NL3,NL4,L1,L2,L3,M);
  printf("the min avalanche dependence is %f, the min avalanche weight is %f, the min avalanche entropy is %f for %d round \n",cur_dep,cur_weight,cur_ent,nbr_round);
  
}

		
//test a specific set of rotation value for SonicX (X>64)
void test_big(int nbr_round,
	      int NL1,
	      int NL2,
	      int NL3,
	      int NL4,
	      int R1,
	      int L1,
	      int L2,
	      int L3,
	      int M,
	      int size_sample){
  
  set_rotation(NL1,NL2,NL3,NL4,R1,L1,L2,L3,M);
  
  struct matrix* m = test_dif_big(nbr_round,
			      SIZE,
			      enc_big,
			      size_sample);
	      
  double cur_dep = min_avalanche_dependence(m,size_sample);
  double cur_weight = min_avalanche_weight(m,size_sample);
  double cur_ent = min_avalanche_entropy(m,size_sample);

  printf("for %d , (%d,%d) | (%d,%d) , X^%d+X^%d+X^%d %d\n",R1,NL1,NL2,NL3,NL4,L1,L2,L3,M);
  printf("the min avalanche dependence is %f, the min avalanche weight is %f, the min avalanche entropy is %f for %d round \n",cur_dep,cur_weight,cur_ent,nbr_round);

  free_matrix(m);

}


//test for a set of number of round start from nbr_round_start to nbr_round_end the rotation value for SonicX 
void test_full_round(int NL1,
		     int NL2,
		     int NL3,
		     int NL4,
		     int R1,
		     int L1,
		     int L2,
		     int L3,
		     int M,
		     int size_sample,
		     int nbr_round_start,
		     int nbr_round_end){

  for(int i=nbr_round_start;i<nbr_round_end;i++){
    
    if(SIZE>32){
      //treat the case of big state
      test_big(i,NL1,NL2,NL3,NL4,R1,L1,L2,L3,M,size_sample);
    }else{
      //the case of small state <64
      test_one(i,NL1,NL2,NL3,NL4,R1,L1,L2,L3,M,size_sample);
    }
  }
}

int main(){

  int nbr_round = 5;
  int nbr_sample = 10000;

  test_full_round(0,1,3,7,12,1,8,10,15,nbr_sample,1,10);

  //test_all(nbr_round,nbr_sample);

  //test_full_round(1,2,5,9,12,1,3,6,11,nbr_sample,1,12);
  //test_full_round(0,14,0,8,10,24,nbr_sample,1,8);
  
  //test_full_round_simon(nbr_sample,1,19);
  //test_full_round_simon(nbr_sample,28,31);

  
  //test_one(nbr_round,1,12,0,4,26,30,nbr_sample);
  //test_one(nbr_round,12,29,1,1,3,27,nbr_sample);
  //test_big_simon(nbr_round,nbr_sample);

  //test_big(nbr_round,0,23,1,12,16,19,nbr_sample);

  //test_full_round(0,1,3,1,12,27,nbr_sample,1,14);
  
  return 1;
}
