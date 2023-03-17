#include <stdlib.h>
#include <time.h>
/**
 * main - Entry point
 * Discription the last digit
 * Return: Always 0
*/
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	if (n > 5)
	{
		printf("Last digit of %d is", n" and is greater than 5\n");
	}
	else if (n == 0)
	{
		printf("Last digit of %d is", n"and is 0\n");
	}
	else if
	{
		printf("Last digit of %d is", n"and is less than 6 and not 0\n");
	}

	return (0);
}
