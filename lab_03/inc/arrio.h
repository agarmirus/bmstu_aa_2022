#ifndef ARRIO_H
#define ARRIO_H

#include <stdio.h>
#include <stdlib.h>

#define INPUT_ERROR 1

int input_array_length(size_t *const length);

int input_array_elements(int *arr, const size_t length);

void print_array(int *arr, const size_t len);

#endif
