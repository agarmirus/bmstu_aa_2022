#include "swap.h"

void swap(int *const a, int *const b)
{
    int tmp = *a;

    *a = *b;
    *b = tmp;
}
