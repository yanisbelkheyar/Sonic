#ifndef STRUCT_512
#define STRUCT_512
#include <stdint.h>

typedef struct state{
      /* data */
    uint64_t* data_64;
    uint8_t size_64;
} state;

typedef struct h_state512{
    /* data */
  uint64_t data_64[4];
  uint8_t size_64;
} h_state512;

typedef struct cst_state_256{
    uint64_t data_64[4];
    uint8_t size_64;
} cst_state_256;

typedef struct table_cst_256{
    uint8_t size;
    cst_state_256 table[30];
} table_cst_256;

#endif