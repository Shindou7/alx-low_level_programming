#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main -  the hacker.
 * Return: Always 0.
 */

int main(void)
{
	srand(time(NULL));
	int sum = 0;

	while (sum < 2772)
	{
		int random = rand() % 128;

		sum += random;
		putchar(random);
	}

	putchar(2772 - sum);
	putchar('\n');
	return (0);
}
