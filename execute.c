#include "shell.h"

/**
 * execute_command - Executes a command with the given arguments.
 * @args: Array of strings containing the command and its arguments.
 */
void execute_command(char **args)
{
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        if (args[0] == NULL)
        {
            exit(EXIT_SUCCESS);
        }
        else
        {
            execve(args[0], args, NULL);
            perror("./shell");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        int status;
        waitpid(pid, &status, 0);
    }
}
