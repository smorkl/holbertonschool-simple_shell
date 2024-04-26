#include <stdio.h>
#include "shell.h"

void print_environment()
{
    extern char **environ;
    char **env = environ;

    while (*env != NULL) 
    {
        printf("%s\n", *env);
        env++;
    }
}
