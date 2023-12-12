#include "search_algos.h"

/**
 * binary_search - calls to binary_search to return
 * the index of the number
 *
 * @array: input array
 * @size: size of the array
 * @value: value to search in
 * Return: index of the number
 */
int binary_search(int *array, size_t size, int value)
{
	size_t i, start, stop;

	if (!size)
		goto KILL;

	stop = size - 1;
	i = stop / 2;
	start = 0;

	for (; start <= stop;)
	{
		printf("Searching in array: ");
		print_array(array, start, stop);
		if (value == array[i])
			return (i);
		else if (value < array[i])
			stop = i - 1;
		else
			start = i + 1;
		i = (stop - start) / 2;
		i += start;
	}
KILL:	return (-1);
}
