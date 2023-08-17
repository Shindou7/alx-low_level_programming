#include <stdlib.h>
#include "lists.h"

/**
  * dlistint_len - Counts the number
  * @h: ....
  * Return: ....
  */
size_t dlistint_len(const dlistint_t *h)
{
	int lenghts = 0;

	while (h != NULL)
	{
		++lenghts;
		h = h->next;
	}

	return (lenghts);
}
