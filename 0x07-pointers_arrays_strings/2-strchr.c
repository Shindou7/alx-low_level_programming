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
	for (s = 0; *s != '\0'; s++)
	{
		if (*s == c)
		{
			return (s);
		}
	}
	return (NULL);
}
