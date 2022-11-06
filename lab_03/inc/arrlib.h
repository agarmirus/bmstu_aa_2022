#ifndef ARRLIB_H
#define ARRLIB_H

#include <stdlib.h>
#include <string.h>

int *arralloc(const size_t length);

int *arrcpy(int *dest, const int *src, const size_t length);

#endif
