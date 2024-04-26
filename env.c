#include <stdio.h>
#include "shell.h"

/**
 * print_environment - Prints the current environment variables.
 */
void print_environment(void)
{
    extern char **environ;
    char **env = environ;

    while (*env != NULL)
    {
        printf("%s\n", *env);
        env++;
    }
}