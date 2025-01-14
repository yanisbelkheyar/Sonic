#ifndef SONIC_H
#define SONIC_H
#include <stdint.h>

void Sonic_Encrypt_256(const uint64_t *plaintext,
                       uint64_t *ciphertext);

void Sonic_Decrypt_256(const uint64_t *ciphertext,
                       uint64_t *plaintext);

void Sonic_Encrypt_512(const uint64_t *plaintext,
                       uint64_t *ciphertext);

void Sonic_Decrypt_512(const uint64_t *ciphertext,
                       uint64_t *plaintext);

void Sonic_Encrypt_256_sub_round(const uint64_t *plaintext,
                       uint64_t *ciphertext,
                       int round);

void Sonic_Encrypt_512_sub_round(const uint64_t *plaintext,
                       uint64_t *ciphertext,
                       int round);

#endif