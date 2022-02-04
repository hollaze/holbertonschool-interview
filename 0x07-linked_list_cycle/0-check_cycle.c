#include "lists.h"

/**
 * check_cycle - check if linked list is a cycle linked list
 *
 * @list: linked list to check
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */

int check_cycle(listint_t *list)
{
	listint_t *node, *temp;

	if (list == NULL)
		return (0);

	temp = list;
	node = list->next;

	while (node && temp && node->next)
	{
		temp = temp->next;
		node = node->next->next;

		if (temp == node)
			return (1);
	}

	return (0);
}
