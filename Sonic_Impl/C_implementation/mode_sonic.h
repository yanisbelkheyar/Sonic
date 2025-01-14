#include "sonic.h"

//definition of the mode of sonic

//Sonic_Boom
void sonic_boom_encrypt( uint64_t* plaintext, uint64_t* key, uint64_t* ciphertext);

void sonic_boom_decrypt( uint64_t* ciphertext, uint64_t* key, uint64_t* plaintext);

//SoniK
void sonik(uint8_t* diversifier,int size_diversifier, uint64_t* key,uint64_t* output);

//Sonic Duplex
void sonic_duplex_encrypt(uint8_t* plaintext,
                        int plaintext_size,
                        uint8_t* ad,
                        int ad_size,
                        uint64_t* nonce,
                        uint64_t* key,
                        uint8_t* ciphertext,
                        uint64_t* tag);

void sonic_duplex_decrypt(uint8_t* plaintext,
                        int plaintext_size,
                        uint8_t* ad,
                        int ad_size,
                        uint64_t* nonce,
                        uint64_t* key,
                        uint8_t* ciphertext,
                        uint64_t* tag);