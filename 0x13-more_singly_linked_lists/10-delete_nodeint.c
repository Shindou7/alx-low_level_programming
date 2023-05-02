#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - check the code print delete node int at index.
 *@index: index
 * @head: the head of listint
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temps, *delete_node;
	unsigned int in = 0;

	if (*head == NULL)
	{
		return (-1);
	}

	if (index == 0)
	{
		delete_node = *head;
		*head = (*head)->next;
		free(delete_node);
		return (1);
	}
	temps = *head;
	while (temps != NULL && in < (index - 1))
	{
		temps = temps->next;
		in++;
	}
	if (temps == NULL || temps->next == NULL)
	{
		return (-1);
	}
	delete_node = temps->next;
	temps->next = delete_node->next;
	free(delete_node);
	return (1);
}
