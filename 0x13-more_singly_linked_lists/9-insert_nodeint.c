#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_nodeint_at_index -  that inserts a new node at a given position
 * @head: the head of listint
 * @idx:  index of node int
 * @n: integer
 * Return:  the address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int in = 0;
	listint_t *xnew_node, *tmp_node = *head;

	xnew_node = malloc(sizeof(listint_t));

	if (xnew_node == NULL)
	{
		return (NULL);
	}
	xnew_node->n = n;
	if (idx == 0)
	{
		xnew_node->next = *head;
		*head = xnew_node;
		return (xnew_node);
	}
	while (in < idx - 1 && tmp_node != NULL)
	{
		tmp_node = tmp_node->next;
		in++;
	}
	if (tmp_node == NULL)
	{
		free(xnew_node);
		return (NULL);
	}
	xnew_node->next = tmp_node->next;
	tmp_node->next = xnew_node;
	return (xnew_node);
}
