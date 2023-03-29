#include "main.h"
#include <stdio.h>
/**
 * print_buffer - prints a buffer
 * @b: buffer.
 * @size: size of buffer.
 * Return: void.
 */
void print_buffer(char *b, int size)
{
	int o, j, i;

	if (size <= 0)
	{
		printf("\n");
		return;
	}
	for (o = 0; o < size; o += 10)
	{
		j = size - o < 10 ? size - o : 10;
		printf("%08x: ", o);
		for (i = 0; i < 10; i++)
		{
			if (i < j)
				printf("%02x", *(b + o + i));
			else
				printf("  ");
			if (i % 2)
				printf(" ");
		}
		for (i = 0; i < j; i++)
			printf("%c", *(b + o + i) < 32 || *(b + o + i) > 132 ? '.' : *(b + o + i));
		printf("\n");
	}
}
