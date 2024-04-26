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
	char *ptr;
	char *token = NULL;
	int i = 0, num_tokens = 1, j;

	while (*buffer && *buffer == ' ')
		buffer++;

	if (*buffer == '\0')
	{
		args = initialize_args();
		return (args);
	}

	for (ptr = buffer; *ptr; ptr++)
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

	for (j = 0; j < i; j++)
		free(args[j]);

	free(buffer_copy);

	return (args);
}
