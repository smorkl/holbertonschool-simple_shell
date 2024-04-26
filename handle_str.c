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

/**
 * _strcmp - Compares two strings.
 * @str1: The first string to be compared.
 * @str2: The second string to be compared.
 *
 * Return: Negative value if str1 is less than str2,
 *         0 if str1 matches str2,
 *         Positive value if str1 is greater than str2.
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(const unsigned char *)str1 - *(const unsigned char *)str2);
}
