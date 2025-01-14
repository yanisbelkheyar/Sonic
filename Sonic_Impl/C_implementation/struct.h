#ifndef STRUCT
#define STRUCT
#include <stdint.h>

typedef struct state{
      /* data */
    uint64_t* data_64;
    uint8_t size_64;
} state;

typedef struct cst_state_128{
    uint64_t data_64[2];
    uint8_t size_64;
} cst_state_128;

typedef struct cst_state_256{
    uint64_t data_64[4];
    uint8_t size_64;
} cst_state_256;

typedef struct table_cst_128{
    uint8_t size;
    cst_state_128 table[30];
} table_cst_128;


typedef struct table_cst_256{
    uint8_t size;
    cst_state_256 table[30];
} table_cst_256;

#endif