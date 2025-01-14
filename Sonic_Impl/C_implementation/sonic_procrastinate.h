#ifndef SONIC_H
#define SONIC_H
#include <stdint.h>

void Sonic_Encrypt_256_procrastinate(const uint64_t *plaintext,
                       uint64_t *ciphertext);

void Sonic_Decrypt_256_procrastinate(const uint64_t *ciphertext,
                       uint64_t *plaintext);

void Sonic_Encrypt_512_procrastinate(const uint64_t *plaintext,
                       uint64_t *ciphertext);

void Sonic_Decrypt_512_procrastinate(const uint64_t *ciphertext,
                       uint64_t *plaintext);

#endif