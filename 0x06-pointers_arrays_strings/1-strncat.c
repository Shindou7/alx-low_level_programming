#include "main.h"
/**
 * _strncat - concatenate two strings,
 * @dest: destination string.
 * @src: source string.
 * @n: the byte usefrom source.
 * Return: return to dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	int dest_len = 0;

	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}

	int i;

	for (i = 0; i < n; i++)
	{
		if (src[i] != '\0')
		{
			dest[dest_len + i] = src[i];
		}

		else
		{
			break;
		}
	}

	dest[dest_len + i] = '\0';
	return (dest);
}
