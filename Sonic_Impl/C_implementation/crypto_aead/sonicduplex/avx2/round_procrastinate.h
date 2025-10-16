#include "function.h"
#include "constante_procrastinate.h"


void sonic_encrypt_512_procrastinate(const uint64_t plaintext[8],
    uint64_t ciphertext[8]){

//split the plaintext in two half
    int size_half = 4;
        
    h_state512 left  = {.data_64 = {plaintext[0],plaintext[1],plaintext[2],plaintext[3]},.size_64=4};
    h_state512 right = {.data_64 = {plaintext[4],plaintext[5],plaintext[6],plaintext[7]},.size_64=4};

    table_cst_256 table = {.table ={c_256_f9_procr,c_256_47_procr,c_256_eb_procr,c_256_37_procr,c_256_69_procr,
                                    c_256_3b_procr,c_256_49_procr,c_256_3a_procr,c_256_b0_procr,c_256_7d_procr,
                                    c_256_5b_procr,c_256_4a_procr,c_256_32_procr,c_256_71_procr,c_256_7b_procr,
                                    c_256_4b_procr}, .size=16};

    h_state512 tmp = {.data_64 = {0,0,0,0},.size_64=4};
    h_state512 tmp1 = {.data_64 = {0,0,0,0},.size_64=4};
    
    for(int i=0;i<(NBR_ROUND512>>1);i++){
        
        int idx = 16-(i<<1);
        /*
        //apply F function to the right branch
        AND_and_XOR_shift_avx2(&left,&right,shift_1_256[idx],shift_5_256[idx]);
        
        //apply theta to left branch
        XOR3_shift_avx2(&left,shift_7_256[idx],shift_32_256[idx]);
        ADD_CST_512_opt_avx2(i,&table,&left);

        //second round
        idx--;

	//apply F function to the right branch
        AND_and_XOR_shift_avx2(&right,&left,shift_1_256[idx],shift_5_256[idx]);
        
        //apply theta to left branch
        XOR3_shift_avx2(&right,shift_7_256[idx],shift_32_256[idx]);
        ADD_CST_512_opt_avx2((i<<1)+1,&table,&right);

        */

         //apply F function to the right branch
         shift512_avx2(shift_1_256[idx],&left,&tmp);
         AND512_avx2(&tmp,&left);
         shift512_avx2(shift_5_256[idx],&left,&tmp1);
         XOR3_avx2(&right,&tmp,&tmp1);
         
         //apply theta to left branch
         shift512_avx2(shift_7_256[idx],&left,&tmp);
         shift512_avx2(shift_32_256[idx],&left,&tmp1);
         XOR3_avx2(&left,&tmp,&tmp1);
         ADD_CST_512_opt_avx2(i,&table,&left);
 
         //second round
         idx--;
 
         shift512_avx2(shift_1_256[idx],&right,&tmp);
         AND512_avx2(&tmp,&right);
         shift512_avx2(shift_5_256[idx],&right,&tmp1);
         XOR3_avx2(&left,&tmp,&tmp1);
         
         //apply theta to left branch
         shift512_avx2(shift_7_256[idx],&right,&tmp);
         shift512_avx2(shift_32_256[idx],&right,&tmp1);
         XOR3_avx2(&right,&tmp,&tmp1);
         ADD_CST_512_opt_avx2((i<<1)+1,&table,&right);

    }

    for(int i=0;i<size_half;i++){
        ciphertext[i] = left.data_64[i];
        ciphertext[i+size_half] = right.data_64[i];
    }

}
