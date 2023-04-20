#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main - print point
 * @argc: number of argument
 * @argv: nrray of argument
 * Return: always 0 (Success)
 */

int main(int argc, char *argv[])
{
	int a, b;
	int (*operation)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	a = atoi(argv[1]);
	b = atoi(argv[3]);
	operation = get_op_func(argv[2]);

	if (!operation)
	{
		printf("Error\n");
		exit(99);
	}
	printf("%d\n", operation(a, b));
	return (0);
}
