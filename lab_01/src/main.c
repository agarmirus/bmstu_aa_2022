#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "recdamlev.h"
#include "nonreclev.h"
#include "nonrecdamlev.h"
#include "cachedamlev.h"

#define MAX_STR_LENGHT 100

int input_strs(char *s1, char *s2)
{
    printf("Введите первую строку: ");
    if (!fgets(s1, MAX_STR_LENGHT, stdin) || strlen(s1) == 0)
        return INPUT_ERROR;
    
    s1[strlen(s1) - 1] = '\0';

    printf("Введите вторую строку: ");
    if (!fgets(s2, MAX_STR_LENGHT, stdin) || strlen(s2) == 0)
        return INPUT_ERROR;
    
    s2[strlen(s2) - 1] = '\0';

    return EXIT_SUCCESS;
}

void print_results(
    const size_t non_rec_lev_res,
    const size_t non_rec_dam_lev_res,
    const size_t rec_dam_lev_res,
    const size_t cache_dam_lev_res,
    const double non_rec_lev_time,
    const double non_rec_dam_lev_time,
    const double rec_dam_lev_time,
    const double cache_dam_lev_time
)
{
    printf(
        "Нерекурсивный алгоритм поиска расстояния Левенштейна\n" \
        "Результат: %zu\n"
        "Время: %lf\n\n",
        non_rec_lev_res, non_rec_lev_time
    );

    printf(
        "Нерекурсивный алгоритм поиска расстояния Дамерау-Левенштейна\n" \
        "Результат: %zu\n"
        "Время: %lf\n\n",
        non_rec_dam_lev_res, non_rec_dam_lev_time
    );

    printf(
        "Рекурсивный алгоритм поиска расстояния Дамерау-Левенштейна\n" \
        "Результат: %zu\n"
        "Время: %lf\n\n",
        rec_dam_lev_res, rec_dam_lev_time
    );

    printf(
        "Алгоритм поиска расстояния Дамерау-Левенштейна с кэшированием\n" \
        "Результат: %zu\n"
        "Время: %lf\n\n",
        cache_dam_lev_res, cache_dam_lev_time
    );
}

int perform_algorithms(const char *s1, const char *s2)
{
    size_t non_rec_lev_res = 0;
    clock_t start = clock();
    int rc = non_rec_lev(&non_rec_lev_res, s1, s2);
    double non_rec_lev_time = (clock() - start) / CLOCKS_PER_SEC;

    if (rc != EXIT_SUCCESS)
        return rc;

    size_t non_rec_dam_lev_res = 0;
    start = clock();
    rc = non_rec_dam_lev(&non_rec_dam_lev_res, s1, s2);
    double non_rec_dam_lev_time = (clock() - start) / CLOCKS_PER_SEC;

    if (rc != EXIT_SUCCESS)
        return rc;

    start = clock();
    size_t rec_dam_lev_res = rec_dam_lev(s1, s2, strlen(s1), strlen(s2));
    double rec_dam_lev_time = (clock() - start) / CLOCKS_PER_SEC;

    mtrx_t cache = {0, 0, NULL};
    size_t cache_dam_lev_res = 0;
    start = clock();
    rc = cache_dam_lev(&cache_dam_lev_res, &cache, s1, s2, strlen(s1), strlen(s2));
    double cache_dam_lev_time = (clock() - start) / CLOCKS_PER_SEC;

    if (rc != EXIT_SUCCESS)
        return rc;

    print_results(
        non_rec_lev_res, non_rec_dam_lev_res,
        rec_dam_lev_res, cache_dam_lev_res,
        non_rec_lev_time, non_rec_dam_lev_time,
        rec_dam_lev_time, cache_dam_lev_time
    );

    return EXIT_SUCCESS;
}

int main(void)
{
    char s1[MAX_STR_LENGHT];
    char s2[MAX_STR_LENGHT];

    int rc = input_strs(s1, s2);

    if (rc != EXIT_SUCCESS)
        return rc;
    
    rc = perform_algorithms(s1, s2);

    return rc;
}
