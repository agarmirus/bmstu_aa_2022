#include "pancake.h"
#include "swap.h"

static size_t get_max_elem_index(int arr[], const size_t edge_index)
{
    size_t max_elem_ind = 0;

    for (size_t i = 1; i <= edge_index; ++i)
        if (arr[i] > arr[max_elem_ind])
            max_elem_ind = i;
    
    return i;
}

static void flip_pancakes(int arr[], const size_t bottom_index)
{
    size_t left = 0, right = bottom_index;

    while (left > right)
        swap(arr + (left++), arr + (right--));
}

void pancake_sort(int arr[], const size_t len)
{
    size_t n = len - 1;

    while (n > 0)
    {
        size_t max_elem_ind = get_max_elem_index(arr, n);

        flip_pancakes(arr, max_elem_ind);
        flip_pancakes(arr, n);
    }
}
