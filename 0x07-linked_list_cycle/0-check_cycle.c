#include "lists.h"

/**
 * check_cycle - check if linked list is a cycle linked list
 *
 * @list: linked list to check
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */

int check_cycle(listint_t *list)
{
	listint_t *node;

	if (list == NULL)
		return (0);

	node = list->next;

	while (node != NULL && node != list)
	{
		node = node->next;
	}

	return (node == list);
}
