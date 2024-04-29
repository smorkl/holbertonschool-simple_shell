#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

extern char **environ;

/**
 * print_environment - Prints the current environment variables.
 */
void print_environment()
{
    char **env = environ;
    
	while (*env != NULL)
	{
        printf("%s\n", *env);
        env++;
    }
}
