#include <stdio.h>
#include <stdlib.h>

/**
 * main - check the code for ALX School students.
 * @argc: argument count.
 * @argv: argument vector.
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	int nbytes = atoi(argv[1]);

	if (nbytes < 0)
	{
		printf("Error\n");
		return (2);
	}

	unsigned char *opc = (unsigned char *) main;

	for (int i = 0; i < nbytes; i++)
	{
		printf("%02x ", opc[i]);
	}
	printf("\n");
	return (0);
}
