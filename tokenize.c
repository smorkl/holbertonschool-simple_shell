#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "shell.h"

char** tokenize(char* buffer)
{
    char** args = (char**)malloc(100 * sizeof(char*));
    char* buffer_copy = strdup(buffer);
    char* token = NULL;
    int i = 0;
    
    if (args == NULL || buffer_copy == NULL)
    {
        perror("malloc or strdup");
        exit(EXIT_FAILURE);
    }

    token = strtok(buffer_copy, " ");
    if (token == NULL) {
        args[i++] = strdup("");
    } else {
        args[i++] = strdup(token); 
    }

    while (token != NULL)
    {
        token = strtok(NULL, " ");
        if (token != NULL) {
            args[i++] = strdup(token);
        }
    }

    args[i] = NULL;

    free(buffer_copy);

    return args;
}
