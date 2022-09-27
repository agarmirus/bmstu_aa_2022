#include <stdbool.h>

#include "cocktailsort.h"
#include "swap.h"

static void right_directional_sort(
    int arr[], bool *swapped, const size_t left, const size_t right
)
{
    for (size_t i = left, i < right; ++i)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr + i, arr + i + 1);

            swapped = true;
        }
    }
}

static void left_directional_sort(
    int arr[], bool *swapped, const size_t left, const size_t right
)
{
    for (size_t i = right, i > left; --i)
    {
        if (arr[i - 1] > arr[i])
        {
            swap(arr + i - 1, arr + i);

            swapped = true;
        }
    }
}

void cocktail_shaker_sort(int arr[], const size_t len)
{
    bool swaped = false;
    size_t left = 0, right = len - 1;

    do
    {
        swapped = false;

        right_directional_sort(arr, &swapped, left, right--);

        if (swapped)
        {
            swapped = false;
            
            left_directional_sort(arr, &swapped, left++, right);
        }
    }
    while (swapped)
}
