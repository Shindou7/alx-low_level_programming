#include "lists.h"

/**
 * sum_dlistint - ......
 * @head: head of the list
 * Return: sum of the data
 */

int sum_dlistint(dlistint_t *head)
{
	int result;

	result = 0;

	if (head != NULL)
	{
		while (head->prev != NULL)
			head = head->prev;

		while (head != NULL)
		{
			result += head->n;
			head = head->next;
		}
	}

	return (result);
}
