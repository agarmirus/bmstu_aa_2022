#include "selectionsort.h"
#include "swap.h"

static size_t get_min_elem_ind(
    int arr[], const size_t len, const size_t begin_ind
)
{
    size_t min_elem_ind = begin_ind;

    for (size_t j = begin_ind + 2; j < len; ++j)
        if (arr[j] < arr[min_elem_ind])
            min_elem_ind = j;
        
    return min_elem_ind;
}

void selection_sort(int arr[], const size_t len)
{
    for (size_t i = 0; i < len - 1; ++i)
    {
        size_t min_elem_ind = get_min_elem_ind(arr, len, i + 1);

        if (arr[i] != arr[min_elem_ind])
            swap(arr + i, arr + min_elem_ind);
    }
}
