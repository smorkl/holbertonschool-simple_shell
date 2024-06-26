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
	int is_terminal = isatty(STDIN_FILENO);

	while (1)
	{
		if (is_terminal)
			printf("#cisfun$ ");
		if (getline(&buffer, &size_of_buffer, stdin) == -1)
            break;
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
		if (args[0] != NULL)
		{
			execute_command(args);
		}
		free(args);
	}

	free(buffer);
	return (0);
}
