#include "main.h"

/**
 * _strncat - concatenates two strings,
 * @dest: destination.
 * @src: source.
 * @n: amount of bytes used from src.
 * Return: the pointer to dest.
 */

char *_strncat(char *dest, char *src, int n)
{
	int dest_len = 0;

	while (dest[dest_len])
		dest_len++;

	int i;

	for (i = 0; i < n && src[i]; i++)
		dest[dest_len++] = src[i];
	dest[dest_len] = '\0';
	return (dest);
}
