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
    char *buffer_copy;
    char *token;
    int i = 0, num_tokens = 1;
    char *ptr = buffer;
    int j;

    while (*ptr)
    {
        if (*ptr != ' ')
        {
            break;
        }
        ptr++;
    }

    if (*ptr == '\0')
    {
        args = malloc(2 * sizeof(char *));
        if (args == NULL)
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        args[0] = NULL;
        args[1] = NULL;
        return args;
    }

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

    return args;
}
