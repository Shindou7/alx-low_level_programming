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
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
	s++;
	}
	if (*s == c)
	{
		return (s);
	}
	return ('\0');
}
