#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "function.h"
#include "constante.h"

int reshuffle_512[13] = {1,183 ,241 ,71 ,193 ,247 ,145 ,167 ,97 ,87 ,49 ,7 ,1 };

void THETA_512(h_state512* s1){
    h_state512 tmp = {.data_64 = {(uint64_t)0,(uint64_t)0,(uint64_t)0,(uint64_t)0},.size_64=4};
    h_state512 tmp1 = {.data_64 = {(uint64_t)0,(uint64_t)0,(uint64_t)0,(uint64_t)0},.size_64=4};

    shift512(3,s1,&tmp);
    shift512(20,s1,&tmp1);
    XOR3(s1,&tmp,&tmp1);

}

void sonic_512(const uint64_t *input,
                uint64_t *output){

    int size_half = 4;
    
     
    h_state512 left = {.data_64 = {(uint64_t)0,(uint64_t)0,(uint64_t)0,(uint64_t)0},.size_64=4};
    h_state512 right = {.data_64 = {(uint64_t)0,(uint64_t)0,(uint64_t)0,(uint64_t)0},.size_64=4};

    for(int i=0;i<size_half;i++){
        left.data_64[i] = input[i];
        right.data_64[i] = input[i+size_half];
    }

    const table_cst_256 table = {.table ={c_256_f9,c_256_47,c_256_eb,c_256_37,c_256_69,c_256_3b,c_256_49,c_256_3a,c_256_b0,c_256_7d,c_256_5b,c_256_4a}, .size=12};

    h_state512 tmp = {.data_64 = {(uint64_t)0,(uint64_t)0,(uint64_t)0,(uint64_t)0},.size_64=4};
    h_state512 tmp1 = {.data_64 = {(uint64_t)0,(uint64_t)0,(uint64_t)0,(uint64_t)0},.size_64=4};

    for(int i=0;i<NBR_ROUND512;i++){
        
        //apply F function to the right branch
        
        shift512(1,&left,&tmp);
        AND512(&tmp,&left);
        shift512(5,&left,&tmp1);
        XOR3(&right,&tmp,&tmp1);
        
        PI(7,&right);
        
        //apply theta to left branch
        
        THETA_512(&left);
        ADD_CST_512(i,table,&left);
        PI(7,&left);
        
        swap512(&left,&right);

    }

    PI(reshuffle_512[1],&left);
    PI(reshuffle_512[1],&right);


    for(int i=0;i<size_half;i++){
        output[i] = left.data_64[i];
        output[i+size_half] = right.data_64[i];
    }
    
}

void Sonic_Encrypt_512_sub_round(const uint64_t *input,
                       uint64_t *output,
                       int round){

     int size_half = 4;
     
    h_state512 left = {.data_64 = {(uint64_t)0,(uint64_t)0,(uint64_t)0,(uint64_t)0},.size_64=4};
    h_state512 right = {.data_64 = {(uint64_t)0,(uint64_t)0,(uint64_t)0,(uint64_t)0},.size_64=4};

    for(int i=0;i<size_half;i++){
        left.data_64[i] = input[i];
        right.data_64[i] = input[i+size_half];
    }

    const table_cst_256 table = {.table ={c_256_f9,c_256_47,c_256_eb,c_256_37,c_256_69,c_256_3b,c_256_49,c_256_3a,c_256_b0,c_256_7d,c_256_5b,c_256_4a}, .size=12};

    h_state512 tmp = {.data_64 = {(uint64_t)0,(uint64_t)0,(uint64_t)0,(uint64_t)0},.size_64=4};
    h_state512 tmp1 = {.data_64 = {(uint64_t)0,(uint64_t)0,(uint64_t)0,(uint64_t)0},.size_64=4};

    for(int i=0;i<round;i++){
        
        //apply F function to the right branch
        
        shift512(1,&left,&tmp);
        AND512(&tmp,&left);
        shift512(5,&left,&tmp1);
        XOR3(&right,&tmp,&tmp1);
        
        PI(7,&right);
        
        //apply theta to left branch
        
        THETA_512(&left);
        ADD_CST_512(i,table,&left);
        PI(7,&left);
        
        swap512(&left,&right);

    }

    for(int i=0;i<size_half;i++){
        output[i] = left.data_64[i];
        output[i+size_half] = right.data_64[i];
    }
    
}