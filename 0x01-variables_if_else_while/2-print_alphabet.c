#include <stdio.h>
/**
 *main - Entry point
 *Dicription : Write a program that prints the alphabet in lowercase
 *Return : Always 0
*/
int main(void)
{
	char alphab;

	for (alphab = 'a'; alphab <= 'z'; alphab++)
	{
		putchar(alphab);
	}
	putchar('\n');
	return (0);
}
