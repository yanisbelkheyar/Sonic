#ifndef ROUND_PROCRASTINATE
#define ROUND_PROCRASTINATE

#include "function.h"

//__attribute__ ((__target__ ("no-avx")))
 void sonic_encrypt_512_procrastinate(h_state512 left, h_state512 right){

    h_state512 tmp = {.data_64 = {0,0,0,0},.size_64=4};
    h_state512 tmp1 = {.data_64 = {0,0,0,0},.size_64=4};
    

        //apply F function to the right branch
        //tmp.data_64[0] = ror_help_inter(left.data_64[3],1);
        //tmp.data_64[1] = ror_help_inter(left.data_64[0],0);
        //tmp.data_64[2] = ror_help_inter(left.data_64[1],0);
        //tmp.data_64[3] = ror_help_inter(left.data_64[2],0);
        //
        ////AND512(tmp,left);
        //// shift512(shift_5_256[16],left,tmp1);
        //tmp1.data_64[0] = ror_help_inter(left.data_64[3],2);
        //tmp1.data_64[1] = ror_help_inter(left.data_64[0],1);
        //tmp1.data_64[2] = ror_help_inter(left.data_64[1],1);
        //tmp1.data_64[3] = ror_help_inter(left.data_64[2],1);
        ////XOR3(right,tmp,tmp1);
        //AND_XOR(right,tmp,left,tmp1);

        right.data_64[0] ^= (ror_help_inter(left.data_64[3],1) & left.data_64[0]) ^ ror_help_inter(left.data_64[3],2);
        right.data_64[1] ^= (ror_help_inter(left.data_64[0],0) & left.data_64[1]) ^ ror_help_inter(left.data_64[0],1);
        right.data_64[2] ^= (ror_help_inter(left.data_64[1],0) & left.data_64[2]) ^ ror_help_inter(left.data_64[1],1);
        right.data_64[3] ^= (ror_help_inter(left.data_64[2],0) & left.data_64[3]) ^ ror_help_inter(left.data_64[2],1);
        
        //apply theta to left branch
        // shift512(shift_7_256[16],left,tmp);
        //tmp.data_64[0] = ror_help_inter(left.data_64[1],2);
        //tmp.data_64[1] = ror_help_inter(left.data_64[2],2);
        //tmp.data_64[2] = ror_help_inter(left.data_64[3],2);
        //tmp.data_64[3] = ror_help_inter(left.data_64[0],1);
        //// shift512(shift_32_256[16],left,tmp1);
        //tmp1.data_64[0] = ror_help_inter(left.data_64[0],8);
        //tmp1.data_64[1] = ror_help_inter(left.data_64[1],8);
        //tmp1.data_64[2] = ror_help_inter(left.data_64[2],8);
        //tmp1.data_64[3] = ror_help_inter(left.data_64[3],8);
        //XOR3(left,tmp,tmp1);

        // ADD_CST_512_opt(0,left);
        left.data_64[0] ^= ror_help_inter(left.data_64[1],2) ^ ror_help_inter(left.data_64[0],8) ^ 0x8000000080000000;
        left.data_64[1] ^= ror_help_inter(left.data_64[2],2) ^ ror_help_inter(left.data_64[1],8) ^ 0x80000000;
        left.data_64[1] ^= ror_help_inter(left.data_64[3],2) ^ ror_help_inter(left.data_64[2],8) ^ 0x0;
        left.data_64[3] ^= ror_help_inter(left.data_64[0],1) ^ ror_help_inter(left.data_64[3],8) ^ 0x8000000000000000;


        // shift512(shift_1_256[15],right,tmp);
        //tmp.data_64[0] = ror_help_inter(right.data_64[1],4);
        //tmp.data_64[1] = ror_help_inter(right.data_64[2],4);
        //tmp.data_64[2] = ror_help_inter(right.data_64[3],4);
        //tmp.data_64[3] = ror_help_inter(right.data_64[0],3);
        ////AND512(tmp,right);
        //// shift512(shift_5_256[15],right,tmp1);
        //tmp1.data_64[0] = ror_help_inter(right.data_64[1],19);
        //tmp1.data_64[1] = ror_help_inter(right.data_64[2],19);
        //tmp1.data_64[2] = ror_help_inter(right.data_64[3],19);
        //tmp1.data_64[3] = ror_help_inter(right.data_64[0],18);
        ////XOR3(left,tmp,tmp1);
        //AND_XOR(left,tmp,right,tmp1);

        left.data_64[0] ^= (ror_help_inter(right.data_64[1],4) & right.data_64[0]) ^ ror_help_inter(right.data_64[1],19);  
        left.data_64[1] ^= (ror_help_inter(right.data_64[2],4) & right.data_64[1]) ^ ror_help_inter(right.data_64[2],19); 
        left.data_64[2] ^= (ror_help_inter(right.data_64[3],4) & right.data_64[2]) ^ ror_help_inter(right.data_64[3],19); 
        left.data_64[3] ^= (ror_help_inter(right.data_64[0],3) & right.data_64[3]) ^ ror_help_inter(right.data_64[0],18); 


        //apply theta to left branch
        // shift512(shift_7_256[15],right,tmp);
        //tmp.data_64[0] = ror_help_inter(right.data_64[3],27);
        //tmp.data_64[1] = ror_help_inter(right.data_64[0],26);
        //tmp.data_64[2] = ror_help_inter(right.data_64[1],26);
        //tmp.data_64[3] = ror_help_inter(right.data_64[2],26);
        //// shift512(shift_32_256[15],right,tmp1);
        //tmp1.data_64[0] = ror_help_inter(right.data_64[0],56);
        //tmp1.data_64[1] = ror_help_inter(right.data_64[1],56);
        //tmp1.data_64[2] = ror_help_inter(right.data_64[2],56);
        //tmp1.data_64[3] = ror_help_inter(right.data_64[3],56);
        //XOR3(right,tmp,tmp1);
        // ADD_CST_512_opt((0<<1)+1,right);
        right.data_64[0] ^= ror_help_inter(right.data_64[3],27) ^ ror_help_inter(right.data_64[0],56) ^ 0x8000000000000000;
        right.data_64[1] ^= ror_help_inter(right.data_64[0],26) ^ ror_help_inter(right.data_64[1],56) ^ 0x8000000080000000;
        right.data_64[2] ^= ror_help_inter(right.data_64[1],26) ^ ror_help_inter(right.data_64[2],56) ^ 0x8000000080000000;
        right.data_64[3] ^= ror_help_inter(right.data_64[2],26) ^ ror_help_inter(right.data_64[3],56) ^ 0x80000000;
        
        
        //apply F function to the right branch
        // shift512(shift_1_256[14],left,tmp);
        //tmp.data_64[0] = ror_help_inter(left.data_64[3],57);
        //tmp.data_64[1] = ror_help_inter(left.data_64[0],56);
        //tmp.data_64[2] = ror_help_inter(left.data_64[1],56);
        //tmp.data_64[3] = ror_help_inter(left.data_64[2],56);
        ////AND512(tmp,left);
        //// shift512(shift_5_256[14],left,tmp1);
        //tmp1.data_64[0] = ror_help_inter(left.data_64[3],26);
        //tmp1.data_64[1] = ror_help_inter(left.data_64[0],25);
        //tmp1.data_64[2] = ror_help_inter(left.data_64[1],25);
        //tmp1.data_64[3] = ror_help_inter(left.data_64[2],25);
        ////XOR3(right,tmp,tmp1);
        //AND_XOR(right,tmp,left,tmp1);

        right.data_64[0] ^= (ror_help_inter(left.data_64[3],57) & left.data_64[0]) ^ ror_help_inter(left.data_64[3],26); 
        right.data_64[1] ^= (ror_help_inter(left.data_64[0],56) & left.data_64[1]) ^ ror_help_inter(left.data_64[0],25); 
        right.data_64[2] ^= (ror_help_inter(left.data_64[1],56) & left.data_64[2]) ^ ror_help_inter(left.data_64[1],25); 
        right.data_64[3] ^= (ror_help_inter(left.data_64[2],56) & left.data_64[3]) ^ ror_help_inter(left.data_64[2],25); 
        //apply theta to left branch
        // shift512(shift_7_256[14],left,tmp);
        //tmp.data_64[0] = ror_help_inter(left.data_64[1],10);
        //tmp.data_64[1] = ror_help_inter(left.data_64[2],10);
        //tmp.data_64[2] = ror_help_inter(left.data_64[3],10);
        //tmp.data_64[3] = ror_help_inter(left.data_64[0],9);
        //// shift512(shift_32_256[14],left,tmp1);
        //tmp1.data_64[0] = ror_help_inter(left.data_64[0],8);
        //tmp1.data_64[1] = ror_help_inter(left.data_64[1],8);
        //tmp1.data_64[2] = ror_help_inter(left.data_64[2],8);
        //tmp1.data_64[3] = ror_help_inter(left.data_64[3],8);
        //XOR3(left,tmp,tmp1);
        // ADD_CST_512_opt(1,left);
        left.data_64[0] ^= ror_help_inter(left.data_64[1],10) ^ror_help_inter(left.data_64[0],8) ^  0x8000000000000000;
        left.data_64[1] ^= ror_help_inter(left.data_64[2],10) ^ror_help_inter(left.data_64[1],8) ^  0x8000000080000000;
        left.data_64[2] ^= ror_help_inter(left.data_64[3],10) ^ror_help_inter(left.data_64[2],8) ^  0x8000000080000000;
        left.data_64[3] ^= ror_help_inter(left.data_64[0],9) ^ ror_help_inter(left.data_64[3],8) ^ 0x80000000;

        // shift512(shift_1_256[13],right,tmp);
        //tmp.data_64[0] = ror_help_inter(right.data_64[1],12);
        //tmp.data_64[1] = ror_help_inter(right.data_64[2],12);
        //tmp.data_64[2] = ror_help_inter(right.data_64[3],12);
        //tmp.data_64[3] = ror_help_inter(right.data_64[0],11);
        ////AND512(tmp,right);
        //// shift512(shift_5_256[13],right,tmp1);
        //tmp1.data_64[0] = ror_help_inter(right.data_64[1],59);
        //tmp1.data_64[1] = ror_help_inter(right.data_64[2],59);
        //tmp1.data_64[2] = ror_help_inter(right.data_64[3],59);
        //tmp1.data_64[3] = ror_help_inter(right.data_64[0],58);
        ////XOR3(left,tmp,tmp1);
        //AND_XOR(left,tmp,right,tmp1);

        left.data_64[0] ^= (ror_help_inter(right.data_64[1],12) & right.data_64[0]) ^ ror_help_inter(right.data_64[1],59); 
        left.data_64[1] ^= (ror_help_inter(right.data_64[2],12) & right.data_64[1]) ^ ror_help_inter(right.data_64[2],59); 
        left.data_64[2] ^= (ror_help_inter(right.data_64[3],12) & right.data_64[2]) ^ ror_help_inter(right.data_64[3],59); 
        left.data_64[3] ^= (ror_help_inter(right.data_64[0],11) & right.data_64[3]) ^ ror_help_inter(right.data_64[0],58);  

        //apply theta to left branch
        // shift512(shift_7_256[13],right,tmp);
        //tmp.data_64[0] = ror_help_inter(right.data_64[3],19);
        //tmp.data_64[1] = ror_help_inter(right.data_64[0],18);
        //tmp.data_64[2] = ror_help_inter(right.data_64[1],18);
        //tmp.data_64[3] = ror_help_inter(right.data_64[2],18);
        //// shift512(shift_32_256[13],right,tmp1);
        //tmp1.data_64[0] = ror_help_inter(right.data_64[0],56);
        //tmp1.data_64[1] = ror_help_inter(right.data_64[1],56);
        //tmp1.data_64[2] = ror_help_inter(right.data_64[2],56);
        //tmp1.data_64[3] = ror_help_inter(right.data_64[3],56);
        //XOR3(right,tmp,tmp1);
        // ADD_CST_512_opt((1<<1)+1,right);
        right.data_64[0] ^= ror_help_inter(right.data_64[3],19) ^ ror_help_inter(right.data_64[0],56) ^ 0x0;
        right.data_64[1] ^= ror_help_inter(right.data_64[0],18) ^ ror_help_inter(right.data_64[1],56) ^ 0x80000000;
        right.data_64[2] ^= ror_help_inter(right.data_64[1],18) ^ ror_help_inter(right.data_64[2],56) ^ 0x8000000000000000;
        right.data_64[3] ^= ror_help_inter(right.data_64[2],18) ^ ror_help_inter(right.data_64[3],56) ^ 0x80000000;
        
        //apply F function to the right branch
        // shift512(shift_1_256[12],left,tmp);
        //tmp.data_64[0] = ror_help_inter(left.data_64[3],49);
        //tmp.data_64[1] = ror_help_inter(left.data_64[0],48);
        //tmp.data_64[2] = ror_help_inter(left.data_64[1],48);
        //tmp.data_64[3] = ror_help_inter(left.data_64[2],48);
        ////AND512(tmp,left);
        //// shift512(shift_5_256[12],left,tmp1);
        //tmp1.data_64[0] = ror_help_inter(left.data_64[3],50);
        //tmp1.data_64[1] = ror_help_inter(left.data_64[0],49);
        //tmp1.data_64[2] = ror_help_inter(left.data_64[1],49);
        //tmp1.data_64[3] = ror_help_inter(left.data_64[2],49);
        ////XOR3(right,tmp,tmp1);
        //AND_XOR(right,tmp,left,tmp1);

        right.data_64[0] ^= (ror_help_inter(left.data_64[3],49) & left.data_64[0]) ^ ror_help_inter(left.data_64[3],50); 
        right.data_64[1] ^= (ror_help_inter(left.data_64[0],48) & left.data_64[1]) ^ ror_help_inter(left.data_64[0],49); 
        right.data_64[2] ^= (ror_help_inter(left.data_64[1],48) & left.data_64[2]) ^ ror_help_inter(left.data_64[1],49); 
        right.data_64[3] ^= (ror_help_inter(left.data_64[2],48) & left.data_64[3]) ^ ror_help_inter(left.data_64[2],49); 

        
        //apply theta to left branch
        // shift512(shift_7_256[12],left,tmp);
        //tmp.data_64[0] = ror_help_inter(left.data_64[1],18);
        //tmp.data_64[1] = ror_help_inter(left.data_64[2],18);
        //tmp.data_64[2] = ror_help_inter(left.data_64[3],18);
        //tmp.data_64[3] = ror_help_inter(left.data_64[0],17);
        //// shift512(shift_32_256[12],left,tmp1);
        //tmp1.data_64[0] = ror_help_inter(left.data_64[0],8);
        //tmp1.data_64[1] = ror_help_inter(left.data_64[1],8);
        //tmp1.data_64[2] = ror_help_inter(left.data_64[2],8);
        //tmp1.data_64[3] = ror_help_inter(left.data_64[3],8);
        //XOR3(left,tmp,tmp1);
        // ADD_CST_512_opt(2,left);
        left.data_64[0] ^= ror_help_inter(left.data_64[1],18) ^ ror_help_inter(left.data_64[0],8) ^ 0x8000000000000000;
        left.data_64[1] ^= ror_help_inter(left.data_64[2],18) ^ ror_help_inter(left.data_64[1],8) ^ 0x0;
        left.data_64[2] ^= ror_help_inter(left.data_64[3],18) ^ ror_help_inter(left.data_64[2],8) ^ 0x8000000080000000;
        left.data_64[3] ^= ror_help_inter(left.data_64[0],17) ^ ror_help_inter(left.data_64[3],8) ^ 0x8000000000000000;


        // shift512(shift_1_256[11],right,tmp);
        //tmp.data_64[0] = ror_help_inter(right.data_64[1],20);
        //tmp.data_64[1] = ror_help_inter(right.data_64[2],20);
        //tmp.data_64[2] = ror_help_inter(right.data_64[3],20);
        //tmp.data_64[3] = ror_help_inter(right.data_64[0],19);
        ////AND512(tmp,right);
        //// shift512(shift_5_256[11],right,tmp1);
        //tmp1.data_64[0] = ror_help_inter(right.data_64[1],35);
        //tmp1.data_64[1] = ror_help_inter(right.data_64[2],35);
        //tmp1.data_64[2] = ror_help_inter(right.data_64[3],35);
        //tmp1.data_64[3] = ror_help_inter(right.data_64[0],34);
        ////XOR3(left,tmp,tmp1);
        //AND_XOR(left,tmp,right,tmp1);
        
        left.data_64[0] ^= (ror_help_inter(right.data_64[1],20) & right.data_64[0]) ^ ror_help_inter(right.data_64[1],35); 
        left.data_64[1] ^= (ror_help_inter(right.data_64[2],20) & right.data_64[1]) ^ ror_help_inter(right.data_64[2],35); 
        left.data_64[2] ^= (ror_help_inter(right.data_64[3],20) & right.data_64[2]) ^ ror_help_inter(right.data_64[3],35); 
        left.data_64[3] ^= (ror_help_inter(right.data_64[0],19) & right.data_64[3]) ^ ror_help_inter(right.data_64[0],34); 
        //apply theta to left branch
        // shift512(shift_7_256[11],right,tmp);
        //tmp.data_64[0] = ror_help_inter(right.data_64[3],11);
        //tmp.data_64[1] = ror_help_inter(right.data_64[0],10);
        //tmp.data_64[2] = ror_help_inter(right.data_64[1],10);
        //tmp.data_64[3] = ror_help_inter(right.data_64[2],10);
        //// shift512(shift_32_256[11],right,tmp1);
        //tmp1.data_64[0] = ror_help_inter(right.data_64[0],56);
        //tmp1.data_64[1] = ror_help_inter(right.data_64[1],56);
        //tmp1.data_64[2] = ror_help_inter(right.data_64[2],56);
        //tmp1.data_64[3] = ror_help_inter(right.data_64[3],56);
        //XOR3(right,tmp,tmp1);
        // ADD_CST_512_opt((2<<1)+1,right);
        right.data_64[0] ^= ror_help_inter(right.data_64[3],11) ^ ror_help_inter(right.data_64[0],56) ^ 0x8000000000000000;
        right.data_64[1] ^= ror_help_inter(right.data_64[0],10) ^ ror_help_inter(right.data_64[1],56) ^ 0x8000000000000000;
        right.data_64[2] ^= ror_help_inter(right.data_64[1],10) ^ ror_help_inter(right.data_64[2],56) ^ 0x8000000080000000;
        right.data_64[3] ^= ror_help_inter(right.data_64[2],10) ^ ror_help_inter(right.data_64[3],56) ^ 0x80000000;
        
        
        //apply F function to the right branch
        // shift512(shift_1_256[10],left,tmp);
        //tmp.data_64[0] = ror_help_inter(left.data_64[3],41);
        //tmp.data_64[1] = ror_help_inter(left.data_64[0],40);
        //tmp.data_64[2] = ror_help_inter(left.data_64[1],40);
        //tmp.data_64[3] = ror_help_inter(left.data_64[2],40);
        ////AND512(tmp,left);
        //// shift512(shift_5_256[10],left,tmp1);
        //tmp1.data_64[0] = ror_help_inter(left.data_64[3],10);
        //tmp1.data_64[1] = ror_help_inter(left.data_64[0],9);
        //tmp1.data_64[2] = ror_help_inter(left.data_64[1],9);
        //tmp1.data_64[3] = ror_help_inter(left.data_64[2],9);
        ////XOR3(right,tmp,tmp1);
        //AND_XOR(right,tmp,left,tmp1);

        right.data_64[0] ^= (ror_help_inter(left.data_64[3],41) & left.data_64[0]) ^ ror_help_inter(left.data_64[3],10); 
        right.data_64[1] ^= (ror_help_inter(left.data_64[0],40) & left.data_64[1]) ^ ror_help_inter(left.data_64[0],9); 
        right.data_64[2] ^= (ror_help_inter(left.data_64[1],40) & left.data_64[2]) ^ ror_help_inter(left.data_64[1],9); 
        right.data_64[3] ^= (ror_help_inter(left.data_64[2],40) & left.data_64[3]) ^ ror_help_inter(left.data_64[2],9); 
        //apply theta to left branch
        // shift512(shift_7_256[10],left,tmp);
        //tmp.data_64[0] = ror_help_inter(left.data_64[1],26);
        //tmp.data_64[1] = ror_help_inter(left.data_64[2],26);
        //tmp.data_64[2] = ror_help_inter(left.data_64[3],26);
        //tmp.data_64[3] = ror_help_inter(left.data_64[0],25);
        //// shift512(shift_32_256[10],left,tmp1);
        //tmp1.data_64[0] = ror_help_inter(left.data_64[0],8);
        //tmp1.data_64[1] = ror_help_inter(left.data_64[1],8);
        //tmp1.data_64[2] = ror_help_inter(left.data_64[2],8);
        //tmp1.data_64[3] = ror_help_inter(left.data_64[3],8);
        //XOR3(left,tmp,tmp1);
        // ADD_CST_512_opt(3,left);
        left.data_64[0] ^= ror_help_inter(left.data_64[1],26) ^ ror_help_inter(left.data_64[0],8) ^ 0x0;
        left.data_64[1] ^= ror_help_inter(left.data_64[2],26) ^ ror_help_inter(left.data_64[1],8) ^ 0x80000000;
        left.data_64[2] ^= ror_help_inter(left.data_64[3],26) ^ ror_help_inter(left.data_64[2],8) ^ 0x8000000000000000;
        left.data_64[3] ^= ror_help_inter(left.data_64[0],25) ^ ror_help_inter(left.data_64[3],8) ^ 0x80000000;


        // shift512(shift_1_256[9],right,tmp);
        //tmp.data_64[0] = ror_help_inter(right.data_64[1],28);
        //tmp.data_64[1] = ror_help_inter(right.data_64[2],28);
        //tmp.data_64[2] = ror_help_inter(right.data_64[3],28);
        //tmp.data_64[3] = ror_help_inter(right.data_64[0],27);
        ////AND512(tmp,right);
        //// shift512(shift_5_256[9],right,tmp1);
        //tmp1.data_64[0] = ror_help_inter(right.data_64[1],11);
        //tmp1.data_64[1] = ror_help_inter(right.data_64[2],11);
        //tmp1.data_64[2] = ror_help_inter(right.data_64[3],11);
        //tmp1.data_64[3] = ror_help_inter(right.data_64[0],10);
        ////XOR3(left,tmp,tmp1);
        //AND_XOR(left,tmp,right,tmp1);

        left.data_64[0] ^= (ror_help_inter(right.data_64[1],28) & right.data_64[0]) ^ ror_help_inter(right.data_64[1],11); 
        left.data_64[1] ^= (ror_help_inter(right.data_64[2],28) & right.data_64[1]) ^ ror_help_inter(right.data_64[2],11);
        left.data_64[2] ^= (ror_help_inter(right.data_64[3],28) & right.data_64[2]) ^ ror_help_inter(right.data_64[3],11);
        left.data_64[3] ^= (ror_help_inter(right.data_64[0],27) & right.data_64[3]) ^ ror_help_inter(right.data_64[0],10);
        //apply theta to left branch
        // shift512(shift_7_256[9],right,tmp);
        //tmp.data_64[0] = ror_help_inter(right.data_64[3],3);
        //tmp.data_64[1] = ror_help_inter(right.data_64[0],2);
        //tmp.data_64[2] = ror_help_inter(right.data_64[1],2);
        //tmp.data_64[3] = ror_help_inter(right.data_64[2],2);
        //// shift512(shift_32_256[9],right,tmp1);
        //tmp1.data_64[0] = ror_help_inter(right.data_64[0],56);
        //tmp1.data_64[1] = ror_help_inter(right.data_64[1],56);
        //tmp1.data_64[2] = ror_help_inter(right.data_64[2],56);
        //tmp1.data_64[3] = ror_help_inter(right.data_64[3],56);
        //XOR3(right,tmp,tmp1);
        // ADD_CST_512_opt((3<<1)+1,right);
        right.data_64[0] ^= ror_help_inter(right.data_64[3],3) ^ ror_help_inter(right.data_64[0],56) ^ 0x80000000;
        right.data_64[1] ^= ror_help_inter(right.data_64[0],2) ^ ror_help_inter(right.data_64[1],56) ^ 0x80000000;
        right.data_64[2] ^= ror_help_inter(right.data_64[1],2) ^ ror_help_inter(right.data_64[2],56) ^ 0x8000000000000000;
        right.data_64[3] ^= ror_help_inter(right.data_64[2],2) ^ ror_help_inter(right.data_64[3],56) ^ 0x0;
        
        
        //apply F function to the right branch
        // shift512(shift_1_256[8],left,tmp);
        //tmp.data_64[0] = ror_help_inter(left.data_64[3],33);
        //tmp.data_64[1] = ror_help_inter(left.data_64[0],32);
        //tmp.data_64[2] = ror_help_inter(left.data_64[1],32);
        //tmp.data_64[3] = ror_help_inter(left.data_64[2],32);
        ////AND512(tmp,left);
        //// shift512(shift_5_256[8],left,tmp1);
        //tmp1.data_64[0] = ror_help_inter(left.data_64[3],34);
        //tmp1.data_64[1] = ror_help_inter(left.data_64[0],33);
        //tmp1.data_64[2] = ror_help_inter(left.data_64[1],33);
        //tmp1.data_64[3] = ror_help_inter(left.data_64[2],33);
        ////XOR3(right,tmp,tmp1);
        //AND_XOR(right,tmp,left,tmp1);

        right.data_64[0] ^= (ror_help_inter(left.data_64[3],33) & left.data_64[0]) ^ ror_help_inter(left.data_64[3],34);
        right.data_64[1] ^= (ror_help_inter(left.data_64[0],32) & left.data_64[1]) ^ ror_help_inter(left.data_64[0],33);
        right.data_64[2] ^= (ror_help_inter(left.data_64[1],32) & left.data_64[2]) ^ ror_help_inter(left.data_64[1],33);
        right.data_64[3] ^= (ror_help_inter(left.data_64[2],32) & left.data_64[3]) ^ ror_help_inter(left.data_64[2],33);
        //apply theta to left branch
        // shift512(shift_7_256[8],left,tmp);
        //tmp.data_64[0] = ror_help_inter(left.data_64[1],34);
        //tmp.data_64[1] = ror_help_inter(left.data_64[2],34);
        //tmp.data_64[2] = ror_help_inter(left.data_64[3],34);
        //tmp.data_64[3] = ror_help_inter(left.data_64[0],33);
        //// shift512(shift_32_256[8],left,tmp1);
        //tmp1.data_64[0] = ror_help_inter(left.data_64[0],8);
        //tmp1.data_64[1] = ror_help_inter(left.data_64[1],8);
        //tmp1.data_64[2] = ror_help_inter(left.data_64[2],8);
        //tmp1.data_64[3] = ror_help_inter(left.data_64[3],8);
        //XOR3(left,tmp,tmp1);
        // ADD_CST_512_opt(4,left);
        left.data_64[0] ^= ror_help_inter(left.data_64[1],34) ^ ror_help_inter(left.data_64[0],8) ^ 0x80000000;
        left.data_64[1] ^= ror_help_inter(left.data_64[2],34) ^ ror_help_inter(left.data_64[1],8) ^ 0x80000000;
        left.data_64[2] ^= ror_help_inter(left.data_64[3],34) ^ ror_help_inter(left.data_64[2],8) ^ 0x0;
        left.data_64[3] ^= ror_help_inter(left.data_64[0],33) ^ ror_help_inter(left.data_64[3],8) ^ 0x8000000000000000;

        // shift512(shift_1_256[7],right,tmp);
        //tmp.data_64[0] = ror_help_inter(right.data_64[1],36);
        //tmp.data_64[1] = ror_help_inter(right.data_64[2],36);
        //tmp.data_64[2] = ror_help_inter(right.data_64[3],36);
        //tmp.data_64[3] = ror_help_inter(right.data_64[0],35);
        ////AND512(tmp,right);
        //// shift512(shift_5_256[7],right,tmp1);
        //tmp1.data_64[0] = ror_help_inter(right.data_64[1],51);
        //tmp1.data_64[1] = ror_help_inter(right.data_64[2],51);
        //tmp1.data_64[2] = ror_help_inter(right.data_64[3],51);
        //tmp1.data_64[3] = ror_help_inter(right.data_64[0],50);
        ////XOR3(left,tmp,tmp1);
        //AND_XOR(left,tmp,right,tmp1);
        
        left.data_64[0] ^= (ror_help_inter(right.data_64[1],36) & right.data_64[0]) ^ ror_help_inter(right.data_64[1],51); 
        left.data_64[1] ^= (ror_help_inter(right.data_64[2],36) & right.data_64[1]) ^ ror_help_inter(right.data_64[2],51); 
        left.data_64[2] ^= (ror_help_inter(right.data_64[3],36) & right.data_64[2]) ^ ror_help_inter(right.data_64[3],51); 
        left.data_64[3] ^= (ror_help_inter(right.data_64[0],35) & right.data_64[3]) ^ ror_help_inter(right.data_64[0],50); 
        //apply theta to left branch
        // shift512(shift_7_256[7],right,tmp);
        //tmp.data_64[0] = ror_help_inter(right.data_64[3],59);
        //tmp.data_64[1] = ror_help_inter(right.data_64[0],58);
        //tmp.data_64[2] = ror_help_inter(right.data_64[1],58);
        //tmp.data_64[3] = ror_help_inter(right.data_64[2],58);
        //// shift512(shift_32_256[9],right,tmp1);
        //tmp1.data_64[0] = ror_help_inter(right.data_64[0],56);
        //tmp1.data_64[1] = ror_help_inter(right.data_64[1],56);
        //tmp1.data_64[2] = ror_help_inter(right.data_64[2],56);
        //tmp1.data_64[3] = ror_help_inter(right.data_64[3],56);
        //XOR3(right,tmp,tmp1);
        // ADD_CST_512_opt((4<<1)+1,right);
        right.data_64[0] ^= ror_help_inter(left.data_64[0],8) ^ ror_help_inter(right.data_64[0],56) ^ 0x8000000000000000;
        right.data_64[1] ^= ror_help_inter(left.data_64[1],8) ^ ror_help_inter(right.data_64[1],56) ^ 0x8000000000000000;
        right.data_64[2] ^= ror_help_inter(left.data_64[2],8) ^ ror_help_inter(right.data_64[2],56) ^ 0x80000000;
        right.data_64[3] ^= ror_help_inter(left.data_64[3],8) ^ ror_help_inter(right.data_64[3],56) ^ 0x0;
        
        
        //apply F function to the right branch
        // shift512(shift_1_256[6],left,tmp);
        //tmp.data_64[0] = ror_help_inter(left.data_64[3],25);
        //tmp.data_64[1] = ror_help_inter(left.data_64[0],24);
        //tmp.data_64[2] = ror_help_inter(left.data_64[1],24);
        //tmp.data_64[3] = ror_help_inter(left.data_64[2],24);
        ////AND512(tmp,left);
        //// shift512(shift_5_256[6],left,tmp1);
        //tmp1.data_64[0] = ror_help_inter(left.data_64[3],58);
        //tmp1.data_64[1] = ror_help_inter(left.data_64[0],57);
        //tmp1.data_64[2] = ror_help_inter(left.data_64[1],57);
        //tmp1.data_64[3] = ror_help_inter(left.data_64[2],57);
        ////XOR3(right,tmp,tmp1);
        //AND_XOR(right,tmp,left,tmp1);

        right.data_64[0] ^= (ror_help_inter(left.data_64[3],25) & left.data_64[0]) ^ ror_help_inter(left.data_64[3],58); 
        right.data_64[1] ^= (ror_help_inter(left.data_64[0],24) & left.data_64[1]) ^ ror_help_inter(left.data_64[0],57); 
        right.data_64[2] ^= (ror_help_inter(left.data_64[1],24) & left.data_64[2]) ^ ror_help_inter(left.data_64[1],57); 
        right.data_64[3] ^= (ror_help_inter(left.data_64[2],24) & left.data_64[3]) ^ ror_help_inter(left.data_64[2],57); 
        //apply theta to left branch
        // shift512(shift_7_256[6],left,tmp);
        //tmp.data_64[0] = ror_help_inter(left.data_64[1],42);
        //tmp.data_64[1] = ror_help_inter(left.data_64[2],42);
        //tmp.data_64[2] = ror_help_inter(left.data_64[3],42);
        //tmp.data_64[3] = ror_help_inter(left.data_64[0],41);
        //// shift512(shift_32_256[6],left,tmp1);
        //tmp1.data_64[0] = ror_help_inter(left.data_64[0],8);
        //tmp1.data_64[1] = ror_help_inter(left.data_64[1],8);
        //tmp1.data_64[2] = ror_help_inter(left.data_64[2],8);
        //tmp1.data_64[3] = ror_help_inter(left.data_64[3],8);
        //XOR3(left,tmp,tmp1);
        // ADD_CST_512_opt(5,left);
        left.data_64[0] ^= ror_help_inter(left.data_64[1],42) ^ ror_help_inter(left.data_64[0],8) ^ 0x8000000000000000;
        left.data_64[1] ^= ror_help_inter(left.data_64[2],42) ^ ror_help_inter(left.data_64[1],8) ^ 0x8000000000000000;
        left.data_64[2] ^= ror_help_inter(left.data_64[3],42) ^ ror_help_inter(left.data_64[2],8) ^ 0x8000000080000000;
        left.data_64[3] ^= ror_help_inter(left.data_64[0],41) ^ ror_help_inter(left.data_64[3],8) ^ 0x80000000;

        // shift512(shift_1_256[5],right,tmp);
        //tmp.data_64[0] = ror_help_inter(right.data_64[1],44);
        //tmp.data_64[1] = ror_help_inter(right.data_64[2],44);
        //tmp.data_64[2] = ror_help_inter(right.data_64[3],44);
        //tmp.data_64[3] = ror_help_inter(right.data_64[0],43);
        ////AND512(tmp,right);
        //// shift512(shift_5_256[5],right,tmp1);
        //tmp1.data_64[0] = ror_help_inter(right.data_64[1],27);
        //tmp1.data_64[1] = ror_help_inter(right.data_64[2],27);
        //tmp1.data_64[2] = ror_help_inter(right.data_64[3],27);
        //tmp1.data_64[3] = ror_help_inter(right.data_64[0],26);
        ////XOR3(left,tmp,tmp1);
        //AND_XOR(left,tmp,right,tmp1);

        left.data_64[0] ^= (ror_help_inter(right.data_64[1],44) & right.data_64[0]) ^ ror_help_inter(right.data_64[1],27);
        left.data_64[1] ^= (ror_help_inter(right.data_64[2],44) & right.data_64[1]) ^ ror_help_inter(right.data_64[2],27);
        left.data_64[2] ^= (ror_help_inter(right.data_64[3],44) & right.data_64[2]) ^ ror_help_inter(right.data_64[3],27);
        left.data_64[3] ^= (ror_help_inter(right.data_64[0],43) & right.data_64[3]) ^ ror_help_inter(right.data_64[0],26);


        //apply theta to left branch
        // shift512(shift_7_256[5],right,tmp);
        //tmp.data_64[0] = ror_help_inter(right.data_64[3],51);
        //tmp.data_64[1] = ror_help_inter(right.data_64[0],50);
        //tmp.data_64[2] = ror_help_inter(right.data_64[1],50);
        //tmp.data_64[3] = ror_help_inter(right.data_64[2],50);
        //// shift512(shift_32_256[9],right,tmp1);
        //tmp1.data_64[0] = ror_help_inter(right.data_64[0],56);
        //tmp1.data_64[1] = ror_help_inter(right.data_64[1],56);
        //tmp1.data_64[2] = ror_help_inter(right.data_64[2],56);
        //tmp1.data_64[3] = ror_help_inter(right.data_64[3],56);
        //XOR3(right,tmp,tmp1);
        // ADD_CST_512_opt((5<<1)+1,right);
        right.data_64[0] ^= ror_help_inter(right.data_64[3],51) ^ ror_help_inter(right.data_64[0],56) ^ 0x8000000000000000;
        right.data_64[1] ^= ror_help_inter(right.data_64[0],50) ^ ror_help_inter(right.data_64[1],56) ^ 0x8000000080000000;
        right.data_64[2] ^= ror_help_inter(right.data_64[1],50) ^ ror_help_inter(right.data_64[2],56) ^ 0x80000000;
        right.data_64[3] ^= ror_help_inter(right.data_64[2],50) ^ ror_help_inter(right.data_64[3],56) ^ 0x0;
        
        //apply F function to the right branch
        // shift512(shift_1_256[4],left,tmp);
        //tmp.data_64[0] = ror_help_inter(left.data_64[3],17);
        //tmp.data_64[1] = ror_help_inter(left.data_64[0],16);
        //tmp.data_64[2] = ror_help_inter(left.data_64[1],16);
        //tmp.data_64[3] = ror_help_inter(left.data_64[2],16);
        ////AND512(tmp,left);
        //// shift512(shift_5_256[4],left,tmp1);
        //tmp1.data_64[0] = ror_help_inter(left.data_64[3],18);
        //tmp1.data_64[1] = ror_help_inter(left.data_64[0],17);
        //tmp1.data_64[2] = ror_help_inter(left.data_64[1],17);
        //tmp1.data_64[3] = ror_help_inter(left.data_64[2],17);
        ////XOR3(right,tmp,tmp1);
        //AND_XOR(right,tmp,left,tmp1);

        right.data_64[0] ^= (ror_help_inter(left.data_64[3],17) & left.data_64[0]) ^ ror_help_inter(left.data_64[3],18); 
        right.data_64[1] ^= (ror_help_inter(left.data_64[0],16) & left.data_64[1]) ^ ror_help_inter(left.data_64[0],17); 
        right.data_64[2] ^= (ror_help_inter(left.data_64[1],16) & left.data_64[2]) ^ ror_help_inter(left.data_64[1],17); 
        right.data_64[3] ^= (ror_help_inter(left.data_64[2],16) & left.data_64[3]) ^ ror_help_inter(left.data_64[2],17); 
        //apply theta to left branch
        // shift512(shift_7_256[4],left,tmp);
        //tmp.data_64[0] = ror_help_inter(left.data_64[1],50);
        //tmp.data_64[1] = ror_help_inter(left.data_64[2],50);
        //tmp.data_64[2] = ror_help_inter(left.data_64[3],50);
        //tmp.data_64[3] = ror_help_inter(left.data_64[0],49);
        //// shift512(shift_32_256[4],left,tmp1);
        //tmp1.data_64[0] = ror_help_inter(left.data_64[0],8);
        //tmp1.data_64[1] = ror_help_inter(left.data_64[1],8);
        //tmp1.data_64[2] = ror_help_inter(left.data_64[2],8);
        //tmp1.data_64[3] = ror_help_inter(left.data_64[3],8);
        //XOR3(left,tmp,tmp1);
        // ADD_CST_512_opt(6,left);
        left.data_64[0] ^= ror_help_inter(left.data_64[1],50) ^ ror_help_inter(left.data_64[0],8) ^ 0x8000000000000000;
        left.data_64[1] ^= ror_help_inter(left.data_64[2],50) ^ ror_help_inter(left.data_64[1],8) ^ 0x8000000080000000;
        left.data_64[2] ^= ror_help_inter(left.data_64[3],50) ^ ror_help_inter(left.data_64[2],8) ^ 0x8000000080000000;
        left.data_64[3] ^= ror_help_inter(left.data_64[0],49) ^ ror_help_inter(left.data_64[3],8) ^ 0x8000000000000000;


        // shift512(shift_1_256[3],right,tmp);
        //tmp.data_64[0] = ror_help_inter(right.data_64[1],52);
        //tmp.data_64[1] = ror_help_inter(right.data_64[2],52);
        //tmp.data_64[2] = ror_help_inter(right.data_64[3],52);
        //tmp.data_64[3] = ror_help_inter(right.data_64[0],51);
        ////AND512(tmp,right);
        //// shift512(shift_5_256[3],right,tmp1);
        //tmp1.data_64[0] = ror_help_inter(right.data_64[1],3);
        //tmp1.data_64[1] = ror_help_inter(right.data_64[2],3);
        //tmp1.data_64[2] = ror_help_inter(right.data_64[3],3);
        //tmp1.data_64[3] = ror_help_inter(right.data_64[0],2);
        ////XOR3(left,tmp,tmp1);
        //AND_XOR(left,tmp,right,tmp1);

        left.data_64[0] ^= (ror_help_inter(right.data_64[1],52) & right.data_64[0]) ^ ror_help_inter(right.data_64[1],3);
        left.data_64[1] ^= (ror_help_inter(right.data_64[2],52) & right.data_64[1]) ^ ror_help_inter(right.data_64[2],3);
        left.data_64[2] ^= (ror_help_inter(right.data_64[3],52) & right.data_64[2]) ^ ror_help_inter(right.data_64[3],3);
        left.data_64[3] ^= (ror_help_inter(right.data_64[0],51) & right.data_64[3]) ^ ror_help_inter(right.data_64[0],2); 
        //apply theta to left branch
        // shift512(shift_7_256[3],right,tmp);
        //tmp.data_64[0] = ror_help_inter(right.data_64[3],43);
        //tmp.data_64[1] = ror_help_inter(right.data_64[0],42);
        //tmp.data_64[2] = ror_help_inter(right.data_64[1],42);
        //tmp.data_64[3] = ror_help_inter(right.data_64[2],42);
        //// shift512(shift_32_256[9],right,tmp1);
        //tmp1.data_64[0] = ror_help_inter(right.data_64[0],56);
        //tmp1.data_64[1] = ror_help_inter(right.data_64[1],56);
        //tmp1.data_64[2] = ror_help_inter(right.data_64[2],56);
        //tmp1.data_64[3] = ror_help_inter(right.data_64[3],56);
        //XOR3(right,tmp,tmp1);
        // ADD_CST_512_opt((6<<1)+1,right);
        right.data_64[0] ^= ror_help_inter(right.data_64[3],43) ^ ror_help_inter(right.data_64[0],56) ^ 0x8000000080000000;
        right.data_64[1] ^= ror_help_inter(right.data_64[0],42) ^ ror_help_inter(right.data_64[1],56) ^ 0x8000000080000000;
        right.data_64[2] ^= ror_help_inter(right.data_64[1],42) ^ ror_help_inter(right.data_64[2],56) ^ 0x80000000;
        right.data_64[3] ^= ror_help_inter(right.data_64[2],42) ^ ror_help_inter(right.data_64[3],56) ^ 0x80000000;
        
        
        //apply F function to the right branch
        // shift512(shift_1_256[2],left,tmp);
        //tmp.data_64[0] = ror_help_inter(left.data_64[3],9);
        //tmp.data_64[1] = ror_help_inter(left.data_64[0],8);
        //tmp.data_64[2] = ror_help_inter(left.data_64[1],8);
        //tmp.data_64[3] = ror_help_inter(left.data_64[2],8);
        ////AND512(tmp,left);
        //// shift512(shift_5_256[2],left,tmp1);
        //tmp1.data_64[0] = ror_help_inter(left.data_64[3],42);
        //tmp1.data_64[1] = ror_help_inter(left.data_64[0],41);
        //tmp1.data_64[2] = ror_help_inter(left.data_64[1],41);
        //tmp1.data_64[3] = ror_help_inter(left.data_64[2],41);
        ////XOR3(right,tmp,tmp1);
        //AND_XOR(right,tmp,left,tmp1);

        right.data_64[0] ^= (ror_help_inter(left.data_64[3],9) & left.data_64[0]) ^ ror_help_inter(left.data_64[3],42); 
        right.data_64[1] ^= (ror_help_inter(left.data_64[0],8) & left.data_64[1]) ^ ror_help_inter(left.data_64[0],41); 
        right.data_64[2] ^= (ror_help_inter(left.data_64[1],8) & left.data_64[2]) ^ ror_help_inter(left.data_64[1],41); 
        right.data_64[3] ^= (ror_help_inter(left.data_64[2],8) & left.data_64[3]) ^ ror_help_inter(left.data_64[2],41); 

        //apply theta to left branch
        // shift512(shift_7_256[2],left,tmp);
        //tmp.data_64[0] = ror_help_inter(left.data_64[1],58);
        //tmp.data_64[1] = ror_help_inter(left.data_64[2],58);
        //tmp.data_64[2] = ror_help_inter(left.data_64[3],58);
        //tmp.data_64[3] = ror_help_inter(left.data_64[0],57);
        //// shift512(shift_32_256[2],left,tmp1);
        //tmp1.data_64[0] = ror_help_inter(left.data_64[0],8);
        //tmp1.data_64[1] = ror_help_inter(left.data_64[1],8);
        //tmp1.data_64[2] = ror_help_inter(left.data_64[2],8);
        //tmp1.data_64[3] = ror_help_inter(left.data_64[3],8);
        //XOR3(left,tmp,tmp1);
        // ADD_CST_512_opt(7,left);
        left.data_64[0] ^= ror_help_inter(left.data_64[1],58) ^ ror_help_inter(left.data_64[0],8) ^ 0x80000000;
        left.data_64[1] ^= ror_help_inter(left.data_64[2],58) ^ ror_help_inter(left.data_64[1],8) ^ 0x80000000;
        left.data_64[2] ^= ror_help_inter(left.data_64[3],58) ^ ror_help_inter(left.data_64[2],8) ^ 0x8000000000000000;
        left.data_64[3] ^= ror_help_inter(left.data_64[0],57) ^ ror_help_inter(left.data_64[3],8) ^ 0x0;


        // shift512(shift_1_256[1],right,tmp);
        //tmp.data_64[0] = ror_help_inter(right.data_64[1],60);
        //tmp.data_64[1] = ror_help_inter(right.data_64[2],60);
        //tmp.data_64[2] = ror_help_inter(right.data_64[3],60);
        //tmp.data_64[3] = ror_help_inter(right.data_64[0],59);
        ////AND512(tmp,right);
        //// shift512(shift_5_256[1],right,tmp1);
        //tmp1.data_64[0] = ror_help_inter(right.data_64[1],43);
        //tmp1.data_64[1] = ror_help_inter(right.data_64[2],43);
        //tmp1.data_64[2] = ror_help_inter(right.data_64[3],43);
        //tmp1.data_64[3] = ror_help_inter(right.data_64[0],42);
        ////XOR3(left,tmp,tmp1);
        //AND_XOR(left,tmp,right,tmp1);

        left.data_64[0] ^= (ror_help_inter(right.data_64[1],60) & right.data_64[0]) ^ ror_help_inter(right.data_64[1],43); 
        left.data_64[1] ^= (ror_help_inter(right.data_64[2],60) & right.data_64[1]) ^ ror_help_inter(right.data_64[2],43); 
        left.data_64[2] ^= (ror_help_inter(right.data_64[3],60) & right.data_64[2]) ^ ror_help_inter(right.data_64[3],43); 
        left.data_64[3] ^= (ror_help_inter(right.data_64[0],59) & right.data_64[3]) ^ ror_help_inter(right.data_64[0],42); 
        //apply theta to left branch
        // shift512(shift_7_256[1],right,tmp);
        //tmp.data_64[0] = ror_help_inter(right.data_64[3],35);
        //tmp.data_64[1] = ror_help_inter(right.data_64[0],34);
        //tmp.data_64[2] = ror_help_inter(right.data_64[1],34);
        //tmp.data_64[3] = ror_help_inter(right.data_64[2],34);
        //// shift512(shift_32_256[9],right,tmp1);
        //tmp1.data_64[0] = ror_help_inter(right.data_64[0],56);
        //tmp1.data_64[1] = ror_help_inter(right.data_64[1],56);
        //tmp1.data_64[2] = ror_help_inter(right.data_64[2],56);
        //tmp1.data_64[3] = ror_help_inter(right.data_64[3],56);
        //XOR3(right,tmp,tmp1);
        // ADD_CST_512_opt((7<<1)+1,right);
        right.data_64[0] ^= ror_help_inter(right.data_64[3],35) ^ ror_help_inter(right.data_64[0],56) ^ 0x8000000080000000;
        right.data_64[1] ^= ror_help_inter(right.data_64[0],34) ^ ror_help_inter(right.data_64[1],56) ^ 0x8000000080000000;
        right.data_64[2] ^= ror_help_inter(right.data_64[1],34) ^ ror_help_inter(right.data_64[2],56) ^ 0x8000000080000000;
        right.data_64[3] ^= ror_help_inter(right.data_64[2],34) ^ ror_help_inter(right.data_64[3],56) ^ 0x0;


}

#endif