#include "sort.h"
#include <stdio.h>

/**
 * swap - Swap a and b values
 *
 * @a: int
 * @b: int
 */

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * heap - To heap a subtree
 *
 * @arr: array
 * @n: Size
 * @i: Index
 * @size: Size of the array
 *
 * Return: void
 */

void heap(int arr[], int n, size_t size, int i)
{
	int max = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[max])
		max = l;

	if (r < n && arr[r] > arr[max])
		max = r;

	if (max != i)
	{
		swap(&arr[i], &arr[max]);
		print_array(arr, size);
		heap(arr, n, size, max);
	}
}

/**
 * heap_sort - Heap sort
 *
 * @arr: array of int to sort
 * @n: Size of the array
 *
 * Return: void
 */
void heap_sort(int arr[], size_t n)
{
	int i;

	if (!arr)
		return;

	for (i = n / 2 - 1; i >= 0; i--)
		heap(arr, n, n, i);

	for (i = n - 1; i > 0; i--)
	{

		swap(&arr[0], &arr[i]);
		print_array(arr, n);
		heap(arr, i, n, 0);
	}

	swap(&arr[0], &arr[i]);
	heap(arr, i, n, 0);
}
