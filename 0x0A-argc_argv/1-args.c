#include <stdio.h>


/**
 * main - function takes two arguments:
 * argc (argument count) and argv (argument vector)
 * @argc: argument count  is the number of arguments passed to the program
 * @argv: arguments is an array of strings containing the arguments
 *
 * Return: always 0.
 */

int main(int argc, char *argv[])
{
	printf("%d\n", argc - 1);
	return (0);
}
