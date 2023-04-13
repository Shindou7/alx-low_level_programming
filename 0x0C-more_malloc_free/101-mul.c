#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
/**
 * _checknum - determines length of the number and checks ifnumberis in base 10
 * @num: input number as string.
 * Return: length of the number.
 */
int _checknum(char *num)
{
	int len = strlen(num);
	int i;

	for (i = 0; i < len; i++)
	{
		if (!isdigit(num[i]))
		{
			printf("Error\n");
			exit(98);
		}
	}
	return (len);
}
/**
 * _reverse - reverse a string in place.
 * @str: input string to reverse.
 * Return: pointer to reversed string.
 */
char *_reverse(char *str)
{
	int len = strlen(str);
	int i;

	for (i = 0; i < len / 2; i++)
	{
		char temp = str[i];

		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}
	return (str);
}
/**
 * main - Entry point. Program that multiplies two positive numbers.
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: 0 - success.
 */
int main(int argc, char *argv[])
{
	int i, j, len1, len2;
	char *result;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}
	if (strcmp(argv[1], "0") == 0 || strcmp(argv[2], "0") == 0)
	{
		printf("0\n");
		return (0);
	}
	len1 = _checknum(argv[1]);
	len2 = _checknum(argv[2]);
	result = (char *) calloc(len1 + len2 + 1, sizeof(char));

	_reverse(argv[1]);
	_reverse(argv[2]);
	for (i = 0; i < len1; i++)
	{
		for (j = 0; j < len2; j++)
		{
			int product = (argv[1][i] - '0') * (argv[2][j] - '0');
			int sum = result[i + j] + product;

			result[i + j] = sum % 10;
			result[i + j + 1] += sum / 10;
		}
	}
	_reverse(result);
	while (result[i] == 0)
		i++;
	if (i == len1 + len2)
		i--;
	for (; i < len1 + len2; i++)
	{
		printf("%d", result[i]);
	}
	printf("\n");
	free(result);
	return (0);
}
