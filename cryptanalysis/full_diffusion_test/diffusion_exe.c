#include "diffusion_test.h"
#include <omp.h>

#define one(x,i) ((x>>i)&1)

#define SIZE 512
#define H_SIZE 256
#define THREADS_NBR 16

typedef uint64_t (*round_function)(uint64_t);


// Left output = (right_input<<NL1 & right_input<<NL2) + right_input<<R1 + left_input
// Right output = right_input<<L1 + right_input<<L2 + right_input<<L3

static int NL1 = 0;    //first rotation for the AND
static int NL2 = 0;    //seconde rotation for the AND
static int R1 = 0;     //rotation for the xor after the AND
static int L1 = 0;     //first rotation for the mixing layer
static int L2 = 0;     //seconde rotation for the mixing layer
static int L3 = 0;     //third rotation for the mixing layer
static int M = 0;     //multiplicative shuffle for the right part


//set the rotation value for the round function
/* void set_rotation(int nl1, */
/* 		  int nl2, */
/* 		  int r1, */
/* 		  int l1, */
/* 		  int l2, */
/* 		  int l3, */
/* 		  int m){ */
/*   NL1 = nl1; */
/*   NL2 = nl2; */
/*   R1 = r1; */
/*   L1 = l1; */
/*   L2 = l2; */
/*   L3 = l3; */
/*   M = m; */
/* } */


//cycling shift modulo size : state<<shift modulo size
uint64_t shifted(uint64_t state,
	    int shift,
	    int size){

  uint64_t mask = ((uint64_t)1<<size-shift) - 1;
  uint64_t output = (state<<size-shift) | ((state>>(shift)) & mask);
  
  return output & (((uint64_t)1<<size)-1);
}


//round function of SimonX (X<=64)
uint64_t enc_simon(uint64_t input){
  
  uint64_t output = 0;
  
  for(int i = 0; i < H_SIZE; i++){
      
    output |= ((one(input,(i+NL1) % H_SIZE)
		& one(input,(i+NL2) % H_SIZE))
	       ^ one(input,(i+R1) % H_SIZE)
	       ^ one(input,i+H_SIZE)
	       )<<i;

    output |= one(input,i)<<(i+H_SIZE);
   
  }
  return output;
}


//round function of SimonX (X>64)
int* enc_simon_big(int* input){
  
  int* output = malloc(sizeof(int)*SIZE);
  
  for(int i = 0; i < H_SIZE; i++){
      
    output[i] = (input[i+1 % H_SIZE] & input[i+8 %H_SIZE]) ^ input[i+2 % H_SIZE] ^ input[i+H_SIZE];

    output[i+H_SIZE] = input[i];
   
  }
  free(input);
  
  return output;
}


//round function of SonicX (X<=64)
uint64_t enc(int NL1,
	     int NL2,
	     int R1,
	     int L1,
	     int L2,
	     int L3,
	     int M,
	     uint64_t input){
  
  uint64_t L_output = 0;
  uint64_t R_output = 0;
  
  uint64_t L_input = input & (((uint64_t)1<<H_SIZE)-1);
  uint64_t R_input = (input >> (H_SIZE)) & (((uint64_t)1<<H_SIZE)-1);

  R_output = shifted(L_input,L1,H_SIZE) ^ shifted(L_input,L2,H_SIZE) ^ shifted(L_input,L3,H_SIZE);

  L_output = (shifted(L_input,NL1,H_SIZE) & shifted(L_input,NL2,H_SIZE) ) ^ shifted(L_input,R1,H_SIZE) ^ R_input;

  //R_output = shifted(R_output,M,H_SIZE);
  for(int i=0;i<H_SIZE;i++){
    R_input ^= one(R_output,i)<<((i*M)%H_SIZE);
    L_input ^= one(L_output,i)<<((i*M)%H_SIZE);
  }
  R_output = R_input;
  L_output = L_input;
  uint64_t output = L_output ^ R_output<<H_SIZE;
  
  return output;
}


//round function of SonicX (X>64)
int* enc_big(int NL1,
	     int NL2,
	     int R1,
	     int L1,
	     int L2,
	     int L3,
	     int M,
	     int* input){
  
        

  int* output = malloc(sizeof(int)*SIZE);

  for(int i=0;i<SIZE;i++)
    output[i] = 0;
  
  for(int i = 0; i < H_SIZE; i++){
      
    output[(i*M)% H_SIZE] = (input[(i+NL1) % H_SIZE] & input[(i+NL2) %H_SIZE]) ^ input[(i+R1) % H_SIZE] ^ input[i+H_SIZE];
    //output[(i*M)% H_SIZE] = ((input[(i)%H_SIZE] & input[(i+1)%H_SIZE]) | (input[(i+3)%H_SIZE] & input[(i+7)%H_SIZE])) ^ input[(i+12)%H_SIZE] ^ input[i+H_SIZE];
    
    output[((i*M)% H_SIZE)+H_SIZE] = input[(i+L1) % H_SIZE] ^ input[(i+L2) % H_SIZE] ^ input[(i+L3) % H_SIZE];
  }

  free(input);
  
  return output;
}

int* enc_big_rev(int NL1,
	     int NL2,
	     int R1,
	     int L1,
	     int L2,
	     int L3,
	     int M,
	     int* input){

  int IM = 111;

  int* output = malloc(sizeof(int)*SIZE);

  for(int i=0;i<SIZE;i++)
    output[i] = 0;
  
  for(int i = 0; i < H_SIZE; i++){
      
    output[(i*IM)% H_SIZE] = (input[(i+NL1) % H_SIZE] & input[(i+NL2) %H_SIZE]) ^ input[(i+R1) % H_SIZE] ^ input[i+H_SIZE];
    //output[(i*M)% H_SIZE] = ((input[(i)%H_SIZE] & input[(i+1)%H_SIZE]) | (input[(i+3)%H_SIZE] & input[(i+7)%H_SIZE])) ^ input[(i+12)%H_SIZE] ^ input[i+H_SIZE];
    
    if(SIZE==256){
    //inv of 1+X^7+X^32 mod 128
    output[((i*IM)% H_SIZE)+H_SIZE] = input[(i+4) % H_SIZE] ^ input[(i+18) % H_SIZE] ^ input[(i+36) % H_SIZE] ^ input[(i+43) % H_SIZE] 
    ^ input[(i+68) % H_SIZE] ^ input[(i+100) % H_SIZE] ^ input[(i+107) % H_SIZE] ^ input[(i+114) % H_SIZE] ^ input[(i+121) % H_SIZE]; //input[(i+L1) % H_SIZE] ^ input[(i+L2) % H_SIZE] ^ input[(i+L3) % H_SIZE];

    output[((i*IM)% H_SIZE)+H_SIZE] = input[(i+16) % H_SIZE] ^ input[(i+56) % H_SIZE] ^ input[(i+72) % H_SIZE] ^ input[(i+88) % H_SIZE] 
      ^ input[(i+96) % H_SIZE] ^ input[(i+104) % H_SIZE] ^ input[(i+120) % H_SIZE] ; //input[(i+L1) % H_SIZE] ^ input[(i+L2) % H_SIZE] ^ input[(i+L3) % H_SIZE];

    
    }else if(SIZE==512){
    //inv of 1+X^7+X^32 mod 256
    output[((i*IM)% H_SIZE)+H_SIZE] =  input[(i+249) % H_SIZE] ^ input[(i+246) % H_SIZE] 
    ^ input[(i+242) % H_SIZE] ^ input[(i+235) % H_SIZE] ^ input[(i+232) % H_SIZE] ^ input[(i+228) % H_SIZE] ^ input[(i+221) % H_SIZE] ^ 
    input[(i+214) % H_SIZE] ^ input[(i+207) % H_SIZE] ^ input[(i+200) % H_SIZE] ^ input[(i+168) % H_SIZE] ^ input[(i+143) % H_SIZE] 
    ^ input[(i+136) % H_SIZE] ^ input[(i+118) % H_SIZE] ^ input[(i+104) % H_SIZE] ^ input[(i+93) % H_SIZE] ^ input[(i+86) % H_SIZE] ^
    input[(i+79) % H_SIZE] ^ input[(i+72) % H_SIZE] ^ input[(i+68) % H_SIZE] ^ input[(i+43) % H_SIZE] ^ input[(i+40) % H_SIZE] 
    ^ input[(i+36) % H_SIZE] ^ input[(i+18) % H_SIZE] ^ input[(i+15) % H_SIZE] ^ input[(i+8) % H_SIZE] ^ input[(i+4) % H_SIZE] ;
    }

  /*
    output[((i*IM)% H_SIZE)+H_SIZE] = input[(i+127) % H_SIZE] ^ input[(i+125) % H_SIZE] ^ input[(i+124) % H_SIZE] ^ input[(i+123) % H_SIZE] 
    ^ input[(i+120) % H_SIZE] ^ input[(i+118) % H_SIZE] ^ input[(i+116) % H_SIZE] ^ input[(i+115) % H_SIZE] ^ input[(i+114) % H_SIZE] ^ 
    input[(i+113) % H_SIZE] ^ input[(i+105) % H_SIZE] ^ input[(i+101) % H_SIZE] ^ input[(i+98) % H_SIZE] ^ input[(i+93) % H_SIZE] 
    ^ input[(i+91) % H_SIZE] ^ input[(i+90) % H_SIZE] ^ input[(i+87) % H_SIZE] ^ input[(i+85) % H_SIZE] ^ input[(i+84) % H_SIZE] ^ 
    input[(i+83) % H_SIZE] ^ input[(i+82) % H_SIZE] ^ input[(i+81) % H_SIZE] ^ input[(i+77) % H_SIZE] ^ input[(i+70) % H_SIZE] 
    ^ input[(i+69) % H_SIZE] ^ input[(i+66) % H_SIZE] ^ input[(i+63) % H_SIZE] ^ input[(i+62) % H_SIZE] ^ input[(i+61) % H_SIZE] ^ 
    input[(i+58) % H_SIZE] ^ input[(i+57) % H_SIZE] ^ input[(i+56) % H_SIZE] ^ input[(i+54) % H_SIZE] ^ input[(i+52) % H_SIZE] 
    ^ input[(i+51) % H_SIZE] ^ input[(i+50) % H_SIZE] ^ input[(i+45) % H_SIZE] ^ input[(i+42) % H_SIZE] ^ input[(i+37) % H_SIZE] ^ 
    input[(i+35) % H_SIZE] ^ input[(i+34) % H_SIZE] ^ input[(i+33) % H_SIZE] ^ input[(i+31) % H_SIZE] ^ input[(i+28) % H_SIZE] 
    ^ input[(i+25) % H_SIZE] ^ input[(i+23) % H_SIZE] ^ input[(i+20) % H_SIZE] ^ input[(i+19) % H_SIZE] ^ input[(i+18) % H_SIZE] ^
    input[(i+14) % H_SIZE] ^ input[(i+13) % H_SIZE] ^ input[(i+10) % H_SIZE] ^ input[(i+9) % H_SIZE] ^ input[(i+7) % H_SIZE] 
    ^ input[(i+6) % H_SIZE] ^ input[(i+3) % H_SIZE] ^ input[(i+2) % H_SIZE] ^ input[(i+1) % H_SIZE] ^ input[(i) % H_SIZE] ;
    */

  }

  free(input);
  
  return output;

}


//read the file
//creat a liste with the number of elements [x,y,z] in the file
//return the list
int** read_file(char* file_name,int* size_list){
	
  FILE* file = fopen(file_name,"r");

  int x,y,z;
  
  int nbr_elt=0;
  
  //read the file and find the number of elements
  while(fscanf(file,"[%d,%d,%d],",&x,&y,&z) != 0){
    nbr_elt++;
  }
  
  
  size_list[0] = nbr_elt;
  
  int** list = malloc(sizeof(int*)*nbr_elt);
  for(int i=0;i<nbr_elt;i++)
    list[i] = malloc(sizeof(int)*3);
  
  int index = 0;

  fclose(file);
  file = fopen(file_name,"r");
  
  while(fscanf(file,"[%d,%d,%d],",&x,&y,&z) != 0){
    list[index][0] = z;
    list[index][1] = y;
    list[index][2] = x;
    index++;
  }

  fclose(file);
  
  return list;
}


//test all rotation value for nbr_round round and a sample of size_sample for SonicX (X<=64) round function
void test_all(int nbr_round,
	      int size_sample){

  double max_dep = 0.0;
  double max_weight = (double)H_SIZE-0.2;
  double max_ent = (double)SIZE-0.2;

  int max = 32;
  
  /* for(int R1=1;R1<max;R1++){ */
  /*   printf("R1 = %d \n",R1); */
  //for(int NL1=0;NL1<H_SIZE;NL1++){
  //for(int NL2=NL1+1;NL2<H_SIZE;NL2++){
  int NL1 = 0;
  int NL2 = 1;

  //read the liste of rotation value in the file poly_H_SIZE.txt
  //creat the name of the file
  char file_name[100];
  sprintf(file_name,"poly_%d_v2.txt",SIZE);
  
  int size_list = 0;
  
  int** list = read_file(file_name,&size_list);

  char result_file_name[100];
  sprintf(result_file_name,"result_diffusion_filtered_%d.txt",SIZE);
  FILE* file = fopen(result_file_name,"w+");

  printf("result file created\n");

  int M = 15;
  
  for(int index=1;index<size_list;index++){
    int L1 = list[index][0];
    int L2 = list[index][1];
    int L3 = list[index][2];
    if(((L1%2==1 && L2%2==0 && L3%2==0) || (L2%2==1 && L1%2==0 && L3%2==0) || (L3%2==1 && L1%2==0 && L2%2==0) || (L1%2==1 && L2%2==1 && L3%2==0) || (L1%2==1 && L2%2==0 && L3%2==1) || (L1%2==0 && L2%2==1 && L3%2==1)) && (L3<64)){
    //for(int L1=0;L1<max-2;L1++){
    //#pragma omp parallel num_threads(THREADS_NBR)
    //for(int L2=L1+1;L2<max-1;L2++){
    //#pragma omp parallel num_threads(THREADS_NBR)
    //for(int L3=L2+1;L3<max;L3++){
    //#pragma omp parallel num_threads(THREADS_NBR)
    //#pragma omp parallel num_threads(THREADS_NBR)
      for(int R1=1;R1<max;R1+=2){
        //printf("for %d , (%d,%d), X^%d+X^%d+X^%d %d\n",R1,NL1,NL2,L1,L2,L3,M);
        //apply the filter : L1,L2,L3 one should be odd two even
        //                   R1 should be odd 
        
        //set_rotation(NL1,NL2,R1,L1,L2,L3,M);
        //set_rotation(NL1,NL1+1,R1,L1,L2,L3);
        struct matrix* m;
        if(SIZE<=64)
          m = test_dif(nbr_round,
                SIZE,
                enc,
                NL1,
                NL2,
                R1,
                L1,
                L2,
                L3,
                M,
                size_sample);
        else
          m = test_dif_big(nbr_round,
              SIZE,
              enc_big,
              NL1,
              NL2,
              R1,
              L1,
              L2,
              L3,
              M,
              size_sample);
          
        double cur_dep = min_avalanche_dependence(m,size_sample);
        double cur_weight = min_avalanche_weight(m,size_sample);
        double cur_ent = min_avalanche_entropy(m,size_sample);

        //printf("for %d , (%d,%d), X^%d+X^%d+X^%d %d\n",R1,NL1,NL2,L1,L2,L3,M);
        //printf("the min avalanche dependence is %f, the min avalanche weight is %f, the min avalanche entropy is %f for %d round \n",cur_dep,cur_weight,cur_ent,nbr_round);
        if(cur_ent>=max_ent && cur_weight>max_weight){
          
          //max_dep = cur_dep;
          //max_weight = cur_weight;
          //max_ent = cur_ent;
          
          //print the result in the form [NL1,NL2,R1,L1,L2,L3,M] in the file result_diffusion_H_SIZE.txt
          fprintf(file,"[%d,%d,%d,%d,%d,%d,%d]\n",NL1,NL2,R1,L1,L2,L3,M);
          fflush(file);
          
          printf("for %d , (%d,%d), X^%d+X^%d+X^%d %d\n",R1,NL1,NL2,L1,L2,L3,M);
          printf("the min avalanche dependence is %f, the min avalanche weight is %f, the min avalanche entropy is %f for %d round \n",cur_dep,cur_weight,cur_ent,nbr_round);
          
        }
                
        free_matrix(m);
      }
    }
    //}
    //}
    //}
    //}
  }

  for(int i=0;i<size_list;i++)
    free(list[i]);
  free(list);
  fclose(file);
  
}

//test a specific set of rotation value for SonicX (X<=64)
void test_one(int nbr_round,
	      int NL1,
	      int NL2,
	      int R1,
	      int L1,
	      int L2,
	      int L3,
	      int M,
	      int size_sample){
  
  //set_rotation(NL1,NL2,R1,L1,L2,L3,M);
  
  struct matrix* m = test_dif(nbr_round,
			      SIZE,
			      enc,
			      NL1,
			      NL2,
			      R1,
			      L1,
			      L2,
			      L3,
			      M,
			      size_sample);
  
  double cur_dep = min_avalanche_dependence(m,size_sample);
  double cur_weight = min_avalanche_weight(m,size_sample);
  double cur_ent = min_avalanche_entropy(m,size_sample);

  printf("for %d , (%d,%d), X^%d+X^%d+X^%d %d\n",R1,NL1,NL2,L1,L2,L3,M);
  printf("the min avalanche dependence is %f, the min avalanche weight is %f, the min avalanche entropy is %f for %d round \n",cur_dep,cur_weight,cur_ent,nbr_round);
  
}
	
//test a specific set of rotation value for SonicX (X>64)
void test_big(int nbr_round,
	      int NL1,
	      int NL2,
	      int R1,
	      int L1,
	      int L2,
	      int L3,
	      int M,
	      int size_sample){
  
  //set_rotation(NL1,NL2,R1,L1,L2,L3,M);
  
  struct matrix* m = test_dif_big(nbr_round,
				  SIZE,
				  enc_big,
				  NL1,
				  NL2,
				  R1,
				  L1,
				  L2,
				  L3,
				  M,
				  size_sample);
	      
  double cur_dep = min_avalanche_dependence(m,size_sample);
  double cur_weight = min_avalanche_weight(m,size_sample);
  double cur_ent = min_avalanche_entropy(m,size_sample);

  printf("for %d , (%d,%d), X^%d+X^%d+X^%d %d \n",R1,NL1,NL2,L1,L2,L3,M);
  printf("the min avalanche dependence is %f, the min avalanche weight is %f, the min avalanche entropy is %f for %d round \n",cur_dep,cur_weight,cur_ent,nbr_round);

  free_matrix(m);

}

//test a specific set of rotation value for SonicX (X>64)
void test_big_simon(int nbr_round,
	      int size_sample){
  
  
  struct matrix* m = test_dif_big_simon(nbr_round,
				  SIZE,
				  enc_simon_big,
				  size_sample);
	      
  double cur_dep = min_avalanche_dependence(m,size_sample);
  double cur_weight = min_avalanche_weight(m,size_sample);
  double cur_ent = min_avalanche_entropy(m,size_sample);

  printf("the min avalanche dependence is %f, the min avalanche weight is %f, the min avalanche entropy is %f for %d round \n",cur_dep,cur_weight,cur_ent,nbr_round);

  free_matrix(m);

}


//test for a set of number of round start from nbr_round_start to nbr_round_end the rotation value for SonicX 
void test_full_round_simon(int size_sample,
		     int nbr_round_start,
		     int nbr_round_end){

  for(int i=nbr_round_start;i<nbr_round_end;i++){
    
    if(SIZE>64){
      //treat the case of big state
      test_big_simon(i,size_sample);
    }
  }
}

//test for a set of number of round start from nbr_round_start to nbr_round_end the rotation value for SonicX 
void test_full_round(int NL1,
		     int NL2,
		     int R1,
		     int L1,
		     int L2,
		     int L3,
		     int M,
		     int size_sample,
		     int nbr_round_start,
		     int nbr_round_end){

  for(int i=nbr_round_start;i<nbr_round_end;i++){
    
    if(SIZE>64){
      //treat the case of big state
      test_big(i,NL1,NL2,R1,L1,L2,L3,M,size_sample);
    }else{
      //the case of small state <64
      test_one(i,NL1,NL2,R1,L1,L2,L3,M,size_sample);
    }
  }
}


int main(){

  int nbr_round = 9;
  if(SIZE<128)
    nbr_round = 6;
  
  int nbr_sample = 1000000;

  nbr_sample = 100000;

  printf("test for size %d, for %d round\n",SIZE,nbr_round);

  test_full_round(0,1,5,0,3,20,7,nbr_sample,0,nbr_round);

  //test_all(nbr_round,nbr_sample);

  //test_full_round(0,1,27,0,1,3,15,nbr_sample,1,9);
  //test_full_round(0,1,12,0,8,10,15,nbr_sample,1,8);

  //test_full_round(0,1,4,2,8,16,15,nbr_sample,1,15);
  //test_full_round(0,1,12,1,8,10,15,nbr_sample,1,15);
  
  //test_full_round_simon(nbr_sample,0,19);
  //test_full_round_simon(nbr_sample,28,31);

  
  //test_one(nbr_round,1,2,0,4,6,8,nbr_sample);
  //test_one(nbr_round,12,29,1,1,3,27,nbr_sample);
  //test_full_round_simon(nbr_sample,0,60);

  //test_big(nbr_round,0,23,1,12,16,19,nbr_sample);

  //test_full_round(0,1,3,1,12,27,nbr_sample,1,14);
  
  return 1;
}
