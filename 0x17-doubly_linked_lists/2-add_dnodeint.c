#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
  * add_dnodeint - ....
  * @head: ......
  * @n: ....
  * Return: .....
  */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *_node = NULL;

	_node = malloc(sizeof(dlistint_t));
	if (_node == NULL)
		return (NULL);

	_node->n = n;
	if (*head)
	{
		_node->next = *head;
		_node->prev = (*head)->prev;
		(*head)->prev = _node;
		*head = _node;
		return (*head);
	}

	_node->next = *head;
	_node->prev = NULL;
	*head = _node;
	return (*head);
}
