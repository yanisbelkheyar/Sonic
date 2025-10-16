#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include <omp.h>
#define THREADS_NBR 7

#include "check_compatibility.h"

#define shift1 2
#define shift2 1
#define shift3 8

#define PRINT 0
#define WITH_PI 1
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

#define one(x,i) ((x>>i)&1)

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

    //for delta 3 l
    copy(Bl,delta_3_l);
    if(WITH_PI==1){
        PI(IM,delta_3_l);
    }

    //for delta 2 r
    copy(alpha,delta_2_r);
    XOR(delta_2_r,Ar);
    if(WITH_PI==1){
        PI(M,delta_2_r);
    }

    //for delta 2 l
    copy(Al,delta_2_l);
    if(WITH_PI==1){
        PI(M,delta_2_l);
        copy(delta_3_l,tmp);
        PI(IM,tmp);
        XOR(delta_2_l,tmp);
    }else
        XOR(delta_2_l,Bl);


    //if(PRINT){
    //    printf("al        = %lx %lx\n",Al->data_64[0],Al->data_64[1]);
    //    printf("bl        = %lx %lx\n",Bl->data_64[0],Bl->data_64[1]);
    //    printf("output F2 = %lx %lx\n",Al->data_64[0]^Bl->data_64[0],Al->data_64[1]^Bl->data_64[1]);
    //}

    //for delta 3 r
    copy(delta_2_r,delta_3_r);
    if(WITH_PI==1){
        PI(M,delta_3_r);
        copy(Br,tmp);
        PI(IM,tmp);
        XOR(delta_3_r,tmp);
    }else{
        XOR(delta_3_r,Br);
    }

     if(PRINT){
        printf("ar        = %lx %lx\n",Al->data_64[0],Al->data_64[1]);
        printf("alpha     = %lx %lx\n",alpha->data_64[0],alpha->data_64[1]);
        printf("br        = %lx %lx\n",Br->data_64[0],Br->data_64[1]);
        printf("output F3 = %lx %lx\n",Ar->data_64[0]^Br->data_64[0]^alpha->data_64[0],Ar->data_64[1]^Br->data_64[1]^alpha->data_64[1]);
    }

    int res = in(delta_2_l,delta_2_r,shift1,shift2,shift3) & in(delta_3_r,delta_3_l,shift1,shift2,shift3);

    if(res==0 && PRINT){
        printf("input \n");

        //print_bin(Al);
        //printf(" ");
        //print_bin(Ar);
        //printf("\n");
        
        printf("%lx ",Al->data_64[0]);
        printf("%lx ",Al->data_64[1]);
        printf("%lx ",Ar->data_64[0]);
        printf("%lx \n",Ar->data_64[1]);
        
        //print_bin(alpha);
        //printf("\n");
        //printf("alpha = %lx %lx\n",alpha->data_64[0],alpha->data_64[1]);
        //print_bin(delta_3_l);
        //printf(" ");
        printf("\n");
        printf("input to F2 = %lx %lx\n",delta_2_r->data_64[0],delta_2_r->data_64[1]);
        print_bin(delta_2_r);
        printf("\n");
        printf("output F2 = %lx %lx \n",delta_2_l->data_64[0],delta_2_l->data_64[1]);
        print_bin(delta_2_l);
        printf("\n");
        printf("input to F3 = %lx %lx \n",delta_3_l->data_64[0],delta_3_l->data_64[1]);
        print_bin(delta_3_l);
        printf("\n");
        printf("output F3 = %lx %lx \n",delta_3_r->data_64[0],delta_3_r->data_64[1]);
        print_bin(delta_3_r);
        //printf(" ");
        //print_bin(Br);
        printf("\noutput\n");
     
        printf("%lx ",Bl->data_64[0]);
        printf("%lx ",Bl->data_64[1]);
        printf("%lx ",Br->data_64[0]);
        printf("%lx \n\n",Br->data_64[1]);
        
        printf(" 2 l in 2 r = %d, 3 r in 3 l = %d\n\n",in(delta_2_l,delta_2_r,shift1,shift2,shift3),in(delta_3_r,delta_3_l,shift1,shift2,shift3));
    }

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

    //maybe there is something smarter to do her to reduce the complexity and cut some search ?
    return res;
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

    //printf("nbr trail for that differential = %d\n",nbr_trail);
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

    if(PRINT)
        print_bin(Al);
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

    int vec = 0;//rand() % ((uint64_t)1<<size_basis);

    alpha = vectore_from_basis(basis,size_basis,offset,vec,alpha);
    if(PRINT)
        printf("alpha = %lx %lx\n",alpha->data_64[0],alpha->data_64[1]);

    XOR(alpha,Ar);

    if(WITH_PI==1){
        PI(M,alpha);
    }

    copy(Al,tmp);
    if(WITH_PI==1){
        PI(M,tmp);
    }

    if(PRINT)
        print_bin(alpha);

    if(PRINT)
        printf("input to F2 = %lx %lx\n",alpha->data_64[0],alpha->data_64[1]);

    size_basis = generate_basis(alpha,basis,offset,shift1,shift2,shift3);
    
    if(PRINT){
        printf("size basis beta = %d\n",size_basis);
        
        printf("offset %lx %lx \n",offset->data_64[0],offset->data_64[1]);
        for(int i=0;i<size_basis;i++)
            printf("basis vector %lx %lx\n",basis[i]->data_64[0],basis[i]->data_64[1]);
    }
    
    vec = 0; //rand() % ((uint64_t)1<<size_basis);

    beta = vectore_from_basis(basis,size_basis,offset,vec,beta);
    if(PRINT)
        printf("output F2 = %lx %lx \n",beta->data_64[0],beta->data_64[1]);

    XOR(beta,tmp);
    if(WITH_PI==1){
        PI(M,beta);
    }

    if(WITH_PI==1){
        PI(M,alpha);
    }

    if(PRINT)
        print_bin(beta);
    if(PRINT)
        printf("input to F3 = %lx %lx \n",beta->data_64[0],beta->data_64[1]);

    size_basis = generate_basis(beta,basis,offset,shift1,shift2,shift3);

    if(PRINT){
        printf("size basis delta = %d\n",size_basis);
        
        printf("offset %lx %lx \n",offset->data_64[0],offset->data_64[1]);
        for(int i=0;i<size_basis;i++)
            printf("basis vector %lx %lx\n",basis[i]->data_64[0],basis[i]->data_64[1]);
    }
    
    vec = rand() % ((uint64_t)1<<size_basis);

    delta = vectore_from_basis(basis,size_basis,offset,vec,delta);
    if(PRINT)
        printf("output F3 = %lx %lx \n",delta->data_64[0],delta->data_64[1]);



    XOR(alpha,delta);

    copy(alpha,Br);
    if(WITH_PI==1){
        PI(M,Br);
    }

    copy(beta,Bl);
    if(WITH_PI==1){
        PI(M,Bl);
    }

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

    int size_dist = 1000;
    uint64_t* distribution = malloc(sizeof(uint64_t)*size_dist);
    for(int i=0;i<size_dist;i++)
        distribution[i] = 0; 

    uint64_t* test_result = malloc(sizeof(uint64_t)*nbr_test*h);
    for(int i=0;i<nbr_test*h;i++)
        test_result[i] = 0;

    int max_clust = 0;

    state* max_clust_differential[4];
    for(int i=0;i<4;i++){
        max_clust_differential[i] = malloc(sizeof(state));
        max_clust_differential[i]->data_64 = malloc(sizeof(uint64_t)*size);
        max_clust_differential[i]->size_64 = size;
        max_clust_differential[i]->weight = 0;
    }

    //#pragma omp parallel for num_threads(THREADS_NBR) 
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
                    al->data_64[word-2] |= (uint64_t)1 << dec;
                else
                    ar->data_64[word] |= (uint64_t)1 << dec;

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
            }
            
            int clust = clusterring_3_round(ar,al,br,bl);
            test_result[test*h+pw-1] = clust;

            if(max_clust<clust){
                max_clust = clust;
                max_clust_differential[0]->data_64[0] = al->data_64[0];
                max_clust_differential[0]->data_64[1] = al->data_64[1];
                max_clust_differential[1]->data_64[0] = ar->data_64[0];
                max_clust_differential[1]->data_64[1] = ar->data_64[1];

                max_clust_differential[2]->data_64[0] = bl->data_64[0];
                max_clust_differential[2]->data_64[1] = bl->data_64[1];
                max_clust_differential[3]->data_64[0] = br->data_64[0];
                max_clust_differential[3]->data_64[1] = br->data_64[1];
            }
            

            if(clust==0){
                    printf("not possible\n");
                    printf("%lx ",al->data_64[0]);
                    printf("%lx ",al->data_64[1]);
                    printf("%lx ",ar->data_64[0]);
                    printf("%lx \n",ar->data_64[1]);

                    printf("%lx ",bl->data_64[0]);
                    printf("%lx ",bl->data_64[1]);
                    printf("%lx ",br->data_64[0]);
                    printf("%lx \n",br->data_64[1]);
                    fflush(stdout);
                }

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
    
    if(PRINT){
    printf("distribution of clustering : \n");
    }
    for(int i=0;i<nbr_test*h;i++){

        if(test_result[i]>max_clust){
            max_clust = test_result[i];
        }
	if(test_result[i]<size_dist)
        	distribution[test_result[i]]++;
    }
    //if(PRINT){
    printf("max clusterring effect %d\n",max_clust);
    printf("for differential :\n");
    printf("%lx ",max_clust_differential[0]->data_64[0]);
    printf("%lx ",max_clust_differential[0]->data_64[1]);
    printf("%lx ",max_clust_differential[1]->data_64[0]);
    printf("%lx \n",max_clust_differential[1]->data_64[1]);

    printf("%lx ",max_clust_differential[2]->data_64[0]);
    printf("%lx ",max_clust_differential[2]->data_64[1]);
    printf("%lx ",max_clust_differential[3]->data_64[0]);
    printf("%lx \n",max_clust_differential[3]->data_64[1]);
    //}
    
    for(int i =0;i<size_dist;i++){
        printf(" %ld ",distribution[i]);
    }
    printf("\n");
    


    free(distribution);
    free(test_result);
}

void test_trail(long int al1,long int al2,long int ar1,long int ar2,long int bl1,long int bl2,long int br1,long int br2){
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

    //bl->data_64[0] = bl1;
    //bl->data_64[1] = bl2;
    //br->data_64[0] = br1;
    //br->data_64[1] = br2;

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

    al->data_64[0] = 0x1000000020004;
    al->data_64[1] = 0x8001000000;
    ar->data_64[0] = 0;
    ar->data_64[1] = 0x0; 
    
    bl->data_64[0] = 0x1408000028105;
    bl->data_64[1] = 0x800000b041e08000;
    br->data_64[0] = 0x200080006241;
    br->data_64[1] = 0xa000003810388080; 
    
    //print_bin(al);
    //print_bin(ar);

    //printf("\n");
    
    //print_bin(bl);
    //print_bin(br);

    //printf("\n");

    //clusterring_3_round(ar,al,br,bl);
    test_cluster_3(10000,5);
    //test_trail(0xaf,0x36,0x7b,0x8c,0xbb,0x7e,0x7e,0xbe);
    //test_trail(0x0,0x804000000000000,0x0,0x0,0x0,0x884400000000000,0x0,0x468144000000000);

    return 1;
}
