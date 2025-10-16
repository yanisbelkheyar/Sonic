#ifndef FUNCTION
#define FUNCTION

#include <immintrin.h>

#include "struct.h"

#define NBR_ROUND512 16
// Add the round constant corresponding to the round
static inline void ADD_CST_512_opt_avx2(int round, const table_cst_256* table, h_state512* s) {
    // Récupérer la constante de round
    cst_state_256 cst = table->table[NBR_ROUND512 - round - 1];
    
    // Charger les données de la constante et de l'état dans des registres AVX2
    __m256i s_data = _mm256_loadu_si256((__m256i*)s->data_64);
    __m256i cst_data = _mm256_loadu_si256((__m256i*)cst.data_64);
    
    // Effectuer le XOR entre l'état et la constante
    __m256i result = _mm256_xor_si256(s_data, cst_data);
    
    // Stocker le résultat dans s->data_64
    _mm256_storeu_si256((__m256i*)s->data_64, result);
}


static inline void XOR3_shift_avx2(h_state512* s,int shift1, int shift2){
    uint64_t sp[4] = {s->data_64[0],s->data_64[1],s->data_64[2],s->data_64[3]};

    int size = 64;
    shift1 = 256 - shift1;
    shift2 = 256 - shift2;

    int dec1 = ((shift1 >> 6) & 3);
    int shift_bits1 = shift1 & 63;
    uint64_t mask1 = (((uint64_t)1<<shift_bits1)-1);
    uint64_t tmp1 = 0;
    int inv_shift_bits1 = size-shift_bits1;

    int dec2 = ((shift2 >> 6) & 3);
    int shift_bits2 = shift2 & 63;
    uint64_t mask2 = (((uint64_t)1<<shift_bits2)-1);
    uint64_t tmp2 = 0;

    int inv_shift_bits2 = size-shift_bits2;

    // Charger les 4 valeurs de 64 bits
    __m256i data1 = _mm256_loadu_si256((__m256i*)s->data_64);

    // Décaler chaque bloc indépendamment
    __m256i shifted_right = _mm256_srli_epi64(data1, shift_bits1);
    __m256i shifted_left = _mm256_slli_epi64(data1, inv_shift_bits1);

    // Effectuer un masquage et un décalage manuel pour éviter les erreurs de permutation
    __m256i result1 = _mm256_or_si256(shifted_right, shifted_left);

    // Charger les 4 valeurs de 64 bits
    __m256i data2 = _mm256_loadu_si256((__m256i*)s->data_64);

    // Décaler chaque bloc indépendamment
    shifted_right = _mm256_srli_epi64(data2, shift_bits2);
    shifted_left = _mm256_slli_epi64(data2, inv_shift_bits2);

    // Effectuer un masquage et un décalage manuel pour éviter les erreurs de permutation
    __m256i result2 = _mm256_or_si256(shifted_right, shifted_left);

    __m256i data = _mm256_loadu_si256((__m256i*)s->data_64);

    __m256i result = _mm256_xor_si256(data1, data2);

    result = _mm256_xor_si256(result, data);

    // Stocker le résultat
    _mm256_storeu_si256((__m256i*)s->data_64, result);
}


static inline void AND_and_XOR_shift_avx2(h_state512* s,h_state512* s1,int shift1, int shift2){
    uint64_t sp[4] = {s->data_64[0],s->data_64[1],s->data_64[2],s->data_64[3]};

    int size = 64;
    shift1 = 256 - shift1;
    shift2 = 256 - shift2;

    int dec1 = ((shift1 >> 6) & 3);
    int shift_bits1 = shift1 & 63;
    uint64_t mask1 = (((uint64_t)1<<shift_bits1)-1);
    uint64_t tmp1 = 0;
    int inv_shift_bits1 = size-shift_bits1;

    int dec2 = ((shift2 >> 6) & 3);
    int shift_bits2 = shift2 & 63;
    uint64_t mask2 = (((uint64_t)1<<shift_bits2)-1);
    uint64_t tmp2 = 0;

    int inv_shift_bits2 = size-shift_bits2;

    // Charger les 4 valeurs de 64 bits
    __m256i data1 = _mm256_loadu_si256((__m256i*)s->data_64);

    // Décaler chaque bloc indépendamment
    __m256i shifted_right = _mm256_srli_epi64(data1, shift_bits1);
    __m256i shifted_left = _mm256_slli_epi64(data1, inv_shift_bits1);

    // Effectuer un masquage et un décalage manuel pour éviter les erreurs de permutation
    __m256i result1 = _mm256_or_si256(shifted_right, shifted_left);

    // Charger les 4 valeurs de 64 bits
    __m256i data2 = _mm256_loadu_si256((__m256i*)s->data_64);

    // Décaler chaque bloc indépendamment
    shifted_right = _mm256_srli_epi64(data2, shift_bits2);
    shifted_left = _mm256_slli_epi64(data2, inv_shift_bits2);

    // Effectuer un masquage et un décalage manuel pour éviter les erreurs de permutation
    __m256i result2 = _mm256_or_si256(shifted_right, shifted_left);

    __m256i data = _mm256_loadu_si256((__m256i*)s->data_64);
    __m256i data3 = _mm256_loadu_si256((__m256i*)s1->data_64);
    
    // Appliquer XOR sur s1 et s2
    __m256i result = _mm256_and_si256(data, data1);

    result = _mm256_xor_si256(result, data2);

    result = _mm256_xor_si256(result, data3);
    
    // Stocker le résultat dans s1->data_64
    _mm256_storeu_si256((__m256i*)s1->data_64, result);

}


static inline void shift512_avx2(int shift, h_state512* s, h_state512* res) {
    shift = 256 - shift;  // Ajustement du décalage (256 - shift)

    int shift_blocks = (shift >> 6) & 3;  // Calcul du nombre de blocs à décaler
    int shift_bits = shift & 63;          // Décalage restant en bits (0-63 bits)
    int inv_shift_bits = 64 - shift_bits; // Décalage inverse pour la partie restante

    // Charger les 4 valeurs de 64 bits
    __m256i data = _mm256_loadu_si256((__m256i*)s->data_64);

    // Décaler chaque bloc indépendamment
    __m256i shifted_right = _mm256_srli_epi64(data, shift_bits);
    __m256i shifted_left = _mm256_slli_epi64(data, inv_shift_bits);

    //mask and rotate each word

    // add the new part

    // Effectuer un masquage et un décalage manuel pour éviter les erreurs de permutation
    __m256i result = _mm256_or_si256(shifted_right, shifted_left);

    // Stocker le résultat
    _mm256_storeu_si256((__m256i*)res->data_64, result);
}


static inline void XOR3_avx2(h_state512* s1, h_state512* s2, h_state512* s3) {
    // Charger les 4 éléments de 64 bits des 3 états dans des registres AVX2
    __m256i s2_data = _mm256_loadu_si256((__m256i*)s2->data_64);
    __m256i s3_data = _mm256_loadu_si256((__m256i*)s3->data_64);
    
    // Appliquer XOR sur s2 et s3
    __m256i result = _mm256_xor_si256(s2_data, s3_data);
    
    // Appliquer XOR sur le résultat avec s1
    __m256i s1_data = _mm256_loadu_si256((__m256i*)s1->data_64);
    result = _mm256_xor_si256(s1_data, result);
    
    // Stocker le résultat dans s1->data_64
    _mm256_storeu_si256((__m256i*)s1->data_64, result);
}

static inline void AND512_avx2(h_state512* s1, h_state512* s2){

    // Charger les 4 éléments de 64 bits des 3 états dans des registres AVX2
    __m256i s2_data = _mm256_loadu_si256((__m256i*)s2->data_64);
    __m256i s1_data = _mm256_loadu_si256((__m256i*)s1->data_64);
    
    // Appliquer XOR sur s1 et s2
    __m256i result = _mm256_and_si256(s2_data, s1_data);
    
    // Stocker le résultat dans s1->data_64
    _mm256_storeu_si256((__m256i*)s1->data_64, result);

}


#endif
