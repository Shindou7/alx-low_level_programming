#include "lists.h"

/**
 * free_dlistint - Frees a linked_dlistint
 * @head: The head
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *new;

	while (head)
	{
		new = head->next;
		free(head);
		head = new;
	}
}
