#include "arrlib.h"

int *arralloc(const size_t length)
{
    return malloc(length * sizeof(int));
}

int *arrcpy(int *dest, const int *src, const size_t length)
{
    return (int *)memmove(dest, src, length);
}
