#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
/**
 * _is_zero - determines if any number is zero
 * @argv: argument vector.
 *
 * Return: 1 if any number is zero, 0 otherwise.
 */
int _is_zero(char *argv[])
{
	int i;

	for (i = 1; i <= 2; i++)
	{
		if (strlen(argv[i]) == 1 && argv[i][0] == '0')
			return (1);
	}
	return (0);
}

/**
 * _initialize_array - set memory to zero in a new array
 * @ar: char array.
 * @lar: length of the char array.
 *
 * Return: pointer of a char array.
 */
char *_initialize_array(char *ar, int lar)
{
	int i;

	for (i = 0; i < lar; i++)
		ar[i] = '0';
	ar[lar] = '\0';
	return (ar);
}

/**
 * _checknum - determines length of the number
 * and checks if number is in base 10.
 * @argv: arguments vector.
 * @n: row of the array.
 *
 * Return: length of the number.
 */
int _checknum(char *argv[], int n)
{
	int ln = strlen(argv[n]);
	int i;

	for (i = 0; i < ln; i++)
	{
		if (!isdigit(argv[n][i]))
		{
			printf("Error\n");
			exit(98);
		}
	}
	return (ln);
}

/**
 * _multiply - multiplies two numbers
 * @a: first number as string.
 * @b: second number as string.
 *
 * Return: pointer to result string.
 */
char *_multiply(char *a, char *b)
{
	int la = strlen(a);
	int lb = strlen(b);
	char *res = malloc(la + lb + 1);
	int i, j, k, carry;

	if (res == NULL)
		return (NULL);

	_initialize_array(res, la + lb);

	for (i = la - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = lb - 1, k = i + j + 1; j >= 0; j--, k--)
		{
			int tmp = (a[i] - '0') * (b[j] - '0') + carry + (res[k] - '0');

			res[k] = (tmp % 10) + '0';
			carry = tmp / 10;
		}
		res[k] = carry + '0';
	}

	while (*res == '0' && *(res + 1) != '\0')
		res++;

	return (res);
}

/**
 * main - Entry point.
 * program that multiplies two positive numbers.
 * @argc: number of arguments.
 * @argv: arguments vector.
 *
 * Return: 0 - success.
 */
int main(int argc, char *argv[])
{
	char *a, *b, *res;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	if (_is_zero(argv))
	{
		printf("0\n");
		return (0);
	}

	a = argv[1];
	b = argv[2];

	res = _multiply(a, b);

	printf("%s\n", res);

	free(res);

	return (0);
}
