#ifndef SORT_H
#define SORT_H

#include <stddef.h>

void print_array(const int *array, size_t size);
void swap(int *a, int *b);
void heap(int arr[], int n, size_t size, int i);
void heap_sort(int *array, size_t size);

#endif /* SORT_H */
