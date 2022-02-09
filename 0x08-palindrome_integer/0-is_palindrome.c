#include "palindrome.h"

/**
 * is_palindrome - check if integer is a palindrome
 *
 * @n: integer to check
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	unsigned long temp_num = n;
	unsigned long rev_num = 0, digit = 0;

	while (temp_num > 0)
	{
		digit = temp_num % 10;
		rev_num = (rev_num * 10) + digit;
		temp_num /= 10;
	}

	if (rev_num == n)
		return (1);

	return (0);
}
