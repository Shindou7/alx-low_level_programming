#include "main.h"

/**
 * _strlen_recursion - returns the length of a string.
 * @s: string
 * Return: the length of a string.
 */
int _strlen_recursion(char *s)
{
	if (!*s)
		return (0);
	return (1 + _strlen_recursion(s + 1));
}
/**
 * comparator1 - recursively checks if string is a palindrome
 * @s: pointer to the string
 * @left: leftmost index of the string to be compared
 * @right: rightmost index of the string to be compared
 * Return: 1 if the string is palindrome, 0 otherwise
 */
int comparator1(char *s, int left, int right)
{
    if (left >= right)
        return 1;

    if (s[left] == s[right])
        return comparator1(s, left + 1, right - 1);

    return 0;
}


/**
 * is_palindrome - detects if a string is a palindrome.
 * @s: input string.
 * Return:  that returns 1 if a string is a palindro
 */
int is_palindrome(char *s)
{
    int len = _strlen_recursion(s);
    for (int i = 0; i < len / 2; i++) {
        if (*(s + i) != *(s + len - 1 - i)) {
            return 0;
        }
    }
    return 1;
}
