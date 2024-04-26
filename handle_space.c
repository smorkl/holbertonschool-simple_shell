#include <stdlib.h>
#include <stdio.h>
#include "shell.h"

/**
 * initialize_args - Initializes an array of strings for command arguments.
 *
 * Return: An array of strings initialized with two NULL elements.
 */
char **initialize_args()
{
	char **args = malloc(2 * sizeof(char *));

	if (args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	args[0] = NULL;
	args[1] = NULL;

	return (args);
}
