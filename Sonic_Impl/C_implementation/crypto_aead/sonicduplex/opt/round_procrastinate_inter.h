#ifndef ROUND_PROCRASTINATE
#define ROUND_PROCRASTINATE

#include "function.h"

//__attribute__ ((__target__ ("no-avx")))
 void sonic_encrypt_512_procrastinate(h_state512* left, h_state512* right){

h_state512 tmp = {.data_64 = {0,0,0,0},.size_64=4};
h_state512 tmp1 = {.data_64 = {0,0,0,0},.size_64=4};

right->data_64[0] ^= (ror_help_inter(left->data_64[3],1) &  left->data_64[0]) ^ ror_help_inter(left->data_64[3],2);
right->data_64[1] ^= (ror_help_inter(left->data_64[0],0) &  left->data_64[1]) ^ ror_help_inter(left->data_64[0],1);
right->data_64[2] ^= (ror_help_inter(left->data_64[1],0) &  left->data_64[2]) ^ ror_help_inter(left->data_64[1],1);
right->data_64[3] ^= (ror_help_inter(left->data_64[2],0) &  left->data_64[3]) ^ ror_help_inter(left->data_64[2],1);

left->data_64[0] ^= ror_help_inter(left->data_64[1],1) ^ ror_help_inter(left->data_64[0],5) ^ 0x80000000;
left->data_64[1] ^= ror_help_inter(left->data_64[2],1) ^ ror_help_inter(left->data_64[1],5) ^ 0x80000000;
left->data_64[2] ^= ror_help_inter(left->data_64[3],1) ^ ror_help_inter(left->data_64[2],5) ^ 0x0;
left->data_64[3] ^= ror_help_inter(left->data_64[0],0) ^ ror_help_inter(left->data_64[3],5) ^ 0x8000000000000000;

left->data_64[0] ^= (ror_help_inter(right->data_64[0],0) &  right->data_64[0]) ^ ror_help_inter(right->data_64[1],9);
left->data_64[1] ^= (ror_help_inter(right->data_64[1],0) &  right->data_64[1]) ^ ror_help_inter(right->data_64[2],9);
left->data_64[2] ^= (ror_help_inter(right->data_64[2],0) &  right->data_64[2]) ^ ror_help_inter(right->data_64[3],9);
left->data_64[3] ^= (ror_help_inter(right->data_64[3],0) &  right->data_64[3]) ^ ror_help_inter(right->data_64[0],8);

right->data_64[0] ^= ror_help_inter(right->data_64[3],6) ^ ror_help_inter(right->data_64[0],35) ^ 0x8000000000000000;
right->data_64[1] ^= ror_help_inter(right->data_64[0],5) ^ ror_help_inter(right->data_64[1],35) ^ 0x8000000000000000;
right->data_64[2] ^= ror_help_inter(right->data_64[1],5) ^ ror_help_inter(right->data_64[2],35) ^ 0x8000000080000000;
right->data_64[3] ^= ror_help_inter(right->data_64[2],5) ^ ror_help_inter(right->data_64[3],35) ^ 0x80000000;

right->data_64[0] ^= (ror_help_inter(left->data_64[3],13) &  left->data_64[0]) ^ ror_help_inter(left->data_64[3],62);
right->data_64[1] ^= (ror_help_inter(left->data_64[0],12) &  left->data_64[1]) ^ ror_help_inter(left->data_64[0],61);
right->data_64[2] ^= (ror_help_inter(left->data_64[1],12) &  left->data_64[2]) ^ ror_help_inter(left->data_64[1],61);
right->data_64[3] ^= (ror_help_inter(left->data_64[2],12) &  left->data_64[3]) ^ ror_help_inter(left->data_64[2],61);

left->data_64[0] ^= ror_help_inter(left->data_64[1],37) ^ ror_help_inter(left->data_64[0],53) ^ 0x8000000000000000;
left->data_64[1] ^= ror_help_inter(left->data_64[2],37) ^ ror_help_inter(left->data_64[1],53) ^ 0x8000000080000000;
left->data_64[2] ^= ror_help_inter(left->data_64[3],37) ^ ror_help_inter(left->data_64[2],53) ^ 0x8000000080000000;
left->data_64[3] ^= ror_help_inter(left->data_64[0],36) ^ ror_help_inter(left->data_64[3],53) ^ 0x8000000000000000;

left->data_64[0] ^= (ror_help_inter(right->data_64[0],0) &  right->data_64[0]) ^ ror_help_inter(right->data_64[1],45);
left->data_64[1] ^= (ror_help_inter(right->data_64[1],0) &  right->data_64[1]) ^ ror_help_inter(right->data_64[2],45);
left->data_64[2] ^= (ror_help_inter(right->data_64[2],0) &  right->data_64[2]) ^ ror_help_inter(right->data_64[3],45);
left->data_64[3] ^= (ror_help_inter(right->data_64[3],0) &  right->data_64[3]) ^ ror_help_inter(right->data_64[0],44);

right->data_64[0] ^= ror_help_inter(right->data_64[3],2) ^ ror_help_inter(right->data_64[0],51) ^ 0x80000000;
right->data_64[1] ^= ror_help_inter(right->data_64[0],1) ^ ror_help_inter(right->data_64[1],51) ^ 0x80000000;
right->data_64[2] ^= ror_help_inter(right->data_64[1],1) ^ ror_help_inter(right->data_64[2],51) ^ 0x8000000000000000;
right->data_64[3] ^= ror_help_inter(right->data_64[2],1) ^ ror_help_inter(right->data_64[3],51) ^ 0x0;

right->data_64[0] ^= (ror_help_inter(left->data_64[3],25) &  left->data_64[0]) ^ ror_help_inter(left->data_64[3],58);
right->data_64[1] ^= (ror_help_inter(left->data_64[0],24) &  left->data_64[1]) ^ ror_help_inter(left->data_64[0],57);
right->data_64[2] ^= (ror_help_inter(left->data_64[1],24) &  left->data_64[2]) ^ ror_help_inter(left->data_64[1],57);
right->data_64[3] ^= (ror_help_inter(left->data_64[2],24) &  left->data_64[3]) ^ ror_help_inter(left->data_64[2],57);

left->data_64[0] ^= ror_help_inter(left->data_64[1],9) ^ ror_help_inter(left->data_64[0],37) ^ 0x80000000;
left->data_64[1] ^= ror_help_inter(left->data_64[2],9) ^ ror_help_inter(left->data_64[1],37) ^ 0x80000000;
left->data_64[2] ^= ror_help_inter(left->data_64[3],9) ^ ror_help_inter(left->data_64[2],37) ^ 0x8000000080000000;
left->data_64[3] ^= ror_help_inter(left->data_64[0],8) ^ ror_help_inter(left->data_64[3],37) ^ 0x0;

left->data_64[0] ^= (ror_help_inter(right->data_64[0],0) &  right->data_64[0]) ^ ror_help_inter(right->data_64[1],17);
left->data_64[1] ^= (ror_help_inter(right->data_64[1],0) &  right->data_64[1]) ^ ror_help_inter(right->data_64[2],17);
left->data_64[2] ^= (ror_help_inter(right->data_64[2],0) &  right->data_64[2]) ^ ror_help_inter(right->data_64[3],17);
left->data_64[3] ^= (ror_help_inter(right->data_64[3],0) &  right->data_64[3]) ^ ror_help_inter(right->data_64[0],16);

right->data_64[0] ^= ror_help_inter(right->data_64[3],62) ^ ror_help_inter(right->data_64[0],3) ^ 0x8000000000000000;
right->data_64[1] ^= ror_help_inter(right->data_64[0],61) ^ ror_help_inter(right->data_64[1],3) ^ 0x8000000000000000;
right->data_64[2] ^= ror_help_inter(right->data_64[1],61) ^ ror_help_inter(right->data_64[2],3) ^ 0x80000000;
right->data_64[3] ^= ror_help_inter(right->data_64[2],61) ^ ror_help_inter(right->data_64[3],3) ^ 0x0;

right->data_64[0] ^= (ror_help_inter(left->data_64[3],37) &  left->data_64[0]) ^ ror_help_inter(left->data_64[3],54);
right->data_64[1] ^= (ror_help_inter(left->data_64[0],36) &  left->data_64[1]) ^ ror_help_inter(left->data_64[0],53);
right->data_64[2] ^= (ror_help_inter(left->data_64[1],36) &  left->data_64[2]) ^ ror_help_inter(left->data_64[1],53);
right->data_64[3] ^= (ror_help_inter(left->data_64[2],36) &  left->data_64[3]) ^ ror_help_inter(left->data_64[2],53);

left->data_64[0] ^= ror_help_inter(left->data_64[1],45) ^ ror_help_inter(left->data_64[0],21) ^ 0x8000000080000000;
left->data_64[1] ^= ror_help_inter(left->data_64[2],45) ^ ror_help_inter(left->data_64[1],21) ^ 0x80000000;
left->data_64[2] ^= ror_help_inter(left->data_64[3],45) ^ ror_help_inter(left->data_64[2],21) ^ 0x8000000080000000;
left->data_64[3] ^= ror_help_inter(left->data_64[0],44) ^ ror_help_inter(left->data_64[3],21) ^ 0x0;

left->data_64[0] ^= (ror_help_inter(right->data_64[0],0) &  right->data_64[0]) ^ ror_help_inter(right->data_64[1],53);
left->data_64[1] ^= (ror_help_inter(right->data_64[1],0) &  right->data_64[1]) ^ ror_help_inter(right->data_64[2],53);
left->data_64[2] ^= (ror_help_inter(right->data_64[2],0) &  right->data_64[2]) ^ ror_help_inter(right->data_64[3],53);
left->data_64[3] ^= (ror_help_inter(right->data_64[3],0) &  right->data_64[3]) ^ ror_help_inter(right->data_64[0],52);

right->data_64[0] ^= ror_help_inter(right->data_64[3],58) ^ ror_help_inter(right->data_64[0],19) ^ 0x8000000000000000;
right->data_64[1] ^= ror_help_inter(right->data_64[0],57) ^ ror_help_inter(right->data_64[1],19) ^ 0x8000000080000000;
right->data_64[2] ^= ror_help_inter(right->data_64[1],57) ^ ror_help_inter(right->data_64[2],19) ^ 0x80000000;
right->data_64[3] ^= ror_help_inter(right->data_64[2],57) ^ ror_help_inter(right->data_64[3],19) ^ 0x0;

right->data_64[0] ^= (ror_help_inter(left->data_64[3],49) &  left->data_64[0]) ^ ror_help_inter(left->data_64[3],50);
right->data_64[1] ^= (ror_help_inter(left->data_64[0],48) &  left->data_64[1]) ^ ror_help_inter(left->data_64[0],49);
right->data_64[2] ^= (ror_help_inter(left->data_64[1],48) &  left->data_64[2]) ^ ror_help_inter(left->data_64[1],49);
right->data_64[3] ^= (ror_help_inter(left->data_64[2],48) &  left->data_64[3]) ^ ror_help_inter(left->data_64[2],49);

left->data_64[0] ^= ror_help_inter(left->data_64[1],17) ^ ror_help_inter(left->data_64[0],5) ^ 0x8000000080000000;
left->data_64[1] ^= ror_help_inter(left->data_64[2],17) ^ ror_help_inter(left->data_64[1],5) ^ 0x8000000000000000;
left->data_64[2] ^= ror_help_inter(left->data_64[3],17) ^ ror_help_inter(left->data_64[2],5) ^ 0x8000000080000000;
left->data_64[3] ^= ror_help_inter(left->data_64[0],16) ^ ror_help_inter(left->data_64[3],5) ^ 0x0;

left->data_64[0] ^= (ror_help_inter(right->data_64[0],0) &  right->data_64[0]) ^ ror_help_inter(right->data_64[1],25);
left->data_64[1] ^= (ror_help_inter(right->data_64[1],0) &  right->data_64[1]) ^ ror_help_inter(right->data_64[2],25);
left->data_64[2] ^= (ror_help_inter(right->data_64[2],0) &  right->data_64[2]) ^ ror_help_inter(right->data_64[3],25);
left->data_64[3] ^= (ror_help_inter(right->data_64[3],0) &  right->data_64[3]) ^ ror_help_inter(right->data_64[0],24);

right->data_64[0] ^= ror_help_inter(right->data_64[3],54) ^ ror_help_inter(right->data_64[0],35) ^ 0x8000000080000000;
right->data_64[1] ^= ror_help_inter(right->data_64[0],53) ^ ror_help_inter(right->data_64[1],35) ^ 0x8000000080000000;
right->data_64[2] ^= ror_help_inter(right->data_64[1],53) ^ ror_help_inter(right->data_64[2],35) ^ 0x80000000;
right->data_64[3] ^= ror_help_inter(right->data_64[2],53) ^ ror_help_inter(right->data_64[3],35) ^ 0x80000000;

right->data_64[0] ^= (ror_help_inter(left->data_64[3],61) &  left->data_64[0]) ^ ror_help_inter(left->data_64[3],46);
right->data_64[1] ^= (ror_help_inter(left->data_64[0],60) &  left->data_64[1]) ^ ror_help_inter(left->data_64[0],45);
right->data_64[2] ^= (ror_help_inter(left->data_64[1],60) &  left->data_64[2]) ^ ror_help_inter(left->data_64[1],45);
right->data_64[3] ^= (ror_help_inter(left->data_64[2],60) &  left->data_64[3]) ^ ror_help_inter(left->data_64[2],45);

left->data_64[0] ^= ror_help_inter(left->data_64[1],53) ^ ror_help_inter(left->data_64[0],53) ^ 0x8000000080000000;
left->data_64[1] ^= ror_help_inter(left->data_64[2],53) ^ ror_help_inter(left->data_64[1],53) ^ 0x8000000000000000;
left->data_64[2] ^= ror_help_inter(left->data_64[3],53) ^ ror_help_inter(left->data_64[2],53) ^ 0x0;
left->data_64[3] ^= ror_help_inter(left->data_64[0],52) ^ ror_help_inter(left->data_64[3],53) ^ 0x8000000000000000;

left->data_64[0] ^= (ror_help_inter(right->data_64[0],0) &  right->data_64[0]) ^ ror_help_inter(right->data_64[1],61);
left->data_64[1] ^= (ror_help_inter(right->data_64[1],0) &  right->data_64[1]) ^ ror_help_inter(right->data_64[2],61);
left->data_64[2] ^= (ror_help_inter(right->data_64[2],0) &  right->data_64[2]) ^ ror_help_inter(right->data_64[3],61);
left->data_64[3] ^= (ror_help_inter(right->data_64[3],0) &  right->data_64[3]) ^ ror_help_inter(right->data_64[0],60);

right->data_64[0] ^= ror_help_inter(right->data_64[3],50) ^ ror_help_inter(right->data_64[0],51) ^ 0x8000000080000000;
right->data_64[1] ^= ror_help_inter(right->data_64[0],49) ^ ror_help_inter(right->data_64[1],51) ^ 0x8000000080000000;
right->data_64[2] ^= ror_help_inter(right->data_64[1],49) ^ ror_help_inter(right->data_64[2],51) ^ 0x8000000080000000;
right->data_64[3] ^= ror_help_inter(right->data_64[2],49) ^ ror_help_inter(right->data_64[3],51) ^ 0x0;

}

#endif