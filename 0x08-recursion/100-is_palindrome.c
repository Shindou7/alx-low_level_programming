#include "main.h"

/**
 * is_palindrome - detects if a string is a palindrome.
 * @s: input string.
 * Return:  that returns 1 if a string is a palindrome and 0 if not.
 */
int is_palindrome(char *s)
{
	int len = 0;

	while (*(s + len) != '\0')
		len++;

	for (int i = 0; i < len / 2; i++)
	{
		if (*(s + i) != *(s + len - i - 1))
			return (0);
	}
	return (1);
}
