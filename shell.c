#include "shell.h"

/**
 * main - Entry point of the simple shell program.
 *
 * Return: Always returns 0.
 */
int main(void)
{
	char *buffer = NULL;
	size_t size_of_buffer = 0;
	char **args = NULL;

	while (getline(&buffer, &size_of_buffer, stdin) != -1)
	{
		if (_strcmp(buffer, "exit\n") == 0)
		{
			free(buffer);
			return (0);
		}
		if (_strcmp(buffer, "env\n") == 0)
		{
			print_environment();
			continue;
		}
		if (buffer[0] == '\n')
			continue;

		buffer[custom_strcspn(buffer, "\n")] = '\0';

		args = tokenize(buffer);
		execute_command(args);

		free(args);
	}

	free(buffer);
	return (0);
}