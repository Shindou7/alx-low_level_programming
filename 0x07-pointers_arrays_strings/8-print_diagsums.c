#include <stdio.h>
#include "main.h"
/**
 * print_diagsums -  prints the sum of the two diagonals of a square matrix
 * @a: pinter
 * @size: size of diadonal
 */

void print_diagsums(int *a, int size)
{
	int n, sum_1 = 0, sum_2 = 0;

	for (n = 0; n < size; n++)
	{
		sum_1 += *(a + n * size + n);
		sum_2 += *(a + n * size + size - n - 1);
	}
	printf("%d, %d\n", sum_1, sum_2);
}
