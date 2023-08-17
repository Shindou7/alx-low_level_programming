#include "lists.h"

/**
 * insert_dnodeint_at_index - .........
 * @h: ......
 * @idx: ........
 * @n: .......
 * Return: .....
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *temp = *h, *_new;

	if (idx == 0)
		return (add_dnodeint(h, n));

	for (; idx != 1; idx--)
	{
		temp = temp->next;
		if (temp == NULL)
			return (NULL);
	}

	if (temp->next == NULL)
		return (add_dnodeint_end(h, n));

	_new = malloc(sizeof(dlistint_t));
	if (_new == NULL)
		return (NULL);

	_new->n = n;
	_new->prev = temp;
	_new->next = temp->next;
	temp->next->prev = _new;
	temp->next = _new;

	return (_new);
}
