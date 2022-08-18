#include <stdlib.h>
#include <stdio.h>
#include "regex.h"

/**
 * regex_match - checks whether a given pattern matches a given string
 *
 * @str: string to scan
 * @pattern: regular expression (RegEx)
 *
 * Return: 1 if the pattern matches the string, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
	int dot = 0, star = 0;

	if (!str || !pattern)
		return (0);

	dot = *str && (*str == *pattern || *pattern == '.');
	star = *(pattern + 1) == '*';

	if (!*str && !star)
		return (*pattern ? 0 : 1);

	else if (dot && star)
		return (regex_match(str + 1, pattern) || regex_match(str, pattern + 2));

	else if (dot && !star)
		return (regex_match(str + 1, pattern + 1));

	else if (star)
		return (regex_match(str, pattern + 2));

	return (0);
}
