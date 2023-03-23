#include "main.h"

/**
 * print_line - draws a straight line in the terminal
 *
 * @n: is the number of times the character _ should be printed
 */

void print_line(int n)
{
	int a;
	int b;

	for (a = 0; a < n; a++)
	{
		for (b = 0; b < n; b++)
		{
			if (a == b)
				_putchar('\\');
			else if (b < a)
				_putchar(' ');
		}
		_putchar('\n');
	}
}
