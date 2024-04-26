#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "shell.h"

char** tokenize(char* buffer)
{
    char** args = (char**)malloc(100 * sizeof(char*));
    char* token = NULL;
    int i;
    
    if (args == NULL)
    {
        fprintf(stderr, "Error: No se pudo tokenizar la entrada\n");
        return NULL; 
    }

    token = strtok(buffer, " ");

    while (token != NULL)
    {
        args[i++] = token;
        token = strtok(NULL, " ");
    }

    args[i] = NULL;
    return args;
}