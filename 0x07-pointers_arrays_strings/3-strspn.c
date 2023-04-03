#include "main.h"

/**
 * _strspn -  function that gets the length of a prefix substring
 * @s:  the number of bytes in the initial segment
 * @accept: consist only of bytes
 * Return: return the number of bytes
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int n;
	unsigned int m;
	unsigned int Acc = 0;

	for (n = 0; s[n]; n++)
	{
		for (m = 0; accept[m]; m++)
		{
			if (s[m] == accept[m])
			{
				Acc++;
				break;
			}
		}
		if (!accept[m])
			break;
	}
	return (Acc);
}
