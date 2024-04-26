#include "shell.h"
#include <stddef.h>

/**
 * custom_strcspn - calculates the length of the initial segment of str which
 *                  consists entirely of characters not in reject.
 * @str: string to be scanned
 * @reject: string containing the characters to match
 *
 * Return: the length of the initial segment of str which does not contain
 *         any character from reject
 */
size_t custom_strcspn(const char *str, const char *reject)
{
	size_t i, j;

	for (i = 0; str[i] != '\0'; ++i)
	{
		for (j = 0; reject[j] != '\0'; ++j)
		{
			if (str[i] == reject[j])
			{
				return (i);
			}
		}
	}

	return (i);
}
