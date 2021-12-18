#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - insert node in sorted singly linked list
 *
 * @head: head node
 * @number: value in the node
 * Return: sorted node
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;

	new = malloc(sizeof(listint_t));

	if (new == NULL)
		return (NULL);

	new->n = number;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	current = *head;

	/* add node at the beginning if value is lower than */
	/* first node value */
	if (current->n > new->n)
	{
		new->next = current;
		*head = new;
		return (new);
	}

	while (current->next != NULL)
	{
		/* current->next->n is the last node value we are in */
		/* new->n is the node value we want to place */
		if (current->next == NULL || current->next->n > new->n)
		{
			/* set where the node needs to be placed */
			new->next = current->next;
			/* place the node */
			current->next = new;
			return (new);
		}
		/* go through linked list */
		current = current->next;
	}

	if (current->n <= new->n)
	{
		add_nodeint_end(head, number);
	}

	return (new);
}
