#include "lists.h"

/**
 * delete_dnodeint_at_index - ............
 * @head: ...........
 * @index: .....
 * Return: .....
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *head1;
	dlistint_t *head2;
	unsigned int n;

	head1 = *head;

	if (head1 != NULL)
		while (head1->prev != NULL)
			head1 = head1->prev;

	n = 0;

	while (head1 != NULL)
	{
		if (n == index)
		{
			if (n == 0)
			{
				*head = head1->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}
			else
			{
				head2->next = head1->next;

				if (head1->next != NULL)
					head1->next->prev = head2;
			}

			free(head1);
			return (1);
		}
		head2 = head1;
		head1 = head1->next;
		n++;
	}

	return (-1);
}
