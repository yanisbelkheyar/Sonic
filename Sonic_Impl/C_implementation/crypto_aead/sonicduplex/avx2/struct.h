#ifndef STRUCT
#define STRUCT
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
    cst_state_256 table[30];
    uint8_t size;
} table_cst_256;

#endif