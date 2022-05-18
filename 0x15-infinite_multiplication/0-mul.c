#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _puts - prints a string
 *
 * @str: string to print
 */

void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	_putchar('\n');
}

/**
 * error_message - print an error message and exit 98 status
 *
 * @s: error message to print
 */
void error_message(char *s)
{
	_puts(s);
	exit(98);
}

/**
 * is_digit - check if the string s is a number
 *
 * @s: string to check
 *
 * Return: 0 if the string s is a number, 1 otherwise
 */
int is_digit(char *s)
{
	int i, digit = 0;

	for (i = 0; s[i] && !digit; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			digit++;
	}
	return (digit);
}

/**
 * operations - multiplies, adds and stores the result in a string
 *
 * @num1: first number
 * @num2: second number
 * @len1: length of num1
 * @len2: length of num2
 *
 * Return: result of multiplies
 */
char *operations(char *num1, char *num2, int len1, int len2)
{
	char *result = NULL;
	int i, j, number, total_len = (len1 + len2);

	result = malloc(sizeof(char) * total_len);

	if (!result)
		error_message("Error");

	for (i = 0; i < total_len; i++)
		result[i] = '0';

	for (i = len1 - 1; i >= 0; i--)
	{
		number = 0;

		for (j = len2 - 1; j >= 0; j--)
		{
			number += (num1[i] - '0') * (num2[j] - '0');
			number += result[i + j + 1] - '0';

			result[i + j + 1] = (number % 10) + '0';
			number /= 10;
		}

		if (number)
			result[i + j + 1] = (number % 10) + '0';
	}

	return (result);
}

/**
 * main - multiplies two positive numbers
 *
 * @argv: arguments value (num1, num2)
 * @argc: arguments count
 *
 * Return: 0 if success otherwise exit error 98
 */
int main(int argc, char **argv)
{
	int len1 = 0, len2 = 0;
	char *num1 = argv[1], *num2 = argv[2], *result = NULL;

	if (argc != 3 || is_digit(num1) || is_digit(num2))
		error_message("Error");

	if (argv[1][0] == 48 || argv[2][0] == 48)
		_puts("0"), exit(0);

	while (num1[len1])
		len1++;

	while (num2[len2])
		len2++;

	result = operations(num1, num2, len1, len2);

	if (result[0] == '0')
		_puts(result + 1);

	else
		_puts(result);

	free(result);

	return (0);
}
