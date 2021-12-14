#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - insert node in sorted singly linked list
 *
 * @head: head node
 * @number: value in the node
 * @return sorted node
 */

listint_t *insert_node(listint_t **head, int number)
{
        listint_t *new;
        listint_t *current;

        current = *head;

        new = malloc(sizeof(listint_t));

        if (new == NULL)
                return (NULL);

        new->n = number;
        new->next = NULL;

        if (*head == NULL)
                *head = new;
        else
        {
                while (current->next != NULL && current->next->n <= number)
                {
                        current = current->next;
                }
                current->n = number;
                current = new;
        
        }

        return (new);
}
