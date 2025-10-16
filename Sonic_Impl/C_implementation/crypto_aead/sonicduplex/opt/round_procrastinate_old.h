#ifndef ROUND_PROCRASTINATE
#define ROUND_PROCRASTINATE

#include "function.h"

//__attribute__ ((__target__ ("no-avx")))
 void sonic_encrypt_512_procrastinate(h_state512* left, h_state512* right){
   


    h_state512 tmp = {.data_64 = {0,0,0,0},.size_64=4};
    h_state512 tmp1 = {.data_64 = {0,0,0,0},.size_64=4};
    

        //apply F function to the right branch
        tmp.data_64[0] = ror_help(left->data_64[1], left->data_64[0], 63);
        tmp.data_64[1] = ror_help(left->data_64[2], left->data_64[1], 63);
        tmp.data_64[2] = ror_help(left->data_64[3], left->data_64[2], 63);
        tmp.data_64[3] = ror_help(left->data_64[0], left->data_64[3], 63);
        
        AND512(&tmp,left);
        // shift512(shift_5_256[16],left,&tmp1);
        tmp1.data_64[0] = ror_help(left->data_64[1], left->data_64[0], 59);
        tmp1.data_64[1] = ror_help(left->data_64[2], left->data_64[1], 59);
        tmp1.data_64[2] = ror_help(left->data_64[3], left->data_64[2], 59);
        tmp1.data_64[3] = ror_help(left->data_64[0], left->data_64[3], 59);
        XOR3(right,&tmp,&tmp1);
        
        //apply theta to left branch
        // shift512(shift_7_256[16],left,&tmp);
        tmp.data_64[0] = ror_help(left->data_64[1], left->data_64[0], 57);
        tmp.data_64[1] = ror_help(left->data_64[2], left->data_64[1], 57);
        tmp.data_64[2] = ror_help(left->data_64[3], left->data_64[2], 57);
        tmp.data_64[3] = ror_help(left->data_64[0], left->data_64[3], 57);
        // shift512(shift_32_256[16],left,&tmp1);
        tmp1.data_64[0] = ror_help(left->data_64[1], left->data_64[0], 32);
        tmp1.data_64[1] = ror_help(left->data_64[2], left->data_64[1], 32);
        tmp1.data_64[2] = ror_help(left->data_64[3], left->data_64[2], 32);
        tmp1.data_64[3] = ror_help(left->data_64[0], left->data_64[3], 32);
        XOR3(left,&tmp,&tmp1);
        // ADD_CST_512_opt(0,left);
        left->data_64[0] ^= 0x8000000080000000;
        left->data_64[1] ^= 0x80000000;
        left->data_64[3] ^= 0x8000000000000000;


        // shift512(shift_1_256[15],right,&tmp);
        tmp.data_64[0] = ror_help(right->data_64[1], right->data_64[0], 49);
        tmp.data_64[1] = ror_help(right->data_64[2], right->data_64[1], 49);
        tmp.data_64[2] = ror_help(right->data_64[3], right->data_64[2], 49);
        tmp.data_64[3] = ror_help(right->data_64[0], right->data_64[3], 49);
        AND512(&tmp,right);
        // shift512(shift_5_256[15],right,&tmp1);
        tmp1.data_64[0] = ror_help(right->data_64[2], right->data_64[1], 53);
        tmp1.data_64[1] = ror_help(right->data_64[3], right->data_64[2], 53);
        tmp1.data_64[2] = ror_help(right->data_64[0], right->data_64[3], 53);
        tmp1.data_64[3] = ror_help(right->data_64[1], right->data_64[0], 53);
        XOR3(left,&tmp,&tmp1);
        
        //apply theta to left branch
        // shift512(shift_7_256[15],right,&tmp);
        tmp.data_64[0] = ror_help(right->data_64[2], right->data_64[1], 23);
        tmp.data_64[1] = ror_help(right->data_64[3], right->data_64[2], 23);
        tmp.data_64[2] = ror_help(right->data_64[0], right->data_64[3], 23);
        tmp.data_64[3] = ror_help(right->data_64[1], right->data_64[0], 23);
        // shift512(shift_32_256[15],right,&tmp1);
        tmp1.data_64[0] = ror_help(right->data_64[0], right->data_64[3], 32);
        tmp1.data_64[1] = ror_help(right->data_64[1], right->data_64[0], 32);
        tmp1.data_64[2] = ror_help(right->data_64[2], right->data_64[1], 32);
        tmp1.data_64[3] = ror_help(right->data_64[3], right->data_64[2], 32);
        XOR3(right,&tmp,&tmp1);
        // ADD_CST_512_opt((0<<1)+1,right);
        right->data_64[0] ^= 0x8000000000000000;
        right->data_64[1] ^= 0x8000000080000000;
        right->data_64[2] ^= 0x8000000080000000;
        right->data_64[3] ^= 0x80000000;
        
        
        //apply F function to the right branch
        // shift512(shift_1_256[14],left,&tmp);
        tmp.data_64[0] = ror_help(left->data_64[0], left->data_64[3], 31);
        tmp.data_64[1] = ror_help(left->data_64[1], left->data_64[0], 31);
        tmp.data_64[2] = ror_help(left->data_64[2], left->data_64[1], 31);
        tmp.data_64[3] = ror_help(left->data_64[3], left->data_64[2], 31);
        AND512(&tmp,left);
        // shift512(shift_5_256[14],left,&tmp1);
        tmp1.data_64[0] = ror_help(left->data_64[2], left->data_64[1], 27);
        tmp1.data_64[1] = ror_help(left->data_64[3], left->data_64[2], 27);
        tmp1.data_64[2] = ror_help(left->data_64[0], left->data_64[3], 27);
        tmp1.data_64[3] = ror_help(left->data_64[1], left->data_64[0], 27);
        XOR3(right,&tmp,&tmp1);
        
        //apply theta to left branch
        // shift512(shift_7_256[14],left,&tmp);
        tmp.data_64[0] = ror_help(left->data_64[1], left->data_64[0], 25);
        tmp.data_64[1] = ror_help(left->data_64[2], left->data_64[1], 25);
        tmp.data_64[2] = ror_help(left->data_64[3], left->data_64[2], 25);
        tmp.data_64[3] = ror_help(left->data_64[0], left->data_64[3], 25);
        // shift512(shift_32_256[14],left,&tmp1);
        tmp1.data_64[0] = ror_help(left->data_64[1], left->data_64[0], 32);
        tmp1.data_64[1] = ror_help(left->data_64[2], left->data_64[1], 32);
        tmp1.data_64[2] = ror_help(left->data_64[3], left->data_64[2], 32);
        tmp1.data_64[3] = ror_help(left->data_64[0], left->data_64[3], 32);
        XOR3(left,&tmp,&tmp1);
        // ADD_CST_512_opt(1,left);
        left->data_64[0] ^= 0x8000000000000000;
        left->data_64[1] ^= 0x8000000080000000;
        left->data_64[2] ^= 0x8000000080000000;
        left->data_64[3] ^= 0x80000000;

        // shift512(shift_1_256[13],right,&tmp);
        tmp.data_64[0] = ror_help(right->data_64[1], right->data_64[0], 17);
        tmp.data_64[1] = ror_help(right->data_64[2], right->data_64[1], 17);
        tmp.data_64[2] = ror_help(right->data_64[3], right->data_64[2], 17);
        tmp.data_64[3] = ror_help(right->data_64[0], right->data_64[3], 17);
        AND512(&tmp,right);
        // shift512(shift_5_256[13],right,&tmp1);
        tmp1.data_64[0] = ror_help(right->data_64[0], right->data_64[3], 21);
        tmp1.data_64[1] = ror_help(right->data_64[1], right->data_64[0], 21);
        tmp1.data_64[2] = ror_help(right->data_64[2], right->data_64[1], 21);
        tmp1.data_64[3] = ror_help(right->data_64[3], right->data_64[2], 21);
        XOR3(left,&tmp,&tmp1);
        
        //apply theta to left branch
        // shift512(shift_7_256[13],right,&tmp);
        tmp.data_64[0] = ror_help(right->data_64[2], right->data_64[1], 55);
        tmp.data_64[1] = ror_help(right->data_64[3], right->data_64[2], 55);
        tmp.data_64[2] = ror_help(right->data_64[0], right->data_64[3], 55);
        tmp.data_64[3] = ror_help(right->data_64[1], right->data_64[0], 55);
        // shift512(shift_32_256[13],right,&tmp1);
        tmp1.data_64[0] = ror_help(right->data_64[0], right->data_64[3], 32);
        tmp1.data_64[1] = ror_help(right->data_64[1], right->data_64[0], 32);
        tmp1.data_64[2] = ror_help(right->data_64[2], right->data_64[1], 32);
        tmp1.data_64[3] = ror_help(right->data_64[3], right->data_64[2], 32);
        XOR3(right,&tmp,&tmp1);
        // ADD_CST_512_opt((1<<1)+1,right);
        right->data_64[0] ^= 0x0;
        right->data_64[1] ^= 0x80000000;
        right->data_64[2] ^= 0x8000000000000000;
        right->data_64[3] ^= 0x80000000;
        
        //apply F function to the right branch
        // shift512(shift_1_256[12],left,&tmp);
        tmp.data_64[0] = ror_help(left->data_64[0], left->data_64[3], 63);
        tmp.data_64[1] = ror_help(left->data_64[1], left->data_64[0], 63);
        tmp.data_64[2] = ror_help(left->data_64[2], left->data_64[1], 63);
        tmp.data_64[3] = ror_help(left->data_64[3], left->data_64[2], 63);
        AND512(&tmp,left);
        // shift512(shift_5_256[12],left,&tmp1);
        tmp1.data_64[0] = ror_help(left->data_64[0], left->data_64[3], 59);
        tmp1.data_64[1] = ror_help(left->data_64[1], left->data_64[0], 59);
        tmp1.data_64[2] = ror_help(left->data_64[2], left->data_64[1], 59);
        tmp1.data_64[3] = ror_help(left->data_64[3], left->data_64[2], 59);
        XOR3(right,&tmp,&tmp1);
        
        //apply theta to left branch
        // shift512(shift_7_256[12],left,&tmp);
        tmp.data_64[0] = ror_help(left->data_64[2], left->data_64[1], 57);
        tmp.data_64[1] = ror_help(left->data_64[3], left->data_64[2], 57);
        tmp.data_64[2] = ror_help(left->data_64[0], left->data_64[3], 57);
        tmp.data_64[3] = ror_help(left->data_64[1], left->data_64[0], 57);
        // shift512(shift_32_256[12],left,&tmp1);
        tmp1.data_64[0] = ror_help(left->data_64[1], left->data_64[0], 32);
        tmp1.data_64[1] = ror_help(left->data_64[2], left->data_64[1], 32);
        tmp1.data_64[2] = ror_help(left->data_64[3], left->data_64[2], 32);
        tmp1.data_64[3] = ror_help(left->data_64[0], left->data_64[3], 32);
        XOR3(left,&tmp,&tmp1);
        // ADD_CST_512_opt(2,left);
        left->data_64[0] ^= 0x8000000000000000;
        left->data_64[1] ^= 0x0;
        left->data_64[2] ^= 0x8000000080000000;
        left->data_64[3] ^= 0x8000000000000000;


        // shift512(shift_1_256[11],right,&tmp);
        tmp.data_64[0] = ror_help(right->data_64[2], right->data_64[1], 49);
        tmp.data_64[1] = ror_help(right->data_64[3], right->data_64[2], 49);
        tmp.data_64[2] = ror_help(right->data_64[0], right->data_64[3], 49);
        tmp.data_64[3] = ror_help(right->data_64[1], right->data_64[0], 49);
        AND512(&tmp,right);
        // shift512(shift_5_256[11],right,&tmp1);
        tmp1.data_64[0] = ror_help(right->data_64[3], right->data_64[2], 53);
        tmp1.data_64[1] = ror_help(right->data_64[0], right->data_64[3], 53);
        tmp1.data_64[2] = ror_help(right->data_64[1], right->data_64[0], 53);
        tmp1.data_64[3] = ror_help(right->data_64[2], right->data_64[1], 53);
        XOR3(left,&tmp,&tmp1);
        
        //apply theta to left branch
        // shift512(shift_7_256[11],right,&tmp);
        tmp.data_64[0] = ror_help(right->data_64[1], right->data_64[0], 23);
        tmp.data_64[1] = ror_help(right->data_64[2], right->data_64[1], 23);
        tmp.data_64[2] = ror_help(right->data_64[3], right->data_64[2], 23);
        tmp.data_64[3] = ror_help(right->data_64[0], right->data_64[3], 23);
        // shift512(shift_32_256[11],right,&tmp1);
        tmp1.data_64[0] = ror_help(right->data_64[0], right->data_64[3], 32);
        tmp1.data_64[1] = ror_help(right->data_64[1], right->data_64[0], 32);
        tmp1.data_64[2] = ror_help(right->data_64[2], right->data_64[1], 32);
        tmp1.data_64[3] = ror_help(right->data_64[3], right->data_64[2], 32);
        XOR3(right,&tmp,&tmp1);
        // ADD_CST_512_opt((2<<1)+1,right);
        right->data_64[0] ^= 0x8000000000000000;
        right->data_64[1] ^= 0x8000000000000000;
        right->data_64[2] ^= 0x8000000080000000;
        right->data_64[3] ^= 0x80000000;
        
        
        //apply F function to the right branch
        // shift512(shift_1_256[10],left,&tmp);
        tmp.data_64[0] = ror_help(left->data_64[3], left->data_64[2], 31);
        tmp.data_64[1] = ror_help(left->data_64[0], left->data_64[3], 31);
        tmp.data_64[2] = ror_help(left->data_64[1], left->data_64[0], 31);
        tmp.data_64[3] = ror_help(left->data_64[2], left->data_64[1], 31);
        AND512(&tmp,left);
        // shift512(shift_5_256[10],left,&tmp1);
        tmp1.data_64[0] = ror_help(left->data_64[1], left->data_64[0], 27);
        tmp1.data_64[1] = ror_help(left->data_64[2], left->data_64[1], 27);
        tmp1.data_64[2] = ror_help(left->data_64[3], left->data_64[2], 27);
        tmp1.data_64[3] = ror_help(left->data_64[0], left->data_64[3], 27);
        XOR3(right,&tmp,&tmp1);
        
        //apply theta to left branch
        // shift512(shift_7_256[10],left,&tmp);
        tmp.data_64[0] = ror_help(left->data_64[2], left->data_64[1], 25);
        tmp.data_64[1] = ror_help(left->data_64[3], left->data_64[2], 25);
        tmp.data_64[2] = ror_help(left->data_64[0], left->data_64[3], 25);
        tmp.data_64[3] = ror_help(left->data_64[1], left->data_64[0], 25);
        // shift512(shift_32_256[10],left,&tmp1);
        tmp1.data_64[0] = ror_help(left->data_64[1], left->data_64[0], 32);
        tmp1.data_64[1] = ror_help(left->data_64[2], left->data_64[1], 32);
        tmp1.data_64[2] = ror_help(left->data_64[3], left->data_64[2], 32);
        tmp1.data_64[3] = ror_help(left->data_64[0], left->data_64[3], 32);
        XOR3(left,&tmp,&tmp1);
        // ADD_CST_512_opt(3,left);
        left->data_64[0] ^= 0x0;
        left->data_64[1] ^= 0x80000000;
        left->data_64[2] ^= 0x8000000000000000;
        left->data_64[3] ^= 0x80000000;


        // shift512(shift_1_256[9],right,&tmp);
        tmp.data_64[0] = ror_help(right->data_64[2], right->data_64[1], 17);
        tmp.data_64[1] = ror_help(right->data_64[3], right->data_64[2], 17);
        tmp.data_64[2] = ror_help(right->data_64[0], right->data_64[3], 17);
        tmp.data_64[3] = ror_help(right->data_64[1], right->data_64[0], 17);
        AND512(&tmp,right);
        // shift512(shift_5_256[9],right,&tmp1);
        tmp1.data_64[0] = ror_help(right->data_64[1], right->data_64[0], 21);
        tmp1.data_64[1] = ror_help(right->data_64[2], right->data_64[1], 21);
        tmp1.data_64[2] = ror_help(right->data_64[3], right->data_64[2], 21);
        tmp1.data_64[3] = ror_help(right->data_64[0], right->data_64[3], 21);
        XOR3(left,&tmp,&tmp1);
        
        //apply theta to left branch
        // shift512(shift_7_256[9],right,&tmp);
        tmp.data_64[0] = ror_help(right->data_64[1], right->data_64[0], 55);
        tmp.data_64[1] = ror_help(right->data_64[2], right->data_64[1], 55);
        tmp.data_64[2] = ror_help(right->data_64[3], right->data_64[2], 55);
        tmp.data_64[3] = ror_help(right->data_64[0], right->data_64[3], 55);
        // shift512(shift_32_256[9],right,&tmp1);
        tmp1.data_64[0] = ror_help(right->data_64[0], right->data_64[3], 32);
        tmp1.data_64[1] = ror_help(right->data_64[1], right->data_64[0], 32);
        tmp1.data_64[2] = ror_help(right->data_64[2], right->data_64[1], 32);
        tmp1.data_64[3] = ror_help(right->data_64[3], right->data_64[2], 32);
        XOR3(right,&tmp,&tmp1);
        // ADD_CST_512_opt((3<<1)+1,right);
        right->data_64[0] ^= 0x80000000;
        right->data_64[1] ^= 0x80000000;
        right->data_64[2] ^= 0x8000000000000000;
        right->data_64[3] ^= 0x0;
        
        
        //apply F function to the right branch
        // shift512(shift_1_256[8],left,&tmp);
        tmp.data_64[0] = ror_help(left->data_64[3], left->data_64[2], 63);
        tmp.data_64[1] = ror_help(left->data_64[0], left->data_64[3], 63);
        tmp.data_64[2] = ror_help(left->data_64[1], left->data_64[0], 63);
        tmp.data_64[3] = ror_help(left->data_64[2], left->data_64[1], 63);
        AND512(&tmp,left);
        // shift512(shift_5_256[8],left,&tmp1);
        tmp1.data_64[0] = ror_help(left->data_64[3], left->data_64[2], 59);
        tmp1.data_64[1] = ror_help(left->data_64[0], left->data_64[3], 59);
        tmp1.data_64[2] = ror_help(left->data_64[1], left->data_64[0], 59);
        tmp1.data_64[3] = ror_help(left->data_64[2], left->data_64[1], 59);
        XOR3(right,&tmp,&tmp1);
        
        //apply theta to left branch
        // shift512(shift_7_256[8],left,&tmp);
        tmp.data_64[0] = ror_help(left->data_64[3], left->data_64[2], 57);
        tmp.data_64[1] = ror_help(left->data_64[0], left->data_64[3], 57);
        tmp.data_64[2] = ror_help(left->data_64[1], left->data_64[0], 57);
        tmp.data_64[3] = ror_help(left->data_64[2], left->data_64[1], 57);
        // shift512(shift_32_256[8],left,&tmp1);
        tmp1.data_64[0] = ror_help(left->data_64[1], left->data_64[0], 32);
        tmp1.data_64[1] = ror_help(left->data_64[2], left->data_64[1], 32);
        tmp1.data_64[2] = ror_help(left->data_64[3], left->data_64[2], 32);
        tmp1.data_64[3] = ror_help(left->data_64[0], left->data_64[3], 32);
        XOR3(left,&tmp,&tmp1);
        // ADD_CST_512_opt(4,left);
        left->data_64[0] ^= 0x80000000;
        left->data_64[1] ^= 0x80000000;
        left->data_64[2] ^= 0x0;
        left->data_64[3] ^= 0x8000000000000000;


        // shift512(shift_1_256[7],right,&tmp);
        tmp.data_64[0] = ror_help(right->data_64[3], right->data_64[2], 49);
        tmp.data_64[1] = ror_help(right->data_64[0], right->data_64[3], 49);
        tmp.data_64[2] = ror_help(right->data_64[1], right->data_64[0], 49);
        tmp.data_64[3] = ror_help(right->data_64[2], right->data_64[1], 49);
        AND512(&tmp,right);
        // shift512(shift_5_256[7],right,&tmp1);
        tmp1.data_64[0] = ror_help(right->data_64[0], right->data_64[3], 53);
        tmp1.data_64[1] = ror_help(right->data_64[1], right->data_64[0], 53);
        tmp1.data_64[2] = ror_help(right->data_64[2], right->data_64[1], 53);
        tmp1.data_64[3] = ror_help(right->data_64[3], right->data_64[2], 53);
        XOR3(left,&tmp,&tmp1);
        
        //apply theta to left branch
        // shift512(shift_7_256[7],right,&tmp);
        tmp.data_64[0] = ror_help(right->data_64[0], right->data_64[3], 23);
        tmp.data_64[1] = ror_help(right->data_64[1], right->data_64[0], 23);
        tmp.data_64[2] = ror_help(right->data_64[2], right->data_64[1], 23);
        tmp.data_64[3] = ror_help(right->data_64[3], right->data_64[2], 23);
        // shift512(shift_32_256[9],right,&tmp1);
        tmp1.data_64[0] = ror_help(right->data_64[0], right->data_64[3], 32);
        tmp1.data_64[1] = ror_help(right->data_64[1], right->data_64[0], 32);
        tmp1.data_64[2] = ror_help(right->data_64[2], right->data_64[1], 32);
        tmp1.data_64[3] = ror_help(right->data_64[3], right->data_64[2], 32);
        XOR3(right,&tmp,&tmp1);
        // ADD_CST_512_opt((4<<1)+1,right);
        right->data_64[0] ^= 0x8000000000000000;
        right->data_64[1] ^= 0x8000000000000000;
        right->data_64[2] ^= 0x80000000;
        right->data_64[3] ^= 0x0;
        
        
        //apply F function to the right branch
        // shift512(shift_1_256[6],left,&tmp);
        tmp.data_64[0] = ror_help(left->data_64[2], left->data_64[1], 31);
        tmp.data_64[1] = ror_help(left->data_64[3], left->data_64[2], 31);
        tmp.data_64[2] = ror_help(left->data_64[0], left->data_64[3], 31);
        tmp.data_64[3] = ror_help(left->data_64[1], left->data_64[0], 31);
        AND512(&tmp,left);
        // shift512(shift_5_256[6],left,&tmp1);
        tmp1.data_64[0] = ror_help(left->data_64[0], left->data_64[3], 27);
        tmp1.data_64[1] = ror_help(left->data_64[1], left->data_64[0], 27);
        tmp1.data_64[2] = ror_help(left->data_64[2], left->data_64[1], 27);
        tmp1.data_64[3] = ror_help(left->data_64[3], left->data_64[2], 27);
        XOR3(right,&tmp,&tmp1);
        
        //apply theta to left branch
        // shift512(shift_7_256[6],left,&tmp);
        tmp.data_64[0] = ror_help(left->data_64[3], left->data_64[2], 25);
        tmp.data_64[1] = ror_help(left->data_64[0], left->data_64[3], 25);
        tmp.data_64[2] = ror_help(left->data_64[1], left->data_64[0], 25);
        tmp.data_64[3] = ror_help(left->data_64[2], left->data_64[1], 25);
        // shift512(shift_32_256[6],left,&tmp1);
        tmp1.data_64[0] = ror_help(left->data_64[1], left->data_64[0], 32);
        tmp1.data_64[1] = ror_help(left->data_64[2], left->data_64[1], 32);
        tmp1.data_64[2] = ror_help(left->data_64[3], left->data_64[2], 32);
        tmp1.data_64[3] = ror_help(left->data_64[0], left->data_64[3], 32);
        XOR3(left,&tmp,&tmp1);
        // ADD_CST_512_opt(5,left);
        left->data_64[0] ^= 0x8000000000000000;
        left->data_64[1] ^= 0x8000000000000000;
        left->data_64[2] ^= 0x8000000080000000;
        left->data_64[3] ^= 0x80000000;

        // shift512(shift_1_256[5],right,&tmp);
        tmp.data_64[0] = ror_help(right->data_64[3], right->data_64[2], 17);
        tmp.data_64[1] = ror_help(right->data_64[0], right->data_64[3], 17);
        tmp.data_64[2] = ror_help(right->data_64[1], right->data_64[0], 17);
        tmp.data_64[3] = ror_help(right->data_64[2], right->data_64[1], 17);
        AND512(&tmp,right);
        // shift512(shift_5_256[5],right,&tmp1);
        tmp1.data_64[0] = ror_help(right->data_64[2], right->data_64[1], 21);
        tmp1.data_64[1] = ror_help(right->data_64[3], right->data_64[2], 21);
        tmp1.data_64[2] = ror_help(right->data_64[0], right->data_64[3], 21);
        tmp1.data_64[3] = ror_help(right->data_64[1], right->data_64[0], 21);
        XOR3(left,&tmp,&tmp1);
        
        //apply theta to left branch
        // shift512(shift_7_256[5],right,&tmp);
        tmp.data_64[0] = ror_help(right->data_64[0], right->data_64[3], 55);
        tmp.data_64[1] = ror_help(right->data_64[1], right->data_64[0], 55);
        tmp.data_64[2] = ror_help(right->data_64[2], right->data_64[1], 55);
        tmp.data_64[3] = ror_help(right->data_64[3], right->data_64[2], 55);
        // shift512(shift_32_256[9],right,&tmp1);
        tmp1.data_64[0] = ror_help(right->data_64[0], right->data_64[3], 32);
        tmp1.data_64[1] = ror_help(right->data_64[1], right->data_64[0], 32);
        tmp1.data_64[2] = ror_help(right->data_64[2], right->data_64[1], 32);
        tmp1.data_64[3] = ror_help(right->data_64[3], right->data_64[2], 32);
        XOR3(right,&tmp,&tmp1);
        // ADD_CST_512_opt((5<<1)+1,right);
        right->data_64[0] ^= 0x8000000000000000;
        right->data_64[1] ^= 0x8000000080000000;
        right->data_64[2] ^= 0x80000000;
        right->data_64[3] ^= 0x0;
        
        //apply F function to the right branch
        // shift512(shift_1_256[4],left,&tmp);
        tmp.data_64[0] = ror_help(left->data_64[2], left->data_64[1], 63);
        tmp.data_64[1] = ror_help(left->data_64[3], left->data_64[2], 63);
        tmp.data_64[2] = ror_help(left->data_64[0], left->data_64[3], 63);
        tmp.data_64[3] = ror_help(left->data_64[1], left->data_64[0], 63);
        AND512(&tmp,left);
        // shift512(shift_5_256[4],left,&tmp1);
        tmp1.data_64[0] = ror_help(left->data_64[2], left->data_64[1], 59);
        tmp1.data_64[1] = ror_help(left->data_64[3], left->data_64[2], 59);
        tmp1.data_64[2] = ror_help(left->data_64[0], left->data_64[3], 59);
        tmp1.data_64[3] = ror_help(left->data_64[1], left->data_64[0], 59);
        XOR3(right,&tmp,&tmp1);
        
        //apply theta to left branch
        // shift512(shift_7_256[4],left,&tmp);
        tmp.data_64[0] = ror_help(left->data_64[0], left->data_64[3], 57);
        tmp.data_64[1] = ror_help(left->data_64[1], left->data_64[0], 57);
        tmp.data_64[2] = ror_help(left->data_64[2], left->data_64[1], 57);
        tmp.data_64[3] = ror_help(left->data_64[3], left->data_64[2], 57);
        // shift512(shift_32_256[4],left,&tmp1);
        tmp1.data_64[0] = ror_help(left->data_64[1], left->data_64[0], 32);
        tmp1.data_64[1] = ror_help(left->data_64[2], left->data_64[1], 32);
        tmp1.data_64[2] = ror_help(left->data_64[3], left->data_64[2], 32);
        tmp1.data_64[3] = ror_help(left->data_64[0], left->data_64[3], 32);
        XOR3(left,&tmp,&tmp1);
        // ADD_CST_512_opt(6,left);
        left->data_64[0] ^= 0x8000000000000000;
        left->data_64[1] ^= 0x8000000080000000;
        left->data_64[2] ^= 0x8000000080000000;
        left->data_64[3] ^= 0x8000000000000000;


        // shift512(shift_1_256[3],right,&tmp);
        tmp.data_64[0] = ror_help(right->data_64[0], right->data_64[3], 49);
        tmp.data_64[1] = ror_help(right->data_64[1], right->data_64[0], 49);
        tmp.data_64[2] = ror_help(right->data_64[2], right->data_64[1], 49);
        tmp.data_64[3] = ror_help(right->data_64[3], right->data_64[2], 49);
        AND512(&tmp,right);
        // shift512(shift_5_256[3],right,&tmp1);
        tmp1.data_64[0] = ror_help(right->data_64[1], right->data_64[0], 53);
        tmp1.data_64[1] = ror_help(right->data_64[2], right->data_64[1], 53);
        tmp1.data_64[2] = ror_help(right->data_64[3], right->data_64[2], 53);
        tmp1.data_64[3] = ror_help(right->data_64[0], right->data_64[3], 53);
        XOR3(left,&tmp,&tmp1);
        
        //apply theta to left branch
        // shift512(shift_7_256[3],right,&tmp);
        tmp.data_64[0] = ror_help(right->data_64[3], right->data_64[2], 23);
        tmp.data_64[1] = ror_help(right->data_64[0], right->data_64[3], 23);
        tmp.data_64[2] = ror_help(right->data_64[1], right->data_64[0], 23);
        tmp.data_64[3] = ror_help(right->data_64[2], right->data_64[1], 23);
        // shift512(shift_32_256[9],right,&tmp1);
        tmp1.data_64[0] = ror_help(right->data_64[0], right->data_64[3], 32);
        tmp1.data_64[1] = ror_help(right->data_64[1], right->data_64[0], 32);
        tmp1.data_64[2] = ror_help(right->data_64[2], right->data_64[1], 32);
        tmp1.data_64[3] = ror_help(right->data_64[3], right->data_64[2], 32);
        XOR3(right,&tmp,&tmp1);
        // ADD_CST_512_opt((6<<1)+1,right);
        right->data_64[0] ^= 0x8000000080000000;
        right->data_64[1] ^= 0x8000000080000000;
        right->data_64[2] ^= 0x80000000;
        right->data_64[3] ^= 0x80000000;
        
        
        //apply F function to the right branch
        // shift512(shift_1_256[2],left,&tmp);
        tmp.data_64[0] = ror_help(left->data_64[1], left->data_64[0], 31);
        tmp.data_64[1] = ror_help(left->data_64[2], left->data_64[1], 31);
        tmp.data_64[2] = ror_help(left->data_64[3], left->data_64[2], 31);
        tmp.data_64[3] = ror_help(left->data_64[0], left->data_64[3], 31);
        AND512(&tmp,left);
        // shift512(shift_5_256[2],left,&tmp1);
        tmp1.data_64[0] = ror_help(left->data_64[3], left->data_64[2], 27);
        tmp1.data_64[1] = ror_help(left->data_64[0], left->data_64[3], 27);
        tmp1.data_64[2] = ror_help(left->data_64[1], left->data_64[0], 27);
        tmp1.data_64[3] = ror_help(left->data_64[2], left->data_64[1], 27);
        XOR3(right,&tmp,&tmp1);
        
        //apply theta to left branch
        // shift512(shift_7_256[2],left,&tmp);
        tmp.data_64[0] = ror_help(left->data_64[0], left->data_64[3], 25);
        tmp.data_64[1] = ror_help(left->data_64[1], left->data_64[0], 25);
        tmp.data_64[2] = ror_help(left->data_64[2], left->data_64[1], 25);
        tmp.data_64[3] = ror_help(left->data_64[3], left->data_64[2], 25);
        // shift512(shift_32_256[2],left,&tmp1);
        tmp1.data_64[0] = ror_help(left->data_64[1], left->data_64[0], 32);
        tmp1.data_64[1] = ror_help(left->data_64[2], left->data_64[1], 32);
        tmp1.data_64[2] = ror_help(left->data_64[3], left->data_64[2], 32);
        tmp1.data_64[3] = ror_help(left->data_64[0], left->data_64[3], 32);
        XOR3(left,&tmp,&tmp1);
        // ADD_CST_512_opt(7,left);
        left->data_64[0] ^= 0x80000000;
        left->data_64[1] ^= 0x80000000;
        left->data_64[2] ^= 0x8000000000000000;
        left->data_64[3] ^= 0x0;


        // shift512(shift_1_256[1],right,&tmp);
        tmp.data_64[0] = ror_help(right->data_64[0], right->data_64[3], 17);
        tmp.data_64[1] = ror_help(right->data_64[1], right->data_64[0], 17);
        tmp.data_64[2] = ror_help(right->data_64[2], right->data_64[1], 17);
        tmp.data_64[3] = ror_help(right->data_64[3], right->data_64[2], 17);
        AND512(&tmp,right);
        // shift512(shift_5_256[1],right,&tmp1);
        tmp1.data_64[0] = ror_help(right->data_64[3], right->data_64[2], 21);
        tmp1.data_64[1] = ror_help(right->data_64[0], right->data_64[3], 21);
        tmp1.data_64[2] = ror_help(right->data_64[1], right->data_64[0], 21);
        tmp1.data_64[3] = ror_help(right->data_64[2], right->data_64[1], 21);
        XOR3(left,&tmp,&tmp1);
        
        //apply theta to left branch
        // shift512(shift_7_256[1],right,&tmp);
        tmp.data_64[0] = ror_help(right->data_64[3], right->data_64[2], 55);
        tmp.data_64[1] = ror_help(right->data_64[0], right->data_64[3], 55);
        tmp.data_64[2] = ror_help(right->data_64[1], right->data_64[0], 55);
        tmp.data_64[3] = ror_help(right->data_64[2], right->data_64[1], 55);
        // shift512(shift_32_256[9],right,&tmp1);
        tmp1.data_64[0] = ror_help(right->data_64[0], right->data_64[3], 32);
        tmp1.data_64[1] = ror_help(right->data_64[1], right->data_64[0], 32);
        tmp1.data_64[2] = ror_help(right->data_64[2], right->data_64[1], 32);
        tmp1.data_64[3] = ror_help(right->data_64[3], right->data_64[2], 32);
        XOR3(right,&tmp,&tmp1);
        // ADD_CST_512_opt((7<<1)+1,right);
        right->data_64[0] ^= 0x8000000080000000;
        right->data_64[1] ^= 0x8000000080000000;
        right->data_64[2] ^= 0x8000000080000000;
        right->data_64[3] ^= 0x0;


}

#endif