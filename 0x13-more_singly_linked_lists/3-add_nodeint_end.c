#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * add_nodeint_end - check the code Add node at the end .
 *
 * @head: the head of listint
 * @n: n element
 * Return: the address of the new element, or NULL if it failed.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *add_nod_end;
	listint_t *add_nodeint = *head;

	add_nod_end = malloc(sizeof(listint_t));

	if (add_nod_end != NULL)
	{
		return (NULL);
	}

	add_nod_end->n = n;
	add_nod_end->next = NULL;

	if (*head == NULL)
	{
		*head = add_nod_end;
		return (*head);
	}
	while (add_nodeint->next != NULL)
	{
		add_nodeint = add_nodeint->next;
	}
	add_nodeint->next = add_nod_end;

	return (*head);
}
