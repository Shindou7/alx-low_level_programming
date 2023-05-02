#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * pop_listint - check the code print pop list int2
 *
 * @head: the head of pop listint
 * Return:no return.
 */
int pop_listint(listint_t **head)
{
	int pop_node;
	listint_t *headd;
	listint_t *current;

	if (*head == NULL)
	{
		return (0);
	}
	current = *head;

	pop_node = current->n;
	headd = current->next;
	free(current);
	*head = headd;

	return (pop_node);
}
