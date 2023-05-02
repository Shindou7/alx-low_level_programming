#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * add_nodeint - check the code print list int len .
 *
 * @head: the head of listint
 * @n: n element
 * Return: the address of the new element, or NULL if it failed.
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *add_node;

	add_node = malloc(sizeof(listint_t));

	if (add_node == NULL)
	{
		free(add_node);
		return (NULL);
	}
	add_node->n = n;
	add_node->next = *head;
	*head = add_node;

	return (*head);
}
