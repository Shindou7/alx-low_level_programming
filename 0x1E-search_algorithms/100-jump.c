#include "search_algos.h"
#include <math.h>

/**
 * jump_search - perform a jump search ie find square root,
 * jump steps to find match, end linear search
 * @array: given array of ints
 * @size: size of array
 * @value: value to search for
 * Return: index at which value's found
 */
int jump_search(int *array, size_t size, int value)
{
	int idx, jump, step, prev_idx;

	if (array == NULL || size == 0)
		return (-1);

	jump = (int)sqrt((double)size);
	step = 0;
	prev_idx = idx = 0;

	do {
		printf("Value checked array[%d] = [%d]\n", idx, array[idx]);
		if (array[idx] == value)
			return (idx);
		step++;
		prev_idx = idx;
		idx = step * jump;
	} while (idx < (int)size && array[idx] < value);
	printf("Value found between indexes [%d] and [%d]\n", prev_idx, idx);
	for (; prev_idx <= idx && prev_idx < (int)size; prev_idx++)
	{
		printf("Value checked array[%d] = [%d]\n", prev_idx, array[prev_idx]);
		if (array[prev_idx] == value)
			return (prev_idx);
	}
	return (-1);
}
