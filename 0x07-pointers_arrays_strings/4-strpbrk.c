#include "main.h"

/**
 * _strpbrk -  unction that searches a string for any of a set of bytes
 * @s:  the first occurrence in the string
 * @accept: any of the bytes in the string
 * Return: return the number of bytes
 */

char *_strpbrk(char *s, char *accept)
{
	unsigned int n;
	unsigned int m;

	for (n = 0; *(s + n) != '\0'; n++)
	{
		for (m = 0; *(accept + m) != '\0'; m++)
		{
			if (*(s + n) == *(accept + m))
			{
				return (s + n);
			}
		}
	}
	return ('\0');
}
