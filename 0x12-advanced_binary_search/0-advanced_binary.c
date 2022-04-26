#include "search_algos.h"
#include <stdio.h>

/**
 * print_array - Print an array
 *
 * @array: Array
 * @first: Size of array
 * @last:  value to find
 */

void print_array(int *array, int first, int last)
{
	int i;

	printf("Searching in array: ");

	for (i = first; i < last; i++)
		printf("%d, ", array[i]);

	printf("%d", array[i]);

	printf("\n");
}

/**
 * recursive_abs - Recursive advanced binary search
 *
 * @array: Array
 * @first: first element of array
 * @last:  last element of array
 * @value: value to find
 *
 * Return: EXIT_SUCCESS
 */

int recursive_abs(int *array, size_t first, size_t last, int value)
{
	size_t hlf;

	if (first < last)
	{
		hlf = first + (last - first) / 2;

		print_array(array, (int)first, (int)last);

		if (array[hlf] >= value)
			return (recursive_abs(array, first, hlf, value));
		else
			return (recursive_abs(array, hlf + 1, last, value));

		return ((int)(hlf));
	}

	if (array[first] == value)
		return (first);

	print_array(array, (int)first, (int)last);

	return (-1);
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 *
 * @array: Array
 * @size: Size of array
 * @valueue: value to find
 *
 * Return: value searched in array, -1 if not found
 */

int advanced_binary(int *array, size_t size, int valueue)
{
	size_t first;
	size_t last;

	if (!array)
		return (-1);

	first = 0;
	last = size - 1;

	return (recursive_abs(array, first, last, valueue));
}
