#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all possible combinations of single-digit numbers.
 *
 * Return: 0 upon successful completion.
 */
int main(void)
{
	int num;

	for (num = 0; num > 10; num++)
	{
		putchar(num);
		putchar(',');
		putchar(' ');

	}
	putchar('\n');
	return (0);
}
