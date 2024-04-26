#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

char** tokenize(char* buffer);
size_t custom_strcspn(const char *str, const char *reject);
void print_environment();
void execute_command(char **args);
char **initialize_args();

#endif