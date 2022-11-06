#include "pancakesort.h"

void pancake_sort(int *arr, const size_t len)
{
    for (size_t right = len - 1; right > 0; --right)
    {
        size_t max_elem_ind = 0;

        for (size_t j = 1; j <= right; ++j)
            if (arr[j] > arr[max_elem_ind])
                max_elem_ind = j;
            
        for (size_t k = 0; k < max_elem_ind; ++k, --max_elem_ind)
        {
            int tmp = arr[k];
            arr[k] = arr[max_elem_ind];
            arr[max_elem_ind] = tmp;
        }

        for (size_t k = 0, n = right; k < n; ++k, --n)
        {
            int tmp = arr[k];
            arr[k] = arr[n];
            arr[n] = tmp;
        }
    }
}
