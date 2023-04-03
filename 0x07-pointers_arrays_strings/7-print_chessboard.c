#include "main.h"
#include <stdio.h>

/**
 * print_chessboard - check the code
 *@a: pointer
 * Return: Always 0.
 */

void print_chessboard(char (*a)[8])
{
	int n;
	int m;

	for (n = 0; n <= 7; n++)
	{
		for (m = 0; m <= 7; m++)
		{
			_putchar(a[n][m]);
		}
		_putchar('\n');
	}
}
