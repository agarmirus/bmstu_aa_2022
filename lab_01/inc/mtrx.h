#ifndef MTRX_H
#define MTRX_H

#include <stdlib.h>
#include <stdio.h>

#define MTRX_ALLOC_ERROR 200
#define EMPTY_MTRX 201

typedef struct
{
    size_t n;
    size_t m;

    size_t **rptrs;
} mtrx_t;

mtrx_t mtrxalloc(const size_t n, const size_t m);

void mtrxfree(mtrx_t *const mtrx);

void print_mtrx(mtrx_t *const mtrx);

#endif
