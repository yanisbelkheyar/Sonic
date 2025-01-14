#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define COYOTE_SIZE  64
#define H_COYOTE_SIZE  (COYOTE_SIZE/2)

/*in this file we will put all the function necessary to test
  for one type of theta all the rotation value possible
*/


void compute_dep(int **new_state_lin,
		 int **new_state_n_lin,
		 int p0,
		 int p1,
		 int p2,
		 int q0,
		 int q1,
		 int q2){

    
  /* printf("begin\n"); */
  /* for(int i=0;i<COYOTE_SIZE;i++) */
  /*   printf("%d ",new_state_n_lin[0][i]); */
  /* printf("\n"); */
  /* for(int i=0;i<COYOTE_SIZE;i++) */
  /*   printf("%d ",new_state_lin[0][i]); */
  /* printf("\n"); */
  
  int **old_state_lin = malloc(sizeof(int*)*COYOTE_SIZE);
  int **old_state_n_lin = malloc(sizeof(int*)*COYOTE_SIZE);
  for(int i=0;i<COYOTE_SIZE;i++){
    old_state_lin[i] = malloc(sizeof(int)*COYOTE_SIZE);
    old_state_n_lin[i] = malloc(sizeof(int)*COYOTE_SIZE);
    for(int j=0;j<COYOTE_SIZE;j++){
      old_state_lin[i][j] = new_state_lin[i][j];
      old_state_n_lin[i][j] = new_state_n_lin[i][j];
    }
  }
  
  //compute dependency for the left output
  for(int i=0;i<H_COYOTE_SIZE;i++){
    for(int j=0;j<COYOTE_SIZE;j++){
      //non linear dependency for the right output
      new_state_n_lin[i+H_COYOTE_SIZE][j] |=
	old_state_n_lin[i+q0 % H_COYOTE_SIZE][j]
	| old_state_n_lin[i+q1 % H_COYOTE_SIZE][j]
	| old_state_n_lin[i+q2 % H_COYOTE_SIZE][j];

      //linear dependency for the right output
      new_state_lin[i+H_COYOTE_SIZE][j] |=
	old_state_lin[i+q0 % H_COYOTE_SIZE][j]
	| old_state_lin[i+q1 % H_COYOTE_SIZE][j]
	| old_state_lin[i+q2 % H_COYOTE_SIZE][j];
      
      //non linear dependency for the left output
      new_state_n_lin[i][j] |=
	old_state_lin[i+p1 % H_COYOTE_SIZE][j]
	| old_state_lin[i+p2 % H_COYOTE_SIZE][j]
	| old_state_n_lin[i+p0 % H_COYOTE_SIZE][j]
	| old_state_n_lin[i+p1 % H_COYOTE_SIZE][j]
	| old_state_n_lin[i+p2 % H_COYOTE_SIZE][j]
	| old_state_n_lin[i+H_COYOTE_SIZE][j];

      //linear dependency for the left output
      new_state_lin[i][j] |=
	old_state_lin[i+p0 % H_COYOTE_SIZE][j]
	| old_state_lin[i+p1 % H_COYOTE_SIZE][j]
	| old_state_lin[i+p2 % H_COYOTE_SIZE][j]
	| old_state_lin[i+H_COYOTE_SIZE][j];
    }
  }


  for(int i=0;i<COYOTE_SIZE;i++)
    for(int j=0;j<COYOTE_SIZE;j++){
      old_state_lin[i][j] = new_state_lin[i][j];
      old_state_n_lin[i][j] = new_state_n_lin[i][j];
    }

  for(int i=0;i<COYOTE_SIZE;i++){
    free(old_state_lin[i]);
    free(old_state_n_lin[i]);
  }
  free(old_state_lin);
  free(old_state_n_lin);
}



void compute_dep_inv(int **new_state_lin,
		     int **new_state_n_lin,
		     int p0,
		     int p1,
		     int p2,
		     int nbr){

  int tab1[17] = {0,1,2,3,4,5,6,13,14,20,21,22,23,26,27,30,31};
  int tab2[17] = {0,1,2,3,4,11,12,17,18,19,23,24,26,27,29,30,31};
  int tab3[19] = {0,3,5,6,8,9,10,11,12,13,14,16,17,19,20,22,23,26,29};
  int tab4[13] = {3,6,8,9,10,11,13,14,17,23,25,27,31};
  int tab5[9] = {0,4,6,8,16,18,22,24,28};
  int tab6[19] = {0,1,2,3,5,7,8,10,13,15,18,19,20,23,24,25,28,29,30};

  /* printf("begin\n"); */
  /* for(int i=0;i<COYOTE_SIZE;i++) */
  /*   printf("%d ",new_state_n_lin[0][i]); */
  /* printf("\n"); */
  /* for(int i=0;i<COYOTE_SIZE;i++) */
  /*   printf("%d ",new_state_lin[0][i]); */
  /* printf("\n"); */
  
  int **old_state_lin = malloc(sizeof(int*)*COYOTE_SIZE);
  int **old_state_n_lin = malloc(sizeof(int*)*COYOTE_SIZE);
  for(int i=0;i<COYOTE_SIZE;i++){
    old_state_lin[i] = malloc(sizeof(int)*COYOTE_SIZE);
    old_state_n_lin[i] = malloc(sizeof(int)*COYOTE_SIZE);
    for(int j=0;j<COYOTE_SIZE;j++){
      old_state_lin[i][j] = new_state_lin[i][j];
      old_state_n_lin[i][j] = new_state_n_lin[i][j];
    }
  }
  
  //compute dependency for the left output
  for(int i=0;i<H_COYOTE_SIZE;i++){
    for(int j=0;j<COYOTE_SIZE;j++){

      if(nbr==1){
	for(int var=0;var<17;var++){
	  //non linear dependency for the right output
	  new_state_n_lin[i+H_COYOTE_SIZE][j] |=
	    old_state_n_lin[i+tab1[var] % H_COYOTE_SIZE][j];

	  //linear dependency for the right output
	  new_state_lin[i+H_COYOTE_SIZE][j] |=
	    old_state_lin[i+tab1[var] % H_COYOTE_SIZE][j];
	}
      }else if(nbr==2){
	for(int var=0;var<17;var++){
	  //non linear dependency for the right output
	  new_state_n_lin[i+H_COYOTE_SIZE][j] |=
	    old_state_n_lin[i+tab2[var] % H_COYOTE_SIZE][j];

	  //linear dependency for the right output
	  new_state_lin[i+H_COYOTE_SIZE][j] |=
	    old_state_lin[i+tab2[var] % H_COYOTE_SIZE][j];
	}
      }else if(nbr==3){
	for(int var=0;var<19;var++){
	  //non linear dependency for the right output
	  new_state_n_lin[i+H_COYOTE_SIZE][j] |=
	    old_state_n_lin[i+tab3[var] % H_COYOTE_SIZE][j];

	  //linear dependency for the right output
	  new_state_lin[i+H_COYOTE_SIZE][j] |=
	    old_state_lin[i+tab3[var] % H_COYOTE_SIZE][j];
	}
      }else if(nbr==4){
	for(int var=0;var<13;var++){
	  //non linear dependency for the right output
	  new_state_n_lin[i+H_COYOTE_SIZE][j] |=
	    old_state_n_lin[i+tab4[var] % H_COYOTE_SIZE][j];

	  //linear dependency for the right output
	  new_state_lin[i+H_COYOTE_SIZE][j] |=
	    old_state_lin[i+tab4[var] % H_COYOTE_SIZE][j];
	}
      }else if(nbr==5){
	for(int var=0;var<9;var++){
	  //non linear dependency for the right output
	  new_state_n_lin[i+H_COYOTE_SIZE][j] |=
	    old_state_n_lin[i+tab5[var] % H_COYOTE_SIZE][j];

	  //linear dependency for the right output
	  new_state_lin[i+H_COYOTE_SIZE][j] |=
	    old_state_lin[i+tab5[var] % H_COYOTE_SIZE][j];
	}
      }else if(nbr==6){
	for(int var=0;var<19;var++){
	  //non linear dependency for the right output
	  new_state_n_lin[i+H_COYOTE_SIZE][j] |=
	    old_state_n_lin[i+tab6[var] % H_COYOTE_SIZE][j];

	  //linear dependency for the right output
	  new_state_lin[i+H_COYOTE_SIZE][j] |=
	    old_state_lin[i+tab6[var] % H_COYOTE_SIZE][j];
	}
      }
      
      //non linear dependency for the left output
      new_state_n_lin[i][j] |=
	old_state_lin[i+p1 % H_COYOTE_SIZE][j]
	| old_state_lin[i+p2 % H_COYOTE_SIZE][j]
	| old_state_n_lin[i+p0 % H_COYOTE_SIZE][j]
	| old_state_n_lin[i+p1 % H_COYOTE_SIZE][j]
	| old_state_n_lin[i+p2 % H_COYOTE_SIZE][j]
	| old_state_n_lin[i+H_COYOTE_SIZE][j];

      //linear dependency for the left output
      new_state_lin[i][j] |=
	old_state_lin[i+p0 % H_COYOTE_SIZE][j]
	| old_state_lin[i+p1 % H_COYOTE_SIZE][j]
	| old_state_lin[i+p2 % H_COYOTE_SIZE][j]
	| old_state_lin[i+H_COYOTE_SIZE][j];
    }
  }


  for(int i=0;i<COYOTE_SIZE;i++)
    for(int j=0;j<COYOTE_SIZE;j++){
      old_state_lin[i][j] = new_state_lin[i][j];
      old_state_n_lin[i][j] = new_state_n_lin[i][j];
    }

  for(int i=0;i<COYOTE_SIZE;i++){
    free(old_state_lin[i]);
    free(old_state_n_lin[i]);
  }
  free(old_state_lin);
  free(old_state_n_lin);
    
}


int test_full_dep(int **state){
  for(int i=0;i<COYOTE_SIZE;i++){
    int nbr_var=0;
    for(int j=0;j<COYOTE_SIZE;j++)
      nbr_var+=state[i][j];
    if(nbr_var!=COYOTE_SIZE)
      return nbr_var;
  }
  return -1;
}

//test for all possible rotation value if the dependency criteria is fufill 
void test_param(){

  int **new_state_lin = malloc(sizeof(int*)*COYOTE_SIZE);
  int **new_state_n_lin = malloc(sizeof(int*)*COYOTE_SIZE);
  //int **old_state = malloc(sizeof(int*)*COYOTE_SIZE);
  for(int i=0;i<COYOTE_SIZE;i++){
    new_state_lin[i] = malloc(sizeof(int)*COYOTE_SIZE);
    new_state_n_lin[i] = malloc(sizeof(int)*COYOTE_SIZE);
    //old_state[i] = malloc(sizeof(int)*COYOTE_SIZE);
  }

  int **new_state_lin_inv = malloc(sizeof(int*)*COYOTE_SIZE);
  int **new_state_n_lin_inv = malloc(sizeof(int*)*COYOTE_SIZE);
  //int **old_state = malloc(sizeof(int*)*COYOTE_SIZE);
  for(int i=0;i<COYOTE_SIZE;i++){
    new_state_lin_inv[i] = malloc(sizeof(int)*COYOTE_SIZE);
    new_state_n_lin_inv[i] = malloc(sizeof(int)*COYOTE_SIZE);
    //old_state[i] = malloc(sizeof(int)*COYOTE_SIZE);
  }

  int tot_good = 0;
  int min_round = 20;
  
  //test all the possible shuffle row

  /* for(int p0=1;p0<H_COYOTE_SIZE;p0++){ */
  /*   for(int p1=1;p1<H_COYOTE_SIZE;p1++){ */
  /*     for(int p2=p1+1;p2<H_COYOTE_SIZE;p2++){ */
  /* 	for(int q0=0;q0<H_COYOTE_SIZE;q0++){ */
  /* 	  for(int q1=q0+1;q1<H_COYOTE_SIZE;q1++){ */
  /* 	    for(int q2=q1+1;q2<H_COYOTE_SIZE;q2++){ */
	      
      			   
  /* 	      for(int i=0;i<COYOTE_SIZE;i++){ */
  /* 		for(int j=0;j<COYOTE_SIZE;j++){ */
  /* 		  if(i==j) */
  /* 		    new_state_lin[i][j] = 1; */
  /* 		  else  */
  /* 		    new_state_lin[i][j] = 0; */
  /* 		  new_state_n_lin[i][j] = 0; */
  /* 		} */
  /* 	      } */

  /* 	      int nbr_round = 6; */
	      
  /* 	      //check the number of round to acheive full dif */
  /* 	      for(int round=0;round<nbr_round;round++){ */
  /* 		//printf("round %d\n",round); */
  /* 		compute_dep(new_state_lin,new_state_n_lin,p0,p1,p2,q0,q1,q2); */
  /* 		//compute_dep_inv(new_state_lin_inv,new_state_n_lin_inv,p0,p1,p2,q0,q1,q2); */
  /* 		//check for full dependency */
  /* 	      } */
				
  /* 	      int res = test_full_dep(new_state_n_lin); */

  /* 	      //printf("%d,(%d,%d), X^%d+X^%d+X^%d : %d round : dif = %d \n",p0,p1,p2,q0,q1,q2,nbr_round,res); */
  /* 	      //int res1 = test_full_dep(new_state_n_lin_inv); */
				
  /* 	      //printf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n",SR1,SR2,SR3,SR4,RR1,RR2,RR3,p1,q1,r1, res); */

  /* 	      if(res==-1){ //&& res1==-1){ */
  /* 		/\* if(res==-1 && round<min_round){ *\/ */
  /* 		/\*   if(round<min_round){ *\/ */
  /* 		/\*     tot_good=0; *\/ */
  /* 		/\*     min_round = round; *\/ */
  /* 		/\*     //printf("%d round \n",round); *\/ */
  /* 		/\*   } *\/ */
  /* 		tot_good++; */
  /* 		//printf("%d round \n",round); */
				
  /* 		printf("%d,(%d,%d), X^%d+X^%d+X^%d full dif in %d round\n",p0,p1,p2,q0,q1,q2,nbr_round); */
  /* 		/\* */
  /* 		  for(int i=0;i<COYOTE_SIZE;i++){ */
  /* 		  for(int j=0;j<COYOTE_SIZE;j++) */
  /* 		  printf("%d ",new_state[i][j]); */
  /* 		  printf("\n"); */
  /* 		  } */
  /* 		*\/ */
  /* 	      } */
  /* 	      //printf("max dependency after 28 round is %d\n",r); */
  /* 	    } */
  /* 	  } */
  /* 	} */
  /*     } */
  /*   } */
  /* } */

  printf("coucou \n");

  int tab[18] = {1,3,28,4,11,13,16,1,4,25,1,3,27,1,4,27,1,11};
  
  for(int pos=0;pos<6;pos++){

    for(int i=0;i<COYOTE_SIZE;i++){
      for(int j=0;j<COYOTE_SIZE;j++){
	if(i==j)
	  new_state_lin[i][j] = 1;
	else 
	  new_state_lin[i][j] = 0;
	new_state_n_lin[i][j] = 0;
      }
    }

    int nbr_round = 5;

    printf("test for %d,(%d,%d), inv nbr %d \n",tab[pos*3],tab[pos*3+1],tab[pos*3+2],pos);
    //check the number of round to acheive full dif
    for(int round=0;round<nbr_round;round++){
      //printf("round %d\n",round);
      compute_dep_inv(new_state_lin,new_state_n_lin,tab[pos*3],tab[pos*3+1],tab[pos*3+2],pos);
      //compute_dep_inv(new_state_lin_inv,new_state_n_lin_inv,p0,p1,p2,q0,q1,q2);
      //check for full dependency
    }
				
    int res = test_full_dep(new_state_n_lin);

    //printf("%d,(%d,%d), X^%d+X^%d+X^%d : %d round : dif = %d \n",p0,p1,p2,q0,q1,q2,nbr_round,res);
    //int res1 = test_full_dep(new_state_n_lin_inv);
				
    //printf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n",SR1,SR2,SR3,SR4,RR1,RR2,RR3,p1,q1,r1, res);

    if(res==-1){ //&& res1==-1){
      /* if(res==-1 && round<min_round){ */
      /*   if(round<min_round){ */
      /*     tot_good=0; */
      /*     min_round = round; */
      /*     //printf("%d round \n",round); */
      /*   } */
      tot_good++;
      //printf("%d round \n",round);
				
      printf("%d,(%d,%d), inv nbr %d full dif in %d round\n",tab[pos*3],tab[pos*3+1],tab[pos*3+2],pos,nbr_round);
      /*
	for(int i=0;i<COYOTE_SIZE;i++){
	for(int j=0;j<COYOTE_SIZE;j++)
	printf("%d ",new_state[i][j]);
	printf("\n");
	}
      */
    }
  }

  double ratio = (tot_good/(H_COYOTE_SIZE*H_COYOTE_SIZE*H_COYOTE_SIZE*H_COYOTE_SIZE*H_COYOTE_SIZE*H_COYOTE_SIZE));
  
  //printf("tot_good = %d , ratio good = %f \n",tot_good,ratio);
  free(new_state_lin);
  free(new_state_n_lin);
  free(new_state_lin_inv);
  free(new_state_n_lin_inv);
}



int main(){
  
  printf("patate\n");
  
  test_param();

  return 1;
}
