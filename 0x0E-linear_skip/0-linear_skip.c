#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 *
 * @list: Sorted skip list
 * @value: Value to search
 *
 * Return: Searched value
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *list_start, *list_end;

	if (!list)
		return (NULL);

	list_start = list;
	list_end = list_start->express;

	while (list_end)
	{
		if (value <= list_end->n || list_end->next != NULL)
			printf("Value checked at index [%lu] = [%d]\n",
			       list_end->index, list_end->n);

		if ((list_start->n <= value && value <= list_end->n) ||
		     list_end->next == NULL)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
			       list_start->index, list_end->index);
			break;
		}
		list_start = list_end;
		if (!(list_end->express) && list_end->next)
		{
			while (list_end->next)
				list_end = list_end->next;
		}
		else
			list_end = list_end->express;
	}

	while (list_start && list_start->index <= list_end->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       list_start->index, list_start->n);
		if (list_start->n == value)
			return (list_start);
		list_start = list_start->next;
	}
	return (NULL);
}
