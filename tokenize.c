#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "shell.h"

/**
 * tokenize - Tokenizes a string into an array of tokens.
 * @buffer: The string to tokenize.
 *
 * Return: An array of tokens.
 */
char **tokenize(char *buffer)
{
	char **args;
	char *buffer_copy = strdup(buffer);
	char *token = NULL;
	int i = 0, num_tokens = 1;
	char *ptr = buffer;

	while (*ptr)
	{
		if (*ptr == ' ')
			num_tokens++;
		ptr++;
	}

	args = malloc((num_tokens + 1) * sizeof(char *));
	if (args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(buffer_copy, " ");
	if (token == NULL)
		args[i++] = strdup("");
	else
		args[i++] = strdup(token);

	while (token != NULL)
	{
		token = strtok(NULL, " ");
		if (token != NULL)
			args[i++] = strdup(token);
	}

	args[i] = NULL;
	for (int j = 0; j < i; j++)
		free(args[j]);

	free(buffer_copy);

	return args;
}