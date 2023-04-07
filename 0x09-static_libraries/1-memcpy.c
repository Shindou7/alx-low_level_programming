#include "main.h"

/**
 * _memcpy - The _memcpy function copies n
 * @n: bytes from memory area
 * @src: memory area source
 * @dest: memory area distination
 * Return: Returns a pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	return (dest);
}
