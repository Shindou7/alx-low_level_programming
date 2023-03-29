#include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * infinite_add - adds two numbers
 * @n1: first number as a string
 * @n2: second number as a string
 * @r: buffer to store the result
 * @size_r: size of the buffer
 * Return: pointer to the result, or 0 if the result cannot be stored in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = strlen(n1);
	int len2 = strlen(n2);
	int len = len1 > len2 ? len1 : len2;
	int carry = 0;
	int i, j;

	if (len + 1 > size_r)
		return (0);
	r[len + 1] = '\0';
	for (i = len - 1, j = len1 - 1; j >= 0; i--, j--)
		r[i] = n1[j];
	for (i = len - 1, j = len2 - 1; j >= 0; i--, j--)
	{
		int digit = carry + (r[i] - '0') + (n2[j] - '0');

		if (digit > 9)
		{
			carry = 1;
			digit -= 10;
		}
		else
		{
			carry = 0;
		}
		r[i] = digit + '0';
	}
	if (carry)
	{
		if (len + 2 > size_r)
			return (0);
		for (i = len; i >= 0; i--)
			r[i + 1] = r[i];
		r[0] = carry + '0';
	}
	return (r);
}
