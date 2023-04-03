#include "main.h"
#include <stddef.h>

/**
 * _strchr -  function that locates a character in a string
 * @c: the first occurrence of the character
 * @s: the first occurrence of the string
 * Return: return a pointer null
 */

char *_strchr(char *s, char c)
{
	char *p;

	for (p = s; *p != '\0'; p++)
	{
		if (*p == c)
		{
			return (p);
		}
	}
	return (NULL);
}
