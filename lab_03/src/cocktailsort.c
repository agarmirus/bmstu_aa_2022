#include "cocktailsort.h"

void cocktail_sort(int *arr, const size_t len)
{
    size_t left = 0, right = len - 1;

    while (left < right)
    {
        for (size_t i = left; i < right; ++i)
        {
            if (arr[i] > arr[i + 1])
            {
                int tmp = arr[i];

                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
            }
        }

        --right;

        for (size_t i = right; i > left; --i)
        {
            if (arr[i - 1] > arr[i])
            {
                int tmp = arr[i];

                arr[i] = arr[i - 1];
                arr[i - 1] = tmp;
            }
        }

        ++left;
    }
}
