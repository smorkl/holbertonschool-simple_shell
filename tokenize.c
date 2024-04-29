#include "shell.h"

/**
 * tokenize - Tokenizes a string into an array of tokens.
 * @buffer: The string to tokenize.
 * Return: An array of tokens.
 */
char **tokenize(char *buffer)
{
    char **args = NULL;
    char *buffer_copy = NULL, *token = NULL;
    char *delimiters = " \t\n";
    int i = 0, num_tokens = 0, j;
    char *ptr;

    for (ptr = buffer; *ptr; ptr++) {
        if (!strchr(delimiters, *ptr) && (*(ptr + 1) == '\0' || strchr(delimiters, *(ptr + 1)))) {
            num_tokens++;
        }
    }

    args = malloc((num_tokens + 1) * sizeof(char *));
    if (args == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    buffer_copy = strdup(buffer);
    if (buffer_copy == NULL) {
        perror("strdup");
        exit(EXIT_FAILURE);
    }
    token = strtok(buffer_copy, delimiters);
    while (token != NULL) {
        args[i] = strdup(token);
        if (args[i] == NULL) {
            perror("strdup");
            for (i = 0; i < num_tokens; i++) {
                free(args[i]);
            }
            free(args);
            exit(EXIT_FAILURE);
        }
        i++;
        token = strtok(NULL, delimiters);
    }

    args[i] = NULL;

    free(buffer_copy);

	for (j = 0; j < i; j++)
		free(args[j]);

    return args;
}

