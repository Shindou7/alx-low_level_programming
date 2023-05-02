#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * get_nodeint_at_index - check the code print get node int at index.
 * @head: head of a list.
 *
 * @index: index_of the node.
 * Return: if the node does not exist, return NULL
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int head_index = 0;

	do {
		if (head == NULL)
		{
			return (NULL);
		}
		head = head->next;
		head_index++;
	} while (head_index < index);

	return (head);
}
