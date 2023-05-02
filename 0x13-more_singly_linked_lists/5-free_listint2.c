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
	if (head == NULL)
	{
		return;
	}

	listint_t *new_list = *head;

	while (new_list != NULL)
	{
		listint_t *add_nodeint = new_list;

		new_list = new_list->next;
		free(add_nodeint);
	}
	*head = NULL;
}
