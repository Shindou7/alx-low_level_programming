#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_listint - check the code print free list int
 *
 * @head: the head of listint
 * Return:no return.
 */

void free_listint(listint_t *head)
{
	listint_t *add_nodeint;

	add_nodeint = head;

	while (add_nodeint != NULL)
	{
		add_nodeint = add_nodeint->next;
		free(head);
		head = add_nodeint;
	}
}
