#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * reverse_listint -   that reverses a listint_t linked list.
 * @head: the head of reverse listint.
 * Return: a pointer to the first node of the reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *pop, *node;

	pop = NULL;

	node = NULL;

	while (*head != NULL)
	{

		node = (*head)->next;

		(*head)->next = pop;

		pop = *head;

		*head = node;
	}

	*head = pop;

	return (*head);
}
