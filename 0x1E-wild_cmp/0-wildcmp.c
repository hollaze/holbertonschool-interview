#include "holberton.h"

/**
 * wildcmp - Compare two strings and check if they can
 * be considered identical using the wildcard *
 *
 * @s1: Pointer to char
 * @s2: Pointer to char
 *
 * Return: 1 if string can be considered identical 0 otherwise
 */

int wildcmp(char *s1, char *s2)
{
	if (*s2 == '\0' && *s1 == '\0')
		return (1);

	if (*s2 == *s1)
		return (wildcmp(s1 + 1, s2 + 1));

	if (*s2 == '*')
	{
		if (*(s2 + 1) == '*')
			return (wildcmp(s1, s2 + 1));

		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
	}

	return (0);
}
