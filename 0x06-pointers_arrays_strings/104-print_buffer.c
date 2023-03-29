#include "main.h"
#include <stdio.h>
/**
 * print_buffer - prints a buffer
 *@b: buffer.
 *@size: size of buffer.
 * Return: void
 */
void print_buffer(char *b, int size)
{
	if (size <= 0)
	{
		printf("\n");
		return;
	}
	int i;

	for (i = 0; i < size; i += 10)
	{
		printf("%08x: ", i);
		int j;

		for (j = 0; j < 10; j++)
		{
			if (i + j < size)
				printf("%02x", b[i + j]);
			else
				printf("  ");
			if (j % 2)
				printf(" ");
		}
		printf(" ");
		for (j = 0; j < 10; j++)
		{
			if (i + j < size)
			{
				char c = b[i + j];

				if (c >= 32 && c <= 126)
					printf("%c", c);
				else
					printf(".");
			}
		}
		printf("\n");
	}
}
