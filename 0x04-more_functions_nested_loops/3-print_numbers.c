#include "main.h"

/**
 * print_numbers - prints the numbers, from 0 to 9
 *
 * Return: no return.
 */

void print_numbers(void)
{
	int numb;

	for (numb = 48; numb < 58; numb++)
	{
		_putchar(numb);
	}
	_putchar('\n');
}
