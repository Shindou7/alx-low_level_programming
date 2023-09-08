#include "hash_tables.h"

/**
 * key_index - index of a key
 * @key: key
 * @size: size hash table array
 * Return: index
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int idx;

	if (size == 0)
		return (0);
	idx = hash_djb2(key);
	return (idx % size);
}
