#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void radix_sort(int *array, size_t size);
int find_max(int *array, size_t len);
void radix_count_sort(int *array, int size, int dig);

#endif /* SORT_H */
