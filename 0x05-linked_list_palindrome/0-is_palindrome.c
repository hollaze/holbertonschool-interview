#include "lists.h"
#include <stdlib.h>

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 *
 * @head: head node
 *
 * Return: 1 if singly linked list is a palindrome, 0 otherwise
 */

int is_palindrome(listint_t **head)
{
	listint_t *new_node, *temp;

	if (*head == NULL || (*head)->next == NULL)
		return (1);

	new_node = *head;
	temp = *head;

	/* Discovered that new_node->next is the same as */
	/* new_node += 2 */
	while (new_node->next)
	{
		new_node += 2;
	}

	while (temp->next)
	{
		/* Discovered that going in reverse with a node is */
		/* the same as new_node -= 2 */
		if (new_node->n == temp->n)
		{
			temp = temp->next;
			new_node -= 2;
		}
		else
		{
			return (0);
		}
	}

	return (1);
}
