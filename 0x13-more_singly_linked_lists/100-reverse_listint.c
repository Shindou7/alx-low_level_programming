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
	if (*head == NULL || (*head)->next == NULL)
	{
		return (*head);
	}

	listint_t *reve = reverse_listint(&((*head)->next));


	(*head)->next->next = *head;
	(*head)->next = NULL;


	return (reve);
}
