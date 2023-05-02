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
	listint_t *current;
	listint_t *tmp;

	if (head != NULL)
	{
		current = *head;

		while ((tmp = current) != NULL)
		{
			current = current->next;
			free(tmp);
		}
		*head = NULL;
	}
}
