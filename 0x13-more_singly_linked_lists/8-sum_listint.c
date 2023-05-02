#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * sum_listint - check the code print sum list int
 *
 * @head: the head of listint
 * Return: if the list is empty, return 0.
 */
int sum_listint(listint_t *head)
{
	int add = 0;

	for (; head != NULL; head = head->next)
	{
		add += head->n;
	}
	return (add);
}
