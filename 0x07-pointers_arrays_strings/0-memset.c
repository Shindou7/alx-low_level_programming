#include "main.h"
#include <stdio.h>

/**
 * _memset - prints buffer in hexa
 * @n:  bytes of the memory area pointed
 * @b: the constant byte
 * @s:  the memory area
 * Return: return s.
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}
