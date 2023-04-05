#include "main.h"

/**
 * binary_power - recursive function to perform binary search
 * @n: input number
 * @min: minimum value
 * @max: maximum value
 * Return: square root of n or -1 if it doesn't have a natural square root
 */
int binary_power(int n, int min, int max)
{
	if (max < min)
		return (-1);
	int mid = (min + max) / 2;

	if (mid * mid == n)
		return (mid);
	else if (mid * mid < n)
		return (binary_power(n, mid + 1, max));
	else
		return (binary_power(n, min, mid - 1));
}
/**
 * _sqrt_recursion - returns the natural square root of a number.
 * @n: input number.
 * Return: natural square root.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0)
		return (0);
	else if (n == 1)
		return (1);
	else
		return (binary_power(n, 1, n));
}
