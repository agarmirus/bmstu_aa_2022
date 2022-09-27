#include <stdio.h>

#include "arrio.h"

void print_array(int arr[], const size_t len)
{
    for (size_t i = 0; i < len; ++i)
        printf("%d ", arr[i]);
    
    printf("\n");
}
