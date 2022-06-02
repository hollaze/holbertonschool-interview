#include "lists.h"

/**
 * find_listint_loop - find the loop in a single linked list
 *
 * @head: head node
 *
 * Return: the node where the loop occured
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *first_node, *second_node;

	first_node = head;
	second_node = head;

	while (head)
	{
		while (second_node && second_node->next)
		{
			second_node = second_node->next->next;
			first_node = first_node->next;

			if (second_node == first_node)
			{
				while (first_node)
				{
					first_node = first_node->next;

					if (first_node == head)
					{
						return (first_node);
					}

					else if (second_node == first_node)
					{
						head = head->next;
						break;
					}
				}
			}
		}

		head = head->next;
	}

	return (NULL);
}
