#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge(int *array, int start, int mid, int end, int *copy);
void split(int *array, int start, int end, int *copy);

#endif /* SORT_H */
