#include <stdlib.h>
#include <stdio.h>
#include "shell.h"

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
    return args;
}