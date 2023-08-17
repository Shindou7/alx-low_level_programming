#include "lists.h"

/**
 * generate_password - Generates a password based on given input
 * @input: The input string.
 *
 * This function generates a password based
 */
void generate_password(char *input)
{
	char password[7], *cipher;
	int len = strlen(input), i, x;

	cipher = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	x = (len ^ 59) & 63;
	password[0] = cipher[x];
	x = 0, i = 0;
	while (i < len)
	{
		x += input[i];
		i++;
	} password[1] = cipher[(x ^ 79) & 63];
	x = 1, i = 0;
	while (i < len)
	{
		x *= input[i];
		i++;
	} password[2] = cipher[(x ^ 85) & 63];
	x = 0, i = 0;
	while (i < len)
	{
		if (input[i] > x)
			x = input[i];
		i++;
	} srand(x ^ 14);
	password[3] = cipher[rand() & 63];
	x = 0, i = 0;
	while (i < len)
	{
		x += (input[i] * input[i]);
		i++;
	} password[4] = cipher[(x ^ 239) & 63];
	i = 0, x = 0;
	while (i < input[0])
	{
		x = rand();
		i++;
	} password[5] = cipher[(x ^ 229) & 63];
	password[6] = '\0';
	printf("%s", password);
}

/**
 * main - Generates  executable.
 * @argc: The number of argumen
 * @argv: An array of point.
 *
 * Return: Always 0.
 */
int main(__silent int argc, char *argv[])
{
	generate_password(argv[1]);
	return (0);
}
