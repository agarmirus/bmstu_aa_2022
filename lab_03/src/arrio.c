#include "arrio.h"

int input_array_length(size_t *const length)
{
    int rc = scanf("%zu", length);

    if (rc != 1 || *length == 0)
        return INPUT_ERROR;
    
    return EXIT_SUCCESS;
}

int input_array_elements(int *arr, const size_t length)
{    
    for (size_t i = 0; i < length; ++i)
    {
        int rc = scanf("%d", arr + i);

        if (rc != 1)
            return INPUT_ERROR;
    }

    return EXIT_SUCCESS;
}

void print_array(int *arr, const size_t len)
{
    for (size_t i = 0; i < len; ++i)
        printf("%d ", arr[i]);
    
    printf("\n");
}
