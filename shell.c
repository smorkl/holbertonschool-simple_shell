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
    char *args[] = {NULL, NULL};
    pid_t pid;

    while (getline(&buffer, &size_of_buffer, stdin) != -1)
    {
        if (buffer[0] == '\n')
            continue;
        
        buffer[custom_strcspn(buffer, "\n")] = '\0';
        args[0] = buffer;

        pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            execve(args[0], args, NULL);
            perror("./shell");
            exit(EXIT_FAILURE);
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
    }

    free(buffer);
    return 0;
}
