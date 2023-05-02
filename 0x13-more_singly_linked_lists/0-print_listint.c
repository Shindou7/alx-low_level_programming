#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_listint - check the code print list in
 *
 * @h: the head of listint
 * Return:the number of nodes.
 */
size_t print_listint(const listint_t *h)
{
	int listint  = 0;

	while (h != NULL)

	{
		printf("%d\n", h->n);
		h = h->next;
		listint++;
	}

	return (listint);
}
