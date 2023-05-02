#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * listint_len - check the code print list int len .
 *
 * @h: the head of listint
 * Return:the number of nodes.
 */
size_t listint_len(const listint_t *h)
{
	int listint  = 0;

	while (h != NULL)

	{

		h = h->next;
		listint++;
	}

	return (listint);
}
