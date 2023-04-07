#include "main.h"

/**
 * _strstr - function that locates a substring
 * @haystack: the string to search
 * @needle: function finds the first occurrence of the substring
 *
 * Return: pointer to the beginning of the located sub
 */
char *_strstr(char *haystack, char *needle)
{
	while (*haystack != '\0')
	{
		char *m = haystack;
		char *n = needle;

		while (*n == *haystack && *n != '\0')
		{
			n++;
			haystack++;
		}
		if (*n == '\0')
			return (m);
		haystack = m + 1;
	}
	return ('\0');
}
