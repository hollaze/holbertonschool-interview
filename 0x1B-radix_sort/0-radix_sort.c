#include "sort.h"

/**
 * find_max - find the maximum value in an array of int
 *
 * @array: array of int
 * @len: size of the array
 *
 * Return: The maximum value of the array
 */
int find_max(int *array, size_t len)
{
	int max = array[0];
	size_t i;

	for (i = 0; i < len; i++)
	{
		if (max <= array[i])
			max = array[i];
	}

	return (max);
}

/**
 * radix_count_sort - count the number of digits of the maximum value
 *
 * @array: array to be sorted
 * @size: size of the array
 * @dig: integer by which the array is divided to get the digit
 */
void radix_count_sort(int *array, int size, int dig)
{
	int *bucket, *bucket_count, i;

	bucket = malloc(sizeof(int) * size);
	bucket_count = malloc(sizeof(int) * (find_max(array, size) + 1));

	if (bucket_count == NULL || bucket == NULL)
	{
		free(bucket_count);
		free(bucket);
	}

	for (i = 0; i <= find_max(array, size); i++)
		bucket_count[i] = 0;

	for (i = 0; i < size; i++)
		bucket_count[array[i] / dig % 10]++;

	for (i = 1; i <= find_max(array, size); i++)
		bucket_count[i] += bucket_count[i - 1];

	for (i = size - 1; i >= 0; i--)
		bucket[bucket_count[array[i] / dig % 10]-- - 1] = array[i];

	for (i = 0; i < size; i++)
		array[i] = bucket[i];

	free(bucket_count);
	free(bucket);
}

/**
 * radix_sort - sort an array using radix sort algorithm
 *
 *@array: array to sort
 *@size: size of the array
 */
void radix_sort(int *array, size_t size)
{

	int i, max;

	if (array == NULL || size <= 1)
	{
		return;
	}

	max = find_max(array, size);

	for (i = 1; max / i > 0; i *= 10)
	{
		radix_count_sort(array, size, i);
		print_array(array, size);
	}
}
