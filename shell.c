#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "shell.h"

int main()
{
    char *buffer = NULL;
    size_t size_of_buffer = 0;
    char **args = NULL;
    pid_t pid;

    while (getline(&buffer, &size_of_buffer, stdin) != -1)
    {
        if (strcmp(buffer, "exit \n") == 0)
        {
            free(buffer);
            return 0;
        }
        if (strcmp(buffer, "env\n") == 0)
        {
            print_environment();
            continue;
        }
        if (buffer[0] == '\n')
            continue;
        
        buffer[custom_strcspn(buffer, "\n")] = '\0';
        
        args = tokenize(buffer);

        pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            if (args[0] == NULL) {
            exit(EXIT_SUCCESS);
            }else {
            execve(args[0], args, NULL);
            perror("./shell");
            exit(EXIT_FAILURE);
            }
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
        free(args);
    }

    free(buffer);
    return 0;
}