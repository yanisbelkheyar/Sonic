#ifndef ROUND_PROCRASTINATE
#define ROUND_PROCRASTINATE

#include "function.h"

//__attribute__ ((__target__ ("no-avx")))
 void sonic_encrypt_512_procrastinate(h_state512* left, h_state512* right){

    h_state512 tmp = {.data_64 = {0,0,0,0},.size_64=4};
    h_state512 tmp1 = {.data_64 = {0,0,0,0},.size_64=4};
    

        //apply F function to the right branch
        right->data_64[0] ^= (ror_help_inter(left->data_64[3],1) & left->data_64[0]) ^ ror_help_inter(left->data_64[3],2);
        right->data_64[1] ^= (ror_help_inter(left->data_64[0],0) & left->data_64[1]) ^ ror_help_inter(left->data_64[0],1);
        right->data_64[2] ^= (ror_help_inter(left->data_64[1],0) & left->data_64[2]) ^ ror_help_inter(left->data_64[1],1);
        right->data_64[3] ^= (ror_help_inter(left->data_64[2],0) & left->data_64[3]) ^ ror_help_inter(left->data_64[2],1);
        
        //apply theta to left branch
        left->data_64[0] ^= ror_help_inter(left->data_64[1],2) ^ ror_help_inter(left->data_64[0],8) ^ 0x8000000080000000;
        left->data_64[1] ^= ror_help_inter(left->data_64[2],2) ^ ror_help_inter(left->data_64[1],8) ^ 0x80000000;
        left->data_64[1] ^= ror_help_inter(left->data_64[3],2) ^ ror_help_inter(left->data_64[2],8) ^ 0x0;
        left->data_64[3] ^= ror_help_inter(left->data_64[0],1) ^ ror_help_inter(left->data_64[3],8) ^ 0x8000000000000000;

        //apply F function to the right branch
        left->data_64[0] ^= (ror_help_inter(right->data_64[1],4) & right->data_64[0]) ^ ror_help_inter(right->data_64[1],19);  
        left->data_64[1] ^= (ror_help_inter(right->data_64[2],4) & right->data_64[1]) ^ ror_help_inter(right->data_64[2],19); 
        left->data_64[2] ^= (ror_help_inter(right->data_64[3],4) & right->data_64[2]) ^ ror_help_inter(right->data_64[3],19); 
        left->data_64[3] ^= (ror_help_inter(right->data_64[0],3) & right->data_64[3]) ^ ror_help_inter(right->data_64[0],18); 

        //apply theta to left branch
        right->data_64[0] ^= ror_help_inter(right->data_64[3],27) ^ ror_help_inter(right->data_64[0],56) ^ 0x8000000000000000;
        right->data_64[1] ^= ror_help_inter(right->data_64[0],26) ^ ror_help_inter(right->data_64[1],56) ^ 0x8000000080000000;
        right->data_64[2] ^= ror_help_inter(right->data_64[1],26) ^ ror_help_inter(right->data_64[2],56) ^ 0x8000000080000000;
        right->data_64[3] ^= ror_help_inter(right->data_64[2],26) ^ ror_help_inter(right->data_64[3],56) ^ 0x80000000;
        
        //apply F function to the right branch
        right->data_64[0] ^= (ror_help_inter(left->data_64[3],57) & left->data_64[0]) ^ ror_help_inter(left->data_64[3],26); 
        right->data_64[1] ^= (ror_help_inter(left->data_64[0],56) & left->data_64[1]) ^ ror_help_inter(left->data_64[0],25); 
        right->data_64[2] ^= (ror_help_inter(left->data_64[1],56) & left->data_64[2]) ^ ror_help_inter(left->data_64[1],25); 
        right->data_64[3] ^= (ror_help_inter(left->data_64[2],56) & left->data_64[3]) ^ ror_help_inter(left->data_64[2],25); 

        //apply theta to left branch
        left->data_64[0] ^= ror_help_inter(left->data_64[1],10) ^ror_help_inter(left->data_64[0],8) ^  0x8000000000000000;
        left->data_64[1] ^= ror_help_inter(left->data_64[2],10) ^ror_help_inter(left->data_64[1],8) ^  0x8000000080000000;
        left->data_64[2] ^= ror_help_inter(left->data_64[3],10) ^ror_help_inter(left->data_64[2],8) ^  0x8000000080000000;
        left->data_64[3] ^= ror_help_inter(left->data_64[0],9) ^ ror_help_inter(left->data_64[3],8) ^ 0x80000000;

        //apply F function to the right branch
        left->data_64[0] ^= (ror_help_inter(right->data_64[1],12) & right->data_64[0]) ^ ror_help_inter(right->data_64[1],59); 
        left->data_64[1] ^= (ror_help_inter(right->data_64[2],12) & right->data_64[1]) ^ ror_help_inter(right->data_64[2],59); 
        left->data_64[2] ^= (ror_help_inter(right->data_64[3],12) & right->data_64[2]) ^ ror_help_inter(right->data_64[3],59); 
        left->data_64[3] ^= (ror_help_inter(right->data_64[0],11) & right->data_64[3]) ^ ror_help_inter(right->data_64[0],58);  

        //apply theta to left branch
        right->data_64[0] ^= ror_help_inter(right->data_64[3],19) ^ ror_help_inter(right->data_64[0],56) ^ 0x0;
        right->data_64[1] ^= ror_help_inter(right->data_64[0],18) ^ ror_help_inter(right->data_64[1],56) ^ 0x80000000;
        right->data_64[2] ^= ror_help_inter(right->data_64[1],18) ^ ror_help_inter(right->data_64[2],56) ^ 0x8000000000000000;
        right->data_64[3] ^= ror_help_inter(right->data_64[2],18) ^ ror_help_inter(right->data_64[3],56) ^ 0x80000000;
        
        //apply F function to the right branch
        right->data_64[0] ^= (ror_help_inter(left->data_64[3],49) & left->data_64[0]) ^ ror_help_inter(left->data_64[3],50); 
        right->data_64[1] ^= (ror_help_inter(left->data_64[0],48) & left->data_64[1]) ^ ror_help_inter(left->data_64[0],49); 
        right->data_64[2] ^= (ror_help_inter(left->data_64[1],48) & left->data_64[2]) ^ ror_help_inter(left->data_64[1],49); 
        right->data_64[3] ^= (ror_help_inter(left->data_64[2],48) & left->data_64[3]) ^ ror_help_inter(left->data_64[2],49); 

        
        //apply theta to left branch
        left->data_64[0] ^= ror_help_inter(left->data_64[1],18) ^ ror_help_inter(left->data_64[0],8) ^ 0x8000000000000000;
        left->data_64[1] ^= ror_help_inter(left->data_64[2],18) ^ ror_help_inter(left->data_64[1],8) ^ 0x0;
        left->data_64[2] ^= ror_help_inter(left->data_64[3],18) ^ ror_help_inter(left->data_64[2],8) ^ 0x8000000080000000;
        left->data_64[3] ^= ror_help_inter(left->data_64[0],17) ^ ror_help_inter(left->data_64[3],8) ^ 0x8000000000000000;

        //apply F function to the right branch
        left->data_64[0] ^= (ror_help_inter(right->data_64[1],20) & right->data_64[0]) ^ ror_help_inter(right->data_64[1],35); 
        left->data_64[1] ^= (ror_help_inter(right->data_64[2],20) & right->data_64[1]) ^ ror_help_inter(right->data_64[2],35); 
        left->data_64[2] ^= (ror_help_inter(right->data_64[3],20) & right->data_64[2]) ^ ror_help_inter(right->data_64[3],35); 
        left->data_64[3] ^= (ror_help_inter(right->data_64[0],19) & right->data_64[3]) ^ ror_help_inter(right->data_64[0],34); 

        //apply theta to left branch
        right->data_64[0] ^= ror_help_inter(right->data_64[3],11) ^ ror_help_inter(right->data_64[0],56) ^ 0x8000000000000000;
        right->data_64[1] ^= ror_help_inter(right->data_64[0],10) ^ ror_help_inter(right->data_64[1],56) ^ 0x8000000000000000;
        right->data_64[2] ^= ror_help_inter(right->data_64[1],10) ^ ror_help_inter(right->data_64[2],56) ^ 0x8000000080000000;
        right->data_64[3] ^= ror_help_inter(right->data_64[2],10) ^ ror_help_inter(right->data_64[3],56) ^ 0x80000000;
        
        
        //apply F function to the right branch
        right->data_64[0] ^= (ror_help_inter(left->data_64[3],41) & left->data_64[0]) ^ ror_help_inter(left->data_64[3],10); 
        right->data_64[1] ^= (ror_help_inter(left->data_64[0],40) & left->data_64[1]) ^ ror_help_inter(left->data_64[0],9); 
        right->data_64[2] ^= (ror_help_inter(left->data_64[1],40) & left->data_64[2]) ^ ror_help_inter(left->data_64[1],9); 
        right->data_64[3] ^= (ror_help_inter(left->data_64[2],40) & left->data_64[3]) ^ ror_help_inter(left->data_64[2],9); 

        //apply theta to left branch
        left->data_64[0] ^= ror_help_inter(left->data_64[1],26) ^ ror_help_inter(left->data_64[0],8) ^ 0x0;
        left->data_64[1] ^= ror_help_inter(left->data_64[2],26) ^ ror_help_inter(left->data_64[1],8) ^ 0x80000000;
        left->data_64[2] ^= ror_help_inter(left->data_64[3],26) ^ ror_help_inter(left->data_64[2],8) ^ 0x8000000000000000;
        left->data_64[3] ^= ror_help_inter(left->data_64[0],25) ^ ror_help_inter(left->data_64[3],8) ^ 0x80000000;

        //apply F function to the right branch
        left->data_64[0] ^= (ror_help_inter(right->data_64[1],28) & right->data_64[0]) ^ ror_help_inter(right->data_64[1],11); 
        left->data_64[1] ^= (ror_help_inter(right->data_64[2],28) & right->data_64[1]) ^ ror_help_inter(right->data_64[2],11);
        left->data_64[2] ^= (ror_help_inter(right->data_64[3],28) & right->data_64[2]) ^ ror_help_inter(right->data_64[3],11);
        left->data_64[3] ^= (ror_help_inter(right->data_64[0],27) & right->data_64[3]) ^ ror_help_inter(right->data_64[0],10);

        //apply theta to left branch
        right->data_64[0] ^= ror_help_inter(right->data_64[3],3) ^ ror_help_inter(right->data_64[0],56) ^ 0x80000000;
        right->data_64[1] ^= ror_help_inter(right->data_64[0],2) ^ ror_help_inter(right->data_64[1],56) ^ 0x80000000;
        right->data_64[2] ^= ror_help_inter(right->data_64[1],2) ^ ror_help_inter(right->data_64[2],56) ^ 0x8000000000000000;
        right->data_64[3] ^= ror_help_inter(right->data_64[2],2) ^ ror_help_inter(right->data_64[3],56) ^ 0x0;
        
        //apply F function to the right branch
        right->data_64[0] ^= (ror_help_inter(left->data_64[3],33) & left->data_64[0]) ^ ror_help_inter(left->data_64[3],34);
        right->data_64[1] ^= (ror_help_inter(left->data_64[0],32) & left->data_64[1]) ^ ror_help_inter(left->data_64[0],33);
        right->data_64[2] ^= (ror_help_inter(left->data_64[1],32) & left->data_64[2]) ^ ror_help_inter(left->data_64[1],33);
        right->data_64[3] ^= (ror_help_inter(left->data_64[2],32) & left->data_64[3]) ^ ror_help_inter(left->data_64[2],33);

        //apply theta to left branch
        left->data_64[0] ^= ror_help_inter(left->data_64[1],34) ^ ror_help_inter(left->data_64[0],8) ^ 0x80000000;
        left->data_64[1] ^= ror_help_inter(left->data_64[2],34) ^ ror_help_inter(left->data_64[1],8) ^ 0x80000000;
        left->data_64[2] ^= ror_help_inter(left->data_64[3],34) ^ ror_help_inter(left->data_64[2],8) ^ 0x0;
        left->data_64[3] ^= ror_help_inter(left->data_64[0],33) ^ ror_help_inter(left->data_64[3],8) ^ 0x8000000000000000;

        //apply F function to the right branch
        left->data_64[0] ^= (ror_help_inter(right->data_64[1],36) & right->data_64[0]) ^ ror_help_inter(right->data_64[1],51); 
        left->data_64[1] ^= (ror_help_inter(right->data_64[2],36) & right->data_64[1]) ^ ror_help_inter(right->data_64[2],51); 
        left->data_64[2] ^= (ror_help_inter(right->data_64[3],36) & right->data_64[2]) ^ ror_help_inter(right->data_64[3],51); 
        left->data_64[3] ^= (ror_help_inter(right->data_64[0],35) & right->data_64[3]) ^ ror_help_inter(right->data_64[0],50); 

        //apply theta to left branch
        right->data_64[0] ^= ror_help_inter(left->data_64[0],8) ^ ror_help_inter(right->data_64[0],56) ^ 0x8000000000000000;
        right->data_64[1] ^= ror_help_inter(left->data_64[1],8) ^ ror_help_inter(right->data_64[1],56) ^ 0x8000000000000000;
        right->data_64[2] ^= ror_help_inter(left->data_64[2],8) ^ ror_help_inter(right->data_64[2],56) ^ 0x80000000;
        right->data_64[3] ^= ror_help_inter(left->data_64[3],8) ^ ror_help_inter(right->data_64[3],56) ^ 0x0;
        
        //apply F function to the right branch
        right->data_64[0] ^= (ror_help_inter(left->data_64[3],25) & left->data_64[0]) ^ ror_help_inter(left->data_64[3],58); 
        right->data_64[1] ^= (ror_help_inter(left->data_64[0],24) & left->data_64[1]) ^ ror_help_inter(left->data_64[0],57); 
        right->data_64[2] ^= (ror_help_inter(left->data_64[1],24) & left->data_64[2]) ^ ror_help_inter(left->data_64[1],57); 
        right->data_64[3] ^= (ror_help_inter(left->data_64[2],24) & left->data_64[3]) ^ ror_help_inter(left->data_64[2],57); 

        //apply theta to left branch
        left->data_64[0] ^= ror_help_inter(left->data_64[1],42) ^ ror_help_inter(left->data_64[0],8) ^ 0x8000000000000000;
        left->data_64[1] ^= ror_help_inter(left->data_64[2],42) ^ ror_help_inter(left->data_64[1],8) ^ 0x8000000000000000;
        left->data_64[2] ^= ror_help_inter(left->data_64[3],42) ^ ror_help_inter(left->data_64[2],8) ^ 0x8000000080000000;
        left->data_64[3] ^= ror_help_inter(left->data_64[0],41) ^ ror_help_inter(left->data_64[3],8) ^ 0x80000000;

        //apply F function to the right branch
        left->data_64[0] ^= (ror_help_inter(right->data_64[1],44) & right->data_64[0]) ^ ror_help_inter(right->data_64[1],27);
        left->data_64[1] ^= (ror_help_inter(right->data_64[2],44) & right->data_64[1]) ^ ror_help_inter(right->data_64[2],27);
        left->data_64[2] ^= (ror_help_inter(right->data_64[3],44) & right->data_64[2]) ^ ror_help_inter(right->data_64[3],27);
        left->data_64[3] ^= (ror_help_inter(right->data_64[0],43) & right->data_64[3]) ^ ror_help_inter(right->data_64[0],26);


        //apply theta to left branch
        right->data_64[0] ^= ror_help_inter(right->data_64[3],51) ^ ror_help_inter(right->data_64[0],56) ^ 0x8000000000000000;
        right->data_64[1] ^= ror_help_inter(right->data_64[0],50) ^ ror_help_inter(right->data_64[1],56) ^ 0x8000000080000000;
        right->data_64[2] ^= ror_help_inter(right->data_64[1],50) ^ ror_help_inter(right->data_64[2],56) ^ 0x80000000;
        right->data_64[3] ^= ror_help_inter(right->data_64[2],50) ^ ror_help_inter(right->data_64[3],56) ^ 0x0;
        
        //apply F function to the right branch
        right->data_64[0] ^= (ror_help_inter(left->data_64[3],17) & left->data_64[0]) ^ ror_help_inter(left->data_64[3],18); 
        right->data_64[1] ^= (ror_help_inter(left->data_64[0],16) & left->data_64[1]) ^ ror_help_inter(left->data_64[0],17); 
        right->data_64[2] ^= (ror_help_inter(left->data_64[1],16) & left->data_64[2]) ^ ror_help_inter(left->data_64[1],17); 
        right->data_64[3] ^= (ror_help_inter(left->data_64[2],16) & left->data_64[3]) ^ ror_help_inter(left->data_64[2],17); 

        //apply theta to left branch
        left->data_64[0] ^= ror_help_inter(left->data_64[1],50) ^ ror_help_inter(left->data_64[0],8) ^ 0x8000000000000000;
        left->data_64[1] ^= ror_help_inter(left->data_64[2],50) ^ ror_help_inter(left->data_64[1],8) ^ 0x8000000080000000;
        left->data_64[2] ^= ror_help_inter(left->data_64[3],50) ^ ror_help_inter(left->data_64[2],8) ^ 0x8000000080000000;
        left->data_64[3] ^= ror_help_inter(left->data_64[0],49) ^ ror_help_inter(left->data_64[3],8) ^ 0x8000000000000000;

        //apply F function to the right branch
        left->data_64[0] ^= (ror_help_inter(right->data_64[1],52) & right->data_64[0]) ^ ror_help_inter(right->data_64[1],3);
        left->data_64[1] ^= (ror_help_inter(right->data_64[2],52) & right->data_64[1]) ^ ror_help_inter(right->data_64[2],3);
        left->data_64[2] ^= (ror_help_inter(right->data_64[3],52) & right->data_64[2]) ^ ror_help_inter(right->data_64[3],3);
        left->data_64[3] ^= (ror_help_inter(right->data_64[0],51) & right->data_64[3]) ^ ror_help_inter(right->data_64[0],2);

        //apply theta to left branch
        right->data_64[0] ^= ror_help_inter(right->data_64[3],43) ^ ror_help_inter(right->data_64[0],56) ^ 0x8000000080000000;
        right->data_64[1] ^= ror_help_inter(right->data_64[0],42) ^ ror_help_inter(right->data_64[1],56) ^ 0x8000000080000000;
        right->data_64[2] ^= ror_help_inter(right->data_64[1],42) ^ ror_help_inter(right->data_64[2],56) ^ 0x80000000;
        right->data_64[3] ^= ror_help_inter(right->data_64[2],42) ^ ror_help_inter(right->data_64[3],56) ^ 0x80000000;
        
        //apply F function to the right branch
        right->data_64[0] ^= (ror_help_inter(left->data_64[3],9) & left->data_64[0]) ^ ror_help_inter(left->data_64[3],42); 
        right->data_64[1] ^= (ror_help_inter(left->data_64[0],8) & left->data_64[1]) ^ ror_help_inter(left->data_64[0],41); 
        right->data_64[2] ^= (ror_help_inter(left->data_64[1],8) & left->data_64[2]) ^ ror_help_inter(left->data_64[1],41); 
        right->data_64[3] ^= (ror_help_inter(left->data_64[2],8) & left->data_64[3]) ^ ror_help_inter(left->data_64[2],41); 

        //apply theta to left branch
        left->data_64[0] ^= ror_help_inter(left->data_64[1],58) ^ ror_help_inter(left->data_64[0],8) ^ 0x80000000;
        left->data_64[1] ^= ror_help_inter(left->data_64[2],58) ^ ror_help_inter(left->data_64[1],8) ^ 0x80000000;
        left->data_64[2] ^= ror_help_inter(left->data_64[3],58) ^ ror_help_inter(left->data_64[2],8) ^ 0x8000000000000000;
        left->data_64[3] ^= ror_help_inter(left->data_64[0],57) ^ ror_help_inter(left->data_64[3],8) ^ 0x0;

        //apply F function to the right branch
        left->data_64[0] ^= (ror_help_inter(right->data_64[1],60) & right->data_64[0]) ^ ror_help_inter(right->data_64[1],43); 
        left->data_64[1] ^= (ror_help_inter(right->data_64[2],60) & right->data_64[1]) ^ ror_help_inter(right->data_64[2],43); 
        left->data_64[2] ^= (ror_help_inter(right->data_64[3],60) & right->data_64[2]) ^ ror_help_inter(right->data_64[3],43); 
        left->data_64[3] ^= (ror_help_inter(right->data_64[0],59) & right->data_64[3]) ^ ror_help_inter(right->data_64[0],42); 

        //apply theta to left branch
        right->data_64[0] ^= ror_help_inter(right->data_64[3],35) ^ ror_help_inter(right->data_64[0],56) ^ 0x8000000080000000;
        right->data_64[1] ^= ror_help_inter(right->data_64[0],34) ^ ror_help_inter(right->data_64[1],56) ^ 0x8000000080000000;
        right->data_64[2] ^= ror_help_inter(right->data_64[1],34) ^ ror_help_inter(right->data_64[2],56) ^ 0x8000000080000000;
        right->data_64[3] ^= ror_help_inter(right->data_64[2],34) ^ ror_help_inter(right->data_64[3],56) ^ 0x0;

}

#endif