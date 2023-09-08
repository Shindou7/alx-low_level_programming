#include "hash_tables.h"

/**
 * add_node_a - adds a node at the beginning of a linked list
 *
 * @head: head of the linked list
 * @key: key of the node
 * @value: value of the node
 * Return: pointer to the new head of the list
 */
hash_node_t *add_node_a(hash_node_t *head, const char *key, const char *value)
{
	hash_node_t *new_node = malloc(sizeof(hash_node_t));

	if (!new_node)
		return (NULL);
	new_node->key = strdup(key);
	if (!new_node->key)
	{
		free(new_node);
		return (NULL);
	}
	new_node->value = strdup(value);
	if (!new_node->value)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}
	new_node->next = head;
	return (new_node);
}

/**
 * hash_table_set - adds a hash (key, value) to a given hash table
 *
 * @ht: pointer to the hash table
 * @key: key the hash
 * @value: value
 * Return: 1 if successful
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int k_index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	k_index = key_index((unsigned char *)key, ht->size);
	ht->array[k_index] = add_node_a(ht->array[k_index], key, value);
	return (1);
}
