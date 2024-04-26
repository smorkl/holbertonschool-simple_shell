#include <stdio.h>
#include "shell.h"

void print_environment()
{
    extern char **environ;  // Variable global que contiene las variables de entorno
    char **env = environ;   // Puntero para recorrer las variables de entorno

    while (*env != NULL) 
    {
        printf("%s\n", *env);
        env++;
    }
}
