#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "api.h"
#include "cpucycles.h"


#include "crypto_aead.h"

#define NUM_RUNS 16
#define NUM_MLENS 7
#if !defined(__AVR__)
#define MAX_LEN (1 << 11)
#else
#define MAX_LEN (1 << 8)
#endif


unsigned long long alen = 0;
unsigned long long clen = 0;
unsigned char ALIGN(16) a[MAX_LEN];
unsigned char ALIGN(16) m[MAX_LEN];
unsigned char ALIGN(16) c[MAX_LEN + CRYPTO_ABYTES];
unsigned char ALIGN(16) n[CRYPTO_NPUBBYTES];
unsigned char ALIGN(16) k[CRYPTO_KEYBYTES];


#if !defined(__AVR__)
unsigned long long mlens[] = {1, 8, 16, 32, 64, 1536, MAX_LEN};
#else
unsigned long long mlens[] = {1, 8, 16, 32, 64, 128, 256};
#endif
unsigned long long cycles[NUM_MLENS][NUM_RUNS * 2];

void init_input() {
  int i, j;
  for (i = 0; i < MAX_LEN; ++i) a[i] = rand();
  for (i = 0; i < MAX_LEN; ++i) m[i] = rand();
  for (i = 0; i < CRYPTO_KEYBYTES; ++i) k[i] = rand();
  for (i = 0; i < CRYPTO_NPUBBYTES; ++i) n[i] = rand();

}

unsigned long long measure(unsigned long long mlen) {
  unsigned long long NREPS = MAX_LEN / mlen;
  unsigned long long i;
  int result = 0;
  init_input();
  cpucycles_reset();
  cpucycles_start();
  for (i = 0; i < NREPS; ++i) {

  result |= crypto_aead_encrypt(c, &clen, m, mlen, a, alen, NULL, n, k);

  }
  cpucycles_stop();
  if (!result)
    return cpucycles_result();
  else
    return -1;
}

int compare_uint64(const void* first, const void* second) {
  const unsigned long long* ia = (const unsigned long long*)first;
  const unsigned long long* ib = (const unsigned long long*)second;
  if (*ia > *ib) return 1;
  if (*ia < *ib) return -1;
  return 0;
}

int main(int argc, char* argv[]) {
  unsigned long long i, j;
  double factor = 1.0;
  if (argc == 2) factor = atof(argv[1]);

  cpucycles_init();

  for (i = 0; i < NUM_MLENS; ++i) {
    for (j = 0; j < NUM_RUNS; ++j) cycles[i][j] = measure(mlens[i]);
    qsort(cycles[i], NUM_RUNS, sizeof(unsigned long long), &compare_uint64);
  }

  printf("\nsorted cycles:\n");
  for (i = 0; i < NUM_MLENS; ++i) {
    unsigned long long NREPS = MAX_LEN / mlens[i];
    printf("%5" PRIu32 ": ", (uint32_t)mlens[i]);
    for (j = 0; j < NUM_RUNS; ++j)
      if (cycles[i][j] == -1)
        printf(" - ");
      else
        printf("%" PRIu32 " ", (uint32_t)(cycles[i][j] / NREPS));
    printf("\n");
  }

  printf("\ncycles per byte (min,median):\n");
  for (i = 0; i < NUM_MLENS; ++i) {
    unsigned long long NREPS = MAX_LEN / mlens[i];
    unsigned long long bytes = mlens[i] * NREPS;
    printf("%5" PRIu32 ": ", (uint32_t)mlens[i]);
    if (cycles[i][0] == -1)
      printf("   -      -   \n");
    else
#if !defined(__AVR__)
      printf("%6.1f %6.1f\n", factor * cycles[i][0] / bytes + 0.05,
             factor * cycles[i][NUM_RUNS / 2] / bytes + 0.05);
#else
      printf("%6" PRIu32 " %6" PRIu32 "\n",
             (uint32_t)(factor * cycles[i][0] / bytes + 0.05),
             (uint32_t)(factor * cycles[i][NUM_RUNS / 2] / bytes + 0.05));
#endif
  }
  printf("\n");

  for (i = 0; i < NUM_MLENS; ++i) printf("| %5" PRIu32 " ", (uint32_t)mlens[i]);
  printf("|\n");
  for (i = 0; i < NUM_MLENS; ++i) printf("|------:");
  printf("|\n");
  for (i = 0; i < NUM_MLENS; ++i) {
    unsigned long long NREPS = MAX_LEN / mlens[i];
    unsigned long long bytes = mlens[i] * NREPS;
    if (cycles[i][0] == -1)
      printf("|   -   ");
    else if ((mlens[i] <= 32) || (factor * cycles[i][0] / bytes + 0.5 >= 1000))
      printf("| %5" PRIu32 " ",
             (uint32_t)(factor * cycles[i][0] / bytes + 0.5));
    else
#if !defined(__AVR__)
      printf("| %5.1f ", factor * cycles[i][0] / bytes + 0.05);
#else
      printf("| %5" PRIu32 " ",
             (uint32_t)(factor * cycles[i][0] / bytes + 0.05));
#endif
  }
  printf("|\n");

  exit(0);
}
