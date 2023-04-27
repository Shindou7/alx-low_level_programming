#include "lists.h"


/**
 * print_list - prints all the elements of a `list_t list.
 * @h: singly linked listss ,pointer to the head node of the list.
 *
 * Return: The number of nodes in the list.
 *
 */

size_t print_list(const list_t *h)
{
	size_t numb_nodes = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);

		h = h->next;
		numb_nodes++;
	}
	return (numb_nodes);
}
