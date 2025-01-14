#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include <omp.h>
#define THREADS_NBR 7

#include "check_compatibility.h"

#define shift1 0
#define shift2 1
#define shift3 5

#define PRINT 0

#define one(x,i) ((x>>i)&1)
#define M 15
#define IM 111

void PI(int mul_shuffle,state* s){

    state* res = malloc(sizeof(state));
    res->data_64 = malloc(sizeof(uint64_t)*s->size_64);
    res->size_64 = s->size_64;

    int size = s->size_64*64;
    for(int i=0;i<s->size_64;i++){
        res->data_64[i] = (uint64_t)0;
        for(int j=0;j<64;j++){
            int idx = (((i*64+j)*mul_shuffle)%size);
            res->data_64[i] ^= (uint64_t)(((s->data_64[idx/64]>>(idx%64)) & (uint64_t)1)<<j);
        }
    }
    for(int i=0;i<s->size_64;i++)
        s->data_64[i] = res->data_64[i];

    free(res->data_64);
    free(res);
}

void THETA_old(state* s1){

    state* tmp = malloc(sizeof(state));
    tmp->size_64 = s1->size_64;
    tmp->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);
    
    state* tmp1 = malloc(sizeof(state));
    tmp1->size_64 = s1->size_64;
    tmp1->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);


    shift(8,s1,tmp);
    shift(10,s1,tmp1);
    XOR(s1,tmp);
    XOR(s1,tmp1);

    free(tmp->data_64);
    free(tmp1->data_64);
    free(tmp);
    free(tmp1);

}

void THETA(state* s1){
    state* tmp = malloc(sizeof(state));
    tmp->size_64 = s1->size_64;
    tmp->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);
    
    state* tmp1 = malloc(sizeof(state));
    tmp1->size_64 = s1->size_64;
    tmp1->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);


    shift(7,s1,tmp);
    shift(32,s1,tmp1);
    XOR(s1,tmp);
    XOR(s1,tmp1);

    free(tmp->data_64);
    free(tmp1->data_64);
    free(tmp);
    free(tmp1);
}

void THETA256_inv_old(state* left){

    state* tmp = malloc(sizeof(state));
    tmp->size_64 = left->size_64;
    tmp->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);

    state* tmp1 = malloc(sizeof(state));
    tmp1->size_64 = left->size_64;
    tmp1->data_64 = malloc(sizeof(uint64_t)*tmp1->size_64);
    
    shift(10,left,tmp);
    shift(8,left,tmp1);
    XOR(tmp,tmp1);
    XOR(left,tmp);

    shift(20,left,tmp);
    shift(16,left,tmp1);
    XOR(tmp,tmp1);
    XOR(left,tmp);

    shift(40,left,tmp);
    shift(32,left,tmp1);
    XOR(tmp,tmp1);
    XOR(left,tmp);

    shift(80,left,tmp);
    shift(64,left,tmp1);
    XOR(tmp,tmp1);
    XOR(left,tmp);

    shift(96,left,tmp);
    copy(tmp,left);

    free(tmp->data_64);
    free(tmp1->data_64);
    free(tmp);
    free(tmp1);

}


void THETA256_inv(state* left){

    state* tmp = malloc(sizeof(state));
    tmp->size_64 = left->size_64;
    tmp->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);

    state* tmp1 = malloc(sizeof(state));
    tmp1->size_64 = left->size_64;
    tmp1->data_64 = malloc(sizeof(uint64_t)*tmp1->size_64);
    
    shift(32,left,tmp);
    shift(7,left,tmp1);
    XOR(tmp,tmp1);
    XOR(left,tmp);

    shift(14,left,tmp);
    shift(64,left,tmp1);
    XOR(tmp,tmp1);
    XOR(left,tmp);

    /*
    shift(28,left,tmp);
    shift(56,tmp,left);

    shift(112,left,tmp);
    shift(96,tmp,left);

    shift(64,left,tmp);
    */
   shift(100,left,tmp);
    copy(tmp,left);

    free(tmp->data_64);
    free(tmp1->data_64);
    free(tmp);
    free(tmp1);

}

//generate for a fixe paire of difference alpha beta, the corresponding 
//following differences and verify if they are compatible
int valid_4_round_trail(state* alpha,state* beta, state* Ar,state* Al,state* Br,state* Bl){


    state* delta_3_l = malloc(sizeof(state));
    delta_3_l->data_64 = malloc(sizeof(uint64_t)*alpha->size_64);
    delta_3_l->size_64 = alpha->size_64;

    state* delta_3_r = malloc(sizeof(state));
    delta_3_r->data_64 = malloc(sizeof(uint64_t)*alpha->size_64);
    delta_3_r->size_64 = alpha->size_64;

    state* delta_4_l = malloc(sizeof(state));
    delta_4_l->data_64 = malloc(sizeof(uint64_t)*alpha->size_64);
    delta_4_l->size_64 = alpha->size_64;

    state* delta_4_r = malloc(sizeof(state));
    delta_4_r->data_64 = malloc(sizeof(uint64_t)*alpha->size_64);
    delta_4_r->size_64 = alpha->size_64;

    //for delta 4 r
    copy(Br,delta_4_r);

    //for delta 3 l
    copy(Al,delta_3_l);
    THETA(delta_3_l);
    PI(M,Al);
    XOR(delta_3_l,beta);
    PI(M,delta_3_l);

    //for delta 3 r
    copy(alpha,delta_3_r);
    XOR(delta_3_r,Ar);
    PI(M,delta_3_r);
    THETA(delta_3_r);
    PI(M,delta_3_r);
    //value for state size = 256
    PI(225,Br);
    XOR(delta_3_r,Br);

    //for delta 4 l
    copy(Al,delta_4_l);
    THETA(delta_4_l);
    PI(M,delta_4_l);
    XOR(delta_4_l,beta);
    THETA(delta_4_l);
    PI(M,delta_4_l);
    XOR(delta_4_l,Bl);

    int res = in(delta_3_r,delta_3_l,shift1,shift2,shift3) & in(delta_4_l,delta_4_r,shift1,shift2,shift3);

    free(delta_3_l->data_64);
    free(delta_3_r->data_64);
    free(delta_4_l->data_64);
    free(delta_4_r->data_64);
    free(delta_3_l);
    free(delta_3_r);
    free(delta_4_l);
    free(delta_4_r);

    //maybe there is something smarter to do her to reduce the complexity and cut some search ?
    return res;
}


//generate for a fixe paire of difference alpha beta, the corresponding 
//following differences and verify if they are compatible
int valid_3_round_trail(state* alpha, state* Ar,state* Al,state* Br,state* Bl){

    state* delta_2_l = malloc(sizeof(state));
    delta_2_l->data_64 = malloc(sizeof(uint64_t)*alpha->size_64);
    delta_2_l->size_64 = alpha->size_64;
    XOR(delta_2_l,delta_2_l);

    state* delta_2_r = malloc(sizeof(state));
    delta_2_r->data_64 = malloc(sizeof(uint64_t)*alpha->size_64);
    delta_2_r->size_64 = alpha->size_64;
    XOR(delta_2_r,delta_2_r);

    state* delta_3_l = malloc(sizeof(state));
    delta_3_l->data_64 = malloc(sizeof(uint64_t)*alpha->size_64);
    delta_3_l->size_64 = alpha->size_64;
    XOR(delta_3_l,delta_3_l);

    state* delta_3_r = malloc(sizeof(state));
    delta_3_r->data_64 = malloc(sizeof(uint64_t)*alpha->size_64);
    delta_3_r->size_64 = alpha->size_64;
    XOR(delta_3_r,delta_3_r);

    state* tmp = malloc(sizeof(state));
    tmp->size_64 = alpha->size_64;
    tmp->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);
    XOR(tmp,tmp);

    
    state* tmp1 = malloc(sizeof(state));
    tmp1->size_64 = alpha->size_64;
    tmp1->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);
    XOR(tmp1,tmp1);

    state* tmp2 = malloc(sizeof(state));
    tmp2->size_64 = alpha->size_64;
    tmp2->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);
    XOR(tmp2,tmp2);

    state* tmp3 = malloc(sizeof(state));
    tmp3->size_64 = alpha->size_64;
    tmp3->data_64 = malloc(sizeof(uint64_t)*tmp->size_64);
    XOR(tmp3,tmp3);
    
    //for delta 3 l
    copy(Bl,delta_3_l);
    PI(IM,delta_3_l);
    THETA256_inv(delta_3_l);

    //for delta 2 r
    copy(alpha,delta_2_r);
    XOR(delta_2_r,Ar);
    //copy(delta_2_r,tmp1);
    PI(M,delta_2_r);

    //for delta 2 l
    copy(Al,delta_2_l);
    THETA(delta_2_l);
    PI(M,delta_2_l);
    copy(delta_3_l,tmp);
    PI(IM,tmp);
    XOR(delta_2_l,tmp);

    //for delta 3 r
    copy(delta_2_r,delta_3_r);
    THETA(delta_3_r);
    //copy(delta_3_r,tmp2);
    PI(M,delta_3_r);
    //copy(delta_3_r,tmp3);
    XOR(tmp,tmp);
    copy(Br,tmp);
    PI(IM,tmp);
    XOR(delta_3_r,tmp);

    int res = in(delta_2_l,delta_2_r,shift1,shift2,shift3) & in(delta_3_r,delta_3_l,shift1,shift2,shift3);

    if(res==1 && PRINT){
        //printf("input \n");

        //print_bin(Al);
        //printf(" ");
        //print_bin(Ar);
        //printf("\n");
        /*
        printf("%lx ",Al->data_64[0]);
        printf("%lx ",Al->data_64[1]);
        printf("%lx ",Ar->data_64[0]);
        printf("%lx \n",Ar->data_64[1]);
        */
        print_bin(alpha);
        printf("\n");
        printf("alpha = %lx %lx\n",alpha->data_64[0],alpha->data_64[1]);
        print_bin(delta_2_l);
        printf(" ");
        print_bin(tmp1);
        printf("\n");
        printf("input to F2 = %lx %lx\n",delta_2_r->data_64[0],delta_2_r->data_64[1]);
        print_bin(delta_2_r);
        printf("\n");
        printf("output F2 = %lx %lx \n",delta_2_l->data_64[0],delta_2_l->data_64[1]);
        print_bin(delta_3_l);
        printf(" ");
        print_bin(tmp2);
        printf("\n");
        print_bin(tmp3);
        printf("\n");
        printf("input to F3 = %lx %lx \n",delta_3_l->data_64[0],delta_3_l->data_64[1]);
        print_bin(delta_3_r);
        printf("\n");
        printf("\n\n");
        printf("output F3 = %lx %lx \n",delta_3_r->data_64[0],delta_3_r->data_64[1]);

        print_bin(Bl);
        printf(" ");
        print_bin(Br);
        printf("\noutput");

        /*
        printf("%lx ",Bl->data_64[0]);
        printf("%lx ",Bl->data_64[1]);
        printf("%lx ",Br->data_64[0]);
        printf("%lx \n\n",Br->data_64[1]);
        */
        printf(" 3 l in 3 r = %d, 4 r in 4 l = %d\n\n",in(delta_2_l,delta_2_r,shift1,shift2,shift3),in(delta_3_r,delta_3_l,shift1,shift2,shift3));
    }

    free(tmp1->data_64);
    free(tmp2->data_64);
    free(tmp3->data_64);
    free(delta_3_l->data_64);
    free(delta_3_r->data_64);
    free(delta_2_l->data_64);
    free(delta_2_r->data_64);
    free(tmp->data_64);
    free(delta_3_l);
    free(delta_3_r);
    free(delta_2_l);
    free(delta_2_r);
    free(tmp);
    free(tmp1);
    free(tmp2);
    free(tmp3);

    //maybe there is something smarter to do her to reduce the complexity and cut some search ?
    return res;
}


//compute for a differential, the number of 4 round trail with the same input output difference
int clusterring_4_round(state* Ar,state* Al,state* Br,state* Bl){

    //first generate all possible alpha's such that alpha is an output difference in F(Al)
    state** basis_alpha = malloc(sizeof(state*)*256);
    state* offset_alpha = malloc(sizeof(state));
    offset_alpha->data_64 = malloc(sizeof(uint64_t)*Ar->size_64);
    offset_alpha->size_64 = Ar->size_64;
    int size_basis_alpha = generate_basis(Al,basis_alpha,offset_alpha,shift1,shift2,shift3);

    if(PRINT==0){
        printf("size basis alpha = %d\n",size_basis_alpha);
        printf("offset %lx %lx \n",offset_alpha->data_64[0],offset_alpha->data_64[1]);
        for(int i=0;i<size_basis_alpha;i++)
            printf("basis vector %lx %lx\n",basis_alpha[i]->data_64[0],basis_alpha[i]->data_64[1]);
        }
    state** basis_beta = malloc(sizeof(state*)*256);
    state* offset_beta = malloc(sizeof(state));
    offset_beta->data_64 = malloc(sizeof(uint64_t)*Ar->size_64);
    offset_beta->size_64 = Ar->size_64;

    state* alpha = malloc(sizeof(state));
    alpha->data_64 = malloc(sizeof(uint64_t)*Ar->size_64);
    alpha->size_64 = Ar->size_64;


    state* beta = malloc(sizeof(state));
    beta->data_64 = malloc(sizeof(uint64_t)*Ar->size_64);
    beta->size_64 = Ar->size_64;

    state* tmp = malloc(sizeof(state));
    tmp->data_64 = malloc(sizeof(uint64_t)*Ar->size_64);
    tmp->size_64 = Ar->size_64;

    copy(Ar,tmp);

    int nbr_trail = 0;
    int size_basis_beta = 0;

    //for each possible alpha's:
    for(int i=0;i<((uint64_t)1<<size_basis_alpha);i++){
        XOR(alpha,alpha);
        alpha = vectore_from_basis(basis_alpha,size_basis_alpha,offset_alpha,i,alpha);
        //printf("alpha %lx %lx\n",alpha->data_64[0],alpha->data_64[1]);

        XOR(tmp,alpha);
        PI(M,tmp);        

        size_basis_beta = generate_basis(tmp,basis_beta,offset_beta,shift1,shift2,shift3);
        if(PRINT){
        printf("size basis beta = %d\n",size_basis_beta);
        printf("offset %lx %lx \n",offset_beta->data_64[0],offset_beta->data_64[1]);
        for(int i=0;i<size_basis_beta;i++)
            printf("basis vector %lx %lx\n",basis_beta[i]->data_64[0],basis_beta[i]->data_64[1]);
        }
        for(int j=0;j<(uint64_t)1<<size_basis_beta;j++){
            XOR(beta,beta);
            beta = vectore_from_basis(basis_beta,size_basis_beta,offset_beta,j,beta);
            //printf("beta %lx %lx\n",beta->data_64[0],beta->data_64[1]);

            nbr_trail += valid_4_round_trail(alpha,beta,Ar,Al,Br,Bl);
        }

    }

    for(int i=0;i<size_basis_alpha;i++){
        free(basis_alpha[i]->data_64);
        free(basis_alpha[i]);
    }

    for(int i=0;i<size_basis_beta;i++){
        free(basis_beta[i]->data_64);
        free(basis_beta[i]);
    }

    free(alpha->data_64);
    free(beta->data_64);
    free(tmp->data_64);
    free(offset_alpha->data_64);
    free(offset_beta->data_64);
    free(basis_alpha);
    free(basis_beta);
    free(alpha);
    free(beta);
    free(tmp);
    free(offset_alpha);
    free(offset_beta);

    return nbr_trail;
}

//compute for a differential, the number of 4 round trail with the same input output difference
int clusterring_3_round(state* Ar,state* Al,state* Br,state* Bl){


    //first generate all possible alpha's such that alpha is an output difference in F(Al)
    state** basis_alpha = malloc(sizeof(state*)*256);
    state* offset_alpha = malloc(sizeof(state));
    offset_alpha->data_64 = malloc(sizeof(uint64_t)*Ar->size_64);
    offset_alpha->size_64 = Ar->size_64;
    XOR(offset_alpha,offset_alpha);
    int size_basis_alpha = generate_basis(Al,basis_alpha,offset_alpha,shift1,shift2,shift3);

    state* alpha = malloc(sizeof(state));
    alpha->data_64 = malloc(sizeof(uint64_t)*Ar->size_64);
    alpha->size_64 = Ar->size_64;

    int nbr_trail = 0;

    //for each possible alpha's:
    for(int i=0;i<((uint64_t)1<<size_basis_alpha);i++){
        XOR(alpha,alpha);
        alpha = vectore_from_basis(basis_alpha,size_basis_alpha,offset_alpha,i,alpha);

        nbr_trail += valid_3_round_trail(alpha,Ar,Al,Br,Bl);

    }

    for(int i=0;i<size_basis_alpha;i++){
        free(basis_alpha[i]->data_64);
        free(basis_alpha[i]);
    }

    free(alpha->data_64);
    free(offset_alpha->data_64);
    free(basis_alpha);
    free(alpha);
    free(offset_alpha);

    return nbr_trail;
}

//for a specific input difference, generate a 3 round trail
void generate_3_round_trail(state* Ar,state* Al,state* Br,state* Bl){

    XOR(Br,Br);
    XOR(Bl,Bl);

    state** basis = malloc(sizeof(state*)*256);
    state* offset = malloc(sizeof(state));
    offset->data_64 = malloc(sizeof(uint64_t)*Ar->size_64);
    offset->size_64 = Ar->size_64;
    int size_basis = generate_basis(Al,basis,offset,shift1,shift2,shift3);

    
    if(PRINT){
        printf("size basis alpha = %d\n",size_basis);
        
        printf("offset %lx %lx \n",offset->data_64[0],offset->data_64[1]);
        for(int i=0;i<size_basis;i++)
            printf("basis vector %lx %lx\n",basis[i]->data_64[0],basis[i]->data_64[1]);
    }

    state* alpha = malloc(sizeof(state));
    alpha->data_64 = malloc(sizeof(uint64_t)*Ar->size_64);
    alpha->size_64 = Ar->size_64;
    XOR(alpha,alpha);

    state* beta = malloc(sizeof(state));
    beta->data_64 = malloc(sizeof(uint64_t)*Ar->size_64);
    beta->size_64 = Ar->size_64;
    XOR(beta,beta);

    state* delta = malloc(sizeof(state));
    delta->data_64 = malloc(sizeof(uint64_t)*Ar->size_64);
    delta->size_64 = Ar->size_64;
    XOR(delta,delta);

    state* tmp = malloc(sizeof(state));
    tmp->data_64 = malloc(sizeof(uint64_t)*Ar->size_64);
    tmp->size_64 = Ar->size_64;
    XOR(tmp,tmp);

    int vec = rand() % ((uint64_t)1<<size_basis);

    alpha = vectore_from_basis(basis,size_basis,offset,vec,alpha);

    if(PRINT){
        printf("a\n");
        printf("alpha = %lx %lx\n",alpha->data_64[0],alpha->data_64[1]);
    }

    XOR(alpha,Ar);
    PI(M,alpha);
    if(PRINT)
        printf("input to F2 = %lx %lx\n",alpha->data_64[0],alpha->data_64[1]);

    size_basis = generate_basis(alpha,basis,offset,shift1,shift2,shift3);
    /*
    if(PRINT){
        printf("size basis beta = %d\n",size_basis);
        
        printf("offset %lx %lx \n",offset->data_64[0],offset->data_64[1]);
        for(int i=0;i<size_basis;i++)
            printf("basis vector %lx %lx\n",basis[i]->data_64[0],basis[i]->data_64[1]);
    }
    */
    vec = rand() % ((uint64_t)1<<size_basis);

    beta = vectore_from_basis(basis,size_basis,offset,vec,beta);
    if(PRINT)
        printf("output F2 = %lx %lx \n",beta->data_64[0],beta->data_64[1]);

    copy(Al,tmp);
    THETA(tmp);
    PI(M,tmp);
    XOR(beta,tmp);
    PI(M,beta);
    if(PRINT)
        printf("input to F3 = %lx %lx \n",beta->data_64[0],beta->data_64[1]);

    size_basis = generate_basis(beta,basis,offset,shift1,shift2,shift3);
    /*
    if(PRINT){
        printf("size basis delta = %d\n",size_basis);
        
        printf("offset %lx %lx \n",offset->data_64[0],offset->data_64[1]);
        for(int i=0;i<size_basis;i++)
            printf("basis vector %lx %lx\n",basis[i]->data_64[0],basis[i]->data_64[1]);
    }
    */
    vec = rand() % ((uint64_t)1<<size_basis);

    delta = vectore_from_basis(basis,size_basis,offset,vec,delta);
    if(PRINT)
        printf("output F3 = %lx %lx \n",delta->data_64[0],delta->data_64[1]);

    THETA(alpha);
    PI(M,alpha);
    XOR(alpha,delta);

    PI(M,alpha);

    copy(alpha,Br);

    THETA(beta);
    PI(M,beta);

    copy(beta,Bl);

    for(int i=0;i<size_basis;i++){
        free(basis[i]->data_64);
        free(basis[i]);
    }

    free(alpha->data_64);
    free(beta->data_64);
    free(delta->data_64);
    free(offset->data_64);
    free(basis);
    free(alpha);
    free(beta);
    free(delta);
    free(offset);

}

void test_cluster_3(int nbr_test,int h){
    int size = 2;

    state* max_al = malloc(sizeof(state));
    state* max_ar = malloc(sizeof(state));
    state* max_bl = malloc(sizeof(state));
    state* max_br = malloc(sizeof(state));

    max_al->data_64 = malloc(sizeof(uint64_t)*size);
    max_al->size_64 = size;
    max_al->weight = 0;

    max_ar->data_64 = malloc(sizeof(uint64_t)*size);
    max_ar->size_64 = size;
    max_ar->weight = 0;

    max_br->data_64 = malloc(sizeof(uint64_t)*size);
    max_br->size_64 = size;
    max_br->weight = 0;

    max_bl->data_64 = malloc(sizeof(uint64_t)*size);
    max_bl->size_64 = size;
    max_bl->weight = 0;

    int size_dist = 1000;
    uint64_t* distribution = malloc(sizeof(uint64_t)*size_dist);
    for(int i=0;i<size_dist;i++)
        distribution[i] = 0; 
    uint64_t* test_result = malloc(sizeof(uint64_t)*nbr_test*h);
    for(int i=0;i<nbr_test*h;i++)
        test_result[i] = 0;

    int max_clust = 0;

    #pragma omp parallel for num_threads(THREADS_NBR) 
    for(int test=0;test<nbr_test;test++){
        state* al = malloc(sizeof(state));
        state* ar = malloc(sizeof(state));
        state* bl = malloc(sizeof(state));
        state* br = malloc(sizeof(state));

        al->data_64 = malloc(sizeof(uint64_t)*size);
        al->size_64 = size;
        al->weight = 0;

        ar->data_64 = malloc(sizeof(uint64_t)*size);
        ar->size_64 = size;
        ar->weight = 0;

        br->data_64 = malloc(sizeof(uint64_t)*al->size_64);
        br->size_64 = size;
        br->weight = 0;

        bl->data_64 = malloc(sizeof(uint64_t)*al->size_64);
        bl->size_64 = size;
        bl->weight = 0;


        //TODO change this part to make the sampling uniformly random over all element of hamming weight h        
        //for each hw h, there is (128 choose h) possible vectors
        //generate h random values between 0 and h_size
        for(int pw = 1;pw<=h;pw++){

            ar->data_64[0] = 0;
            ar->data_64[1] = 0;

            al->data_64[0] = 0;
            al->data_64[1] = 0;

            for(int i=0;i<pw;i++){
                int index = rand() % 256;
                int dec = index % 64;
                int word = (int)index/64;

                if(word>=2)
                    ar->data_64[word-2] |= (uint64_t)1 << dec;
                else
                    al->data_64[word] |= (uint64_t)1 << dec;

            }
            /*
            sleep(0.0001);

            do{
                sleep(0.0001);
                al->data_64[0] = rand() % 256;
                al->data_64[1] = rand() % 256;
                ar->data_64[0] = rand() % 256;
                ar->data_64[1] = rand() % 256;
            }while(hw(al->data_64[0],64)+hw(al->data_64[1],64)+hw(ar->data_64[0],64)+hw(ar->data_64[1],64)>=20);
            */
            bl->data_64[0] = 0;
            bl->data_64[1] = 0;
            br->data_64[0] = 0;
            br->data_64[1] = 0;

            if(PRINT){
                printf("input = ");

                printf("%lx ",al->data_64[0]);
                printf("%lx ",al->data_64[1]);
                printf("%lx ",ar->data_64[0]);
                printf("%lx \n",ar->data_64[1]);
            }
            generate_3_round_trail(ar,al,br,bl);

            if(PRINT){
                printf("output = ");
                printf("%lx ",bl->data_64[0]);
                printf("%lx ",bl->data_64[1]);
                printf("%lx ",br->data_64[0]);
                printf("%lx \n",br->data_64[1]);
                printf("before clustering\n");
            }
            
            int clust = clusterring_3_round(ar,al,br,bl);

            if(PRINT){
                printf("after clustering\n");
            }
            test_result[test*h+pw-1] = clust;
            if(clust==0){
                    printf("\n\n\n\n");
                    printf("\n\n not possible\n\n");
                    printf("%lx ",al->data_64[0]);
                    printf("%lx ",al->data_64[1]);
                    printf("%lx ",ar->data_64[0]);
                    printf("%lx \n",ar->data_64[1]);

                    printf("%lx ",bl->data_64[0]);
                    printf("%lx ",bl->data_64[1]);
                    printf("%lx ",br->data_64[0]);
                    printf("%lx \n",br->data_64[1]);

                    printf("\n\n\n\n");
                    fflush(stdout);
                }
                /*
            #pragma omp critical
            {
            
                if(clust<size_dist)
                    distribution[clust]++;

                if(clust>max_clust){
                    copy(ar,max_ar);
                    copy(al,max_al);
                    copy(br,max_br);
                    copy(bl,max_bl);
                
                    max_clust = clust;
                    printf("new max clust = %d \n\n\n",clust);
                    fflush(stdout);
                }
            }
            */
            if(PRINT)
                printf("number of trail for that differential = %d \n\n\n",clust);
            }
        free(al->data_64);
        free(ar->data_64);
        free(bl->data_64);
        free(br->data_64);
        free(al);
        free(ar);
        free(bl);
        free(br);
    }

    for(int i=0;i<nbr_test*h;i++){

        if(test_result[i]>max_clust){
            max_clust = test_result[i];
        }
        distribution[test_result[i]]++;
    }
    printf("max clusterring effect %d\n",max_clust);
    /*
    printf("input = ");
    printf("%lx ",max_al->data_64[0]);
    printf("%lx ",max_al->data_64[1]);
    printf("%lx ",max_ar->data_64[0]);
    printf("%lx \n",max_ar->data_64[1]);

    printf("output = ");
    printf("%lx ",max_bl->data_64[0]);
    printf("%lx ",max_bl->data_64[1]);
    printf("%lx ",max_br->data_64[0]);
    printf("%lx \n",max_br->data_64[1]);
    */
    printf("distribution of clustering : \n");
    for(int i =0;i<size_dist;i++){
        printf(" %ld ",distribution[i]);
    }
    printf("\n");
    
    
    free(max_al->data_64);
    free(max_ar->data_64);
    free(max_bl->data_64);
    free(max_br->data_64);
    free(distribution);
    free(max_al);
    free(max_ar);
    free(max_bl);
    free(max_br);

}


void test_trail(uint64_t al1,uint64_t al2,uint64_t ar1,uint64_t ar2,uint64_t bl1,uint64_t bl2,uint64_t br1,uint64_t br2){
    state* al = malloc(sizeof(state));
    state* ar = malloc(sizeof(state));
    state* bl = malloc(sizeof(state));
    state* br = malloc(sizeof(state));

    int size = 2;

    al->data_64 = malloc(sizeof(uint64_t)*size);
    al->size_64 = size;
    al->weight = 0;

    ar->data_64 = malloc(sizeof(uint64_t)*size);
    ar->size_64 = size;
    ar->weight = 0;

    br->data_64 = malloc(sizeof(uint64_t)*al->size_64);
    br->size_64 = size;
    br->weight = 0;

    bl->data_64 = malloc(sizeof(uint64_t)*al->size_64);
    bl->size_64 = size;
    bl->weight = 0;

    al->data_64[0] = al1;
    al->data_64[1] = al2;
    ar->data_64[0] = ar1;
    ar->data_64[1] = ar2;  

    printf("%lx ",al->data_64[0]);
    printf("%lx ",al->data_64[1]);
    printf("%lx ",ar->data_64[0]);
    printf("%lx \n",ar->data_64[1]);

    //printf("%lx ",bl->data_64[0]);
    //printf("%lx ",bl->data_64[1]);
    //printf("%lx ",br->data_64[0]);
    //printf("%lx \n",br->data_64[1]);

    generate_3_round_trail(ar,al,br,bl);

    printf("%lx ",al->data_64[0]);
    printf("%lx ",al->data_64[1]);
    printf("%lx ",ar->data_64[0]);
    printf("%lx \n",ar->data_64[1]);

    printf("%lx ",bl->data_64[0]);
    printf("%lx ",bl->data_64[1]);
    printf("%lx ",br->data_64[0]);
    printf("%lx \n",br->data_64[1]);

    bl->data_64[0] = bl1;
    bl->data_64[1] = bl2;
    br->data_64[0] = br1;
    br->data_64[1] = br2;

    int clust = clusterring_3_round(ar,al,br,bl);
    printf("number of trail for that differential = %d \n\n\n",clust);

    free(al->data_64);
    free(ar->data_64);
    free(bl->data_64);
    free(br->data_64);
    free(al);
    free(ar);
    free(bl);
    free(br);

}



int main(){

    //time_t t;
    //srand((unsigned) time(&t));

    test_cluster_3(10000,20);
    //test_trail(0xe9,0xa11,0x3a,0xe5,0x322204040c991012,0x66004c199811,0x52020200140829,0x106260484c10993);

/*
    int size = 2;

    state* al = malloc(sizeof(state));
    state* ar = malloc(sizeof(state));
    state* bl = malloc(sizeof(state));
    state* br = malloc(sizeof(state));

    al->data_64 = malloc(sizeof(uint64_t)*size);
    al->size_64 = size;
    al->weight = 0;

    ar->data_64 = malloc(sizeof(uint64_t)*size);
    ar->size_64 = size;
    ar->weight = 0;

    br->data_64 = malloc(sizeof(uint64_t)*al->size_64);
    br->size_64 = size;
    br->weight = 0;

    bl->data_64 = malloc(sizeof(uint64_t)*al->size_64);
    bl->size_64 = size;
    bl->weight = 0;
    
    al->data_64[0] = rand() % ((uint64_t)1<<50);
    al->data_64[1] = rand() % ((uint64_t)1<<50);

    printf("input : \n");
    print_bin(al);
    printf("\n");

    state** basis = malloc(sizeof(state*)*256);
    state* offset = malloc(sizeof(state));
    offset->data_64 = malloc(sizeof(uint64_t)*al->size_64);
    offset->size_64 = al->size_64;
    int size_basis = generate_basis(al,basis,offset);

    printf("%d size basis\n",size_basis);

    state* alpha = malloc(sizeof(state));
    alpha->data_64 = malloc(sizeof(uint64_t)*al->size_64);
    alpha->size_64 = al->size_64;

    for(int i=0;i<10;i++){
        sleep(1);
        int vec = rand() % ((uint64_t)1<<size_basis);
        //printf(" vector num %d\n",vec);
        XOR(alpha,alpha);
        alpha = vectore_from_basis(basis,size_basis,offset,vec,alpha);
        print_bin(alpha);
        printf("\n");
        printf(" in : %d\n",in(alpha,al));
    }
    
    free(al->data_64);
    free(ar->data_64);
    free(bl->data_64);
    free(br->data_64);
    free(al);
    free(ar);
    free(bl);
    free(br);
    */
    return 0;

}
