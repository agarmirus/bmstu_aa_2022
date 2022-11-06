#include "selectionsort.h"

void selection_sort(int *arr, const size_t len)
{
    for (size_t i = 0; i < len - 1; ++i)
    {
        size_t min_elem_ind = i;

        for (size_t j = i + 1; j < len; ++j)
            if (arr[j] < arr[min_elem_ind])
                min_elem_ind = j;

        if (arr[i] != arr[min_elem_ind])
        {
            int tmp = arr[i];

            arr[i] = arr[min_elem_ind];
            arr[min_elem_ind] = tmp;
        }
    }
}
