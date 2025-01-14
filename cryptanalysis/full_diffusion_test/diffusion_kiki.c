#include "diffusion_test.h"
#include "usefull/function_binary.h"
#include <omp.h>

#define one(x,i) ((x>>i)&1)

#define SIZE_DATA 32
#define SIZE_TWEAK 64
#define SIZE SIZE_DATA + SIZE_TWEAK

#define THREADS_NBR 5

typedef uint64_t (*round_function)(uint64_t);

static int NL1 = 0;    //first rotation for the AND
static int NL2 = 1;    //seconde rotation for the AND

static int[3] alpha = {0,0,0};
static int[3] beta = {0,0,0};
static int[3] delta = {0,0,0};
static int[3] gama = {0,0,0};

//compute the non linear mapping for chichi for the tweak part and the data part
void compute_chichi(int* input,
                    int* output){

                    
}


//compute the linear layer for element between start and end in the input
void compute_linear(int[] alpha,
                    int[] beta,
                    int* input,
                    int* output,
                    int start,
                    int end){



}

//round function of kiki
int* enc_big(
        int[] alpha,
        int[] beta,
        int[] delta,
        int[] gama,
        int* input){
                
    //the output is split in two part the first SIZE_DATA element are the state of the datapath
    //the last SIZE_TWEAK element are the state of the tweak schedule
    int* output = malloc(sizeof(int)*SIZE);

    for(int i=0;i<SIZE;i++)
        output[i] = 0;
        
    add_tweak(input,output);
    compute_chichi(output,input);
    compute_linear(alpha,beta,input,output,0,SIZE_DATA);
    compute_linear(delta,gama,output,input,SIZE_DATA,SIZE_TWEAK);

    free(output);
    
  return input;
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
  double max_weight = (double)H_SIZE-0.1;
  double max_ent = (double)SIZE-0.1;

  int max = H_SIZE;
  
  /* for(int R1=1;R1<max;R1++){ */
  /*   printf("R1 = %d \n",R1); */
  //for(int NL1=0;NL1<H_SIZE;NL1++){
  //for(int NL2=NL1+1;NL2<H_SIZE;NL2++){
  int NL1 = 0;
  int NL2 = 1;

  //read the liste of rotation value in the file poly_H_SIZE.txt
  //creat the name of the file
  char file_name[100];
  sprintf(file_name,"poly_%d.txt",H_SIZE);
  
  int size_list = 0;
  
  int** list = read_file(file_name,&size_list);

  char result_file_name[100];
  sprintf(result_file_name,"result_diffusion_%d.txt",H_SIZE);
  FILE* file = fopen(result_file_name,"w+");
  
  for(int index=1;index<size_list;index++){
    int L1 = list[index][0];
    int L2 = list[index][1];
    int L3 = list[index][2];
    //for(int L1=0;L1<max-2;L1++){
    //#pragma omp parallel num_threads(THREADS_NBR)
    //for(int L2=L1+1;L2<max-1;L2++){
    //#pragma omp parallel num_threads(THREADS_NBR)
    //for(int L3=L2+1;L3<max;L3++){
    //#pragma omp parallel num_threads(THREADS_NBR)
    for(int M=2;M<max;M++){
      //#pragma omp parallel num_threads(THREADS_NBR)
      for(int R1=1;R1<max;R1++){
	
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

/* //test a number of round with a number of sample = size_sample for SimonX (X>64) */
/* void test_big_simon(int nbr_round, */
/* 		    int size_sample){ */
  
/*   set_rotation(1,8,2,0,0,0,0); */
  
/*   struct matrix* m = test_dif_big(nbr_round, */
/* 			      SIZE, */
/* 			      enc_simon_big, */
/* 			      size_sample); */
	      
/*   double cur_dep = min_avalanche_dependence(m,size_sample); */
/*   double cur_weight = min_avalanche_weight(m,size_sample); */
/*   double cur_ent = min_avalanche_entropy(m,size_sample); */

/*   printf("for %d , (%d,%d), X^%d+X^%d+X^%d \n",R1,NL1,NL2,L1,L2,L3); */
/*   printf("the min avalanche dependence is %f, the min avalanche weight is %f, the min avalanche entropy is %f for %d round \n",cur_dep,cur_weight,cur_ent,nbr_round); */

/*   free_matrix(m); */

/* } */

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

/* //test for a set of number of round start from nbr_round_start to nbr_round_end the rotation value for SimonX  */
/* void test_full_round_simon(int size_sample, */
/* 			   int nbr_round_start, */
/* 			   int nbr_round_end){ */

/*   for(int i=nbr_round_start;i<nbr_round_end;i++){ */
    
/*     if(SIZE>64){ */
/*       //treat the case of big state */
/*       test_big_simon(i,size_sample); */
/*     }else{ */
/*       //the case of small state <64 */
/*       test_simon(i,size_sample); */
/*     } */
/*   } */
/* } */

int main(){

  int nbr_round = 6;
  if(SIZE<128)
    nbr_round = 6;
  
  int nbr_sample = 2000;
  
  test_all(nbr_round,nbr_sample);
  
  return 1;
}
