#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_listint2 - check the code print free list int2
 *
 * @head: the head of listint
 * Return:no return.
 */

void free_listint2(listint_t **head)
{
	listint_t *add_nodeint;

	add_nodeint = *head;

	if (head == 0)
	{
		return;
	}
	while (add_nodeint)
	{
		add_nodeint = add_nodeint->next;
		free(*head);
		*head = add_nodeint;
	}
	head = NULL;
}
