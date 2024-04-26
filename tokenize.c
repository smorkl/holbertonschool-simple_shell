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
	char **args = NULL;
	char *buffer_copy = NULL;
	char *token = NULL;
	int i = 0, num_tokens = 1;

	while (*buffer && *buffer == ' ')
		buffer++;

	if (*buffer == '\0')
	{
		args = initialize_args();
		return (args);
	}
	for (char *ptr = buffer; *ptr; ptr++)
		num_tokens += (*ptr == ' ');

	args = malloc((num_tokens + 1) * sizeof(char *));
	if (args == NULL)
	{
		exit(EXIT_FAILURE);
	}
	buffer_copy = strdup(buffer);
	if (buffer_copy == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}

	token = strtok(buffer_copy, " ");
	while (token != NULL)
	{
		args[i++] = strdup(token);
		token = strtok(NULL, " ");
	}
	
    args[i] = NULL;
	
    for (int j = 0; j < i; j++)
		free(args[j]);

	free(buffer_copy);

	return (args);
}