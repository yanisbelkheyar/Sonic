#include "diffusion_test.h"
#include <math.h>
#include <omp.h>

#define THREADS_NBR 10

struct matrix* init_matrix(int size, struct matrix* m){
  m = malloc(sizeof(struct matrix));
  m->size = size;
  m->proba = malloc(size * sizeof(double*));
  for(int i = 0; i < size; i++){
    m->proba[i] = malloc(size * sizeof(double));
    for(int j = 0; j < size; j++){
      m->proba[i][j] = 0;
    }
  }

  return m;
}

void free_matrix(struct matrix* m){
  for(int i = 0; i < m->size; i++){
    free(m->proba[i]);
  }
  free(m->proba);
  free(m);
}


void print_matrix(struct matrix* m){
  for(int i = 0; i < m->size; i++){
    for(int j = 0; j < m->size; j++){
      printf("%.3f ", m->proba[i][j]);
    }
    printf("\n");
  }
}


struct matrix* test_dif_big_simon(int nbr_round,
			    int size,
			    int* f(int*),
			    int size_sample){

  struct matrix* m = init_matrix(size, m);

  int** sample = malloc(size_sample * sizeof(int*));
  for(int i = 0; i < size_sample; i++){
    sample[i] = malloc(sizeof(int)*size);
    for(int j=0;j<size;j++)
      sample[i][j] = rand()%2;
  }

  for(int i = 0; i < size_sample; i++){
    int* x = malloc(sizeof(int)*size);
    int* dx = malloc(sizeof(int)*size);
    int* lx = malloc(sizeof(int)*size);

    for(int j=0;j<size;j++){
      x[j] = sample[i][j];
      //dx[j] = sample[i][j];
      lx[j] = sample[i][j];
    }
    //dx[0] ^= 1;
    //difference in the left side
    lx[size-1] ^= 1;
    //difference in the right side
    //lx[1] ^= 1;
          
    for(int j = 0; j < nbr_round; j++){
      x = f(x);
      //dx = f(dx);
      lx = f(lx);
    }
    
    for(int j=0;j<size;j++){
      //m->proba[0][j] += x[j] ^ dx[j];
      m->proba[size-1][j] += x[j] ^ lx[j];

    }
      
    free(x);
    free(dx);
    free(lx);  
  }  

  for(int i=0;i<size_sample;i++)
    free(sample[i]);
  free(sample);

  return m;
}


struct matrix* test_dif(int nbr_round,
			int size,
			uint64_t f(int,int,int,int,int,int,int,uint64_t),
			int NL1,
			int NL2,
			int R1,
			int L1,
			int L2,
			int L3,
			int M,
			int size_sample){

  struct matrix* m = init_matrix(size, m);

  uint64_t* sample = malloc(size_sample * sizeof(uint64_t));
  for(int i = 0; i < size_sample; i++){
    sample[i] = rand();
  }
  
  for(int i = 0; i < size_sample; i++){
    
    uint64_t x = sample[i];
      
    //uint64_t dx = sample[i] ^ (uint64_t)1; 
    uint64_t lx = sample[i] ^ (uint64_t)1<<(size-1);
      
    for(int j = 0; j < nbr_round; j++){
      x = f(NL1,NL2,R1,L1,L2,L3,M,x);
      //dx = f(dx);
      lx = f(NL1,NL2,R1,L1,L2,L3,M,lx);
    }
      
    for(int posj=0;posj<size;posj++){
      //m->proba[0][posj] += ((x >> posj) & 1) ^ ((dx >> posj) & 1);
      m->proba[size-1][posj] += ((x >> posj) & 1) ^ ((lx >> posj) & 1);
    }
  }  
  
  free(sample);

  return m;
}

struct matrix* test_dif_big(int nbr_round,
			    int size,
			    int* f(int,int,int,int,int,int,int,int*),
			    int NL1,
			    int NL2,
			    int R1,
			    int L1,
			    int L2,
			    int L3,
			    int M,
			    int size_sample){

  struct matrix* m = init_matrix(size, m);

  int** sample = malloc(size_sample * sizeof(int*));
  for(int i = 0; i < size_sample; i++){
    sample[i] = malloc(sizeof(int)*size);
    for(int j=0;j<size;j++)
      sample[i][j] = rand()%2;
  }

  for(int i = 0; i < size_sample; i++){
    int* x = malloc(sizeof(int)*size);
    int* dx = malloc(sizeof(int)*size);
    int* lx = malloc(sizeof(int)*size);

    for(int j=0;j<size;j++){
      x[j] = sample[i][j];
      //dx[j] = sample[i][j];
      lx[j] = sample[i][j];
    }
    //dx[0] ^= 1;
    //difference in the left side
    //lx[size-1] ^= 1;
    //difference in the right side
    lx[1] ^= 1;
          
    for(int j = 0; j < nbr_round; j++){
      x = f(NL1,NL2,R1,L1,L2,L3,M,x);
      //dx = f(dx);
      lx = f(NL1,NL2,R1,L1,L2,L3,M,lx);
    }
    
    for(int j=0;j<size;j++){
      //m->proba[0][j] += x[j] ^ dx[j];
      m->proba[size-1][j] += x[j] ^ lx[j];

    }
      
    free(x);
    free(dx);
    free(lx);  
  }  

  for(int i=0;i<size_sample;i++)
    free(sample[i]);
  free(sample);

  return m;
}



double min_avalanche_dependence(struct matrix* m,
				int size_sample){
  double min = m->size;
  for(int i = m->size-1; i < m->size ; i++){
    double sum = 0;
    for(int j = 0; j < m->size; j++){
      sum += (m->proba[i][j]==0)?1:0;
    }
    sum = m->size - sum;

    if(sum < min){
      min = sum;
    }
  }
  return min;
}


double min_avalanche_weight(struct matrix* m,
			    int size_sample){

  double min = m->size;
  for(int i = m->size -1; i < m->size; i++){
    double sum = 0;
    for(int j = 0; j < m->size; j++){
      sum += m->proba[i][j];
    }
    sum /= size_sample;
    
    if(sum < min){
      min = sum;
    }
  }
  
  return min;
}


double min_avalanche_entropy(struct matrix* m,
			     int size_sample){

  double inf = 1.0/0.0;
  
  double min = m->size;
  for(int i = m->size-1; i < m->size; i++){
    double sum = 0;
    for(int j = 0; j < m->size; j++){

      double log_1 = 0;
      double log_2 = 0;
      if(log2(m->proba[i][j]/size_sample)!=-inf)	
	log_1 = log2(m->proba[i][j]/size_sample);
      if(log2(1-(m->proba[i][j]/size_sample))!=-inf)
	log_2 = log2(1-(m->proba[i][j]/size_sample));
      
      sum += -((m->proba[i][j]/size_sample) * log_1) - ((1-( m->proba[i][j]/size_sample)) * log_2);
    }
    if(sum < min){
      min = sum;
    }
  }
  
  return min;
}
