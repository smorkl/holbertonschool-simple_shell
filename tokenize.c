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
        // Manejar el error de asignación de memoria
        fprintf(stderr, "Error: No se pudo tokenizar la entrada\n");
        return NULL; // Continuar con la siguiente iteración del bucle
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