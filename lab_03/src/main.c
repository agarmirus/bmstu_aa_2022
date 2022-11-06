#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "arrio.h"
#include "arrlib.h"
#include "pancakesort.h"
#include "cocktailsort.h"
#include "selectionsort.h"

#define MEMORY_ALLOCATION_ERROR 2

#define MEASURMENTS_COUNT 1000

typedef enum
{
    EXIT,
    PANCAKE_SORT,
    COCKTAIL_SORT,
    SELECTION_SORT
} cmd_t;

static void print_menu(void)
{
    printf("Меню\n\n" \
    "1. Блинная сортировка\n" \
    "2. Сортировка перемешиванием\n" \
    "3. Сортировка выбором\n\n" \
    "0. Выход\n\n" \
    "Введите команду: ");
}

static int input_command(cmd_t *const cmd)
{
    int tmp;

    int rc = scanf("%d", &tmp);

    if (rc != 1 || (tmp < EXIT || tmp > SELECTION_SORT))
        return INPUT_ERROR;
    
    *cmd = tmp;

    return EXIT_SUCCESS;
}

static int input_array(int **arr, size_t *const length)
{
    printf("\nВведите размер массива: ");

    int rc = input_array_length(length);

    if (rc != EXIT_SUCCESS)
        return rc;
    
    *arr = arralloc(*length);

    if (!(*arr))
        return MEMORY_ALLOCATION_ERROR;

    printf("Введите элементы массива: ");

    rc = input_array_elements(*arr, *length);

    if (rc != EXIT_SUCCESS)
    {
        free(*arr);

        *arr = NULL;

        return rc;
    }

    return EXIT_SUCCESS;
}

static int measure_sorting_time(
    double *const avrg_time,
    const int *arr,
    const size_t length,
    void (*sort)(int *, const size_t)
)
{
    int *arr_copy = arralloc(length);

    if (!arr_copy)
        return MEMORY_ALLOCATION_ERROR;
    
    clock_t time = 0;

    for (size_t i = 0; i < MEASURMENTS_COUNT; ++i)
    {
        arrcpy(arr_copy, arr, length);

        clock_t start = clock();

        sort(arr_copy, length);

        time += clock() - start;
    }

    *avrg_time = (double)time / CLOCKS_PER_SEC;

    return EXIT_SUCCESS;
}

static int perform_sort(void (*sort)(int *, const size_t))
{
    int *arr = NULL;
    size_t length = 0;

    int rc = input_array(&arr, &length);

    if (rc != EXIT_SUCCESS)
        return rc;

    double avrg_time = 0.0;

    rc = measure_sorting_time(&avrg_time, arr, length, sort);

    if (rc != EXIT_SUCCESS)
        return rc;

    printf("\nМассив до сортировки:\t\t");
    print_array(arr, length);

    sort(arr, length);

    printf("Массив после сортировки:\t");
    print_array(arr, length);

    printf("\nСреднее время сортировки: %lf сек\n\n", avrg_time);

    free(arr);

    return EXIT_SUCCESS;
}

static int perform_command(bool *const running, const cmd_t cmd)
{
    if (cmd == PANCAKE_SORT)
        return perform_sort(pancake_sort);
    else if (cmd == COCKTAIL_SORT)
        return perform_sort(cocktail_sort);
    else if (cmd == SELECTION_SORT)
        return perform_sort(selection_sort);
    
    *running = false;

    return EXIT_SUCCESS;
}

int main(void)
{
    bool running = true;

    while (running)
    {
        print_menu();

        cmd_t cmd = EXIT;

        int rc = input_command(&cmd);

        if (rc != EXIT_SUCCESS)
            return rc;

        rc = perform_command(&running, cmd);

        if (rc != EXIT_SUCCESS)
            return rc;
    }

    return EXIT_SUCCESS;
}
