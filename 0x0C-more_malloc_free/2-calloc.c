#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array.
 * @nmemb: number of element .
 * @size: size of byte.
 * Return: pointer to the allocated memory if nmemb or size is 0, returns NULL
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	if (nmemb == 0 || size == 0)
		return (NULL);

	void *p = calloc(nmemb, size);

	return (p);
}
