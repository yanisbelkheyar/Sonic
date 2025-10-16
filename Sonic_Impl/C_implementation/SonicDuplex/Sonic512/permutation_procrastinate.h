#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "function.h"
#include "constante.h"

void sonic_512_procrastinate(const uint64_t *input,
                        uint64_t *output){

    int size_half = 4;
    
    h_state512 left = {.data_64 = {(uint64_t)0,(uint64_t)0,(uint64_t)0,(uint64_t)0},.size_64=4};
    h_state512 right = {.data_64 = {(uint64_t)0,(uint64_t)0,(uint64_t)0,(uint64_t)0},.size_64=4};

    for(int i=0;i<size_half;i++){
        left.data_64[i] = input[i];
        right.data_64[i] = input[i+size_half];
    }

    const table_cst_256 table = {.table ={c_256_f9_procr,c_256_47_procr,c_256_eb_procr,c_256_37_procr,c_256_69_procr,c_256_3b_procr,c_256_49_procr,c_256_3a_procr,c_256_b0_procr,c_256_7d_procr,c_256_5b_procr,c_256_4a_procr}, .size=12};

    h_state512 tmp = {.data_64 = {(uint64_t)0,(uint64_t)0,(uint64_t)0,(uint64_t)0},.size_64=4};
    h_state512 tmp1 = {.data_64 = {(uint64_t)0,(uint64_t)0,(uint64_t)0,(uint64_t)0},.size_64=4};

    for(int i=0;i<NBR_ROUND512;i++){
        
        int idx = 12-i;

        //apply F function to the right branch
        shift512(shift_1_256[idx],&left,&tmp);
        AND512(&tmp,&left);
        shift512(shift_5_256[idx],&left,&tmp1);
        XOR3(&right,&tmp,&tmp1);
        
        //apply theta to left branch
        shift512(shift_3_256[idx],&left,&tmp);
        shift512(shift_20_256[idx],&left,&tmp1);
        XOR3(&left,&tmp,&tmp1);
        ADD_CST_512(i,table,&left);

        swap512(&left,&right);

    }

    for(int i=0;i<size_half;i++){
        output[i] = left.data_64[i];
        output[i+size_half] = right.data_64[i];
    }

}

