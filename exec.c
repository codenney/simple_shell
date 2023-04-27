#include "main.h"

void execmd(char **argv)
{
    pid_t pid;
    int status;
    char *actual_command = NULL;
    pid = fork();
    if (pid == -1)
    {
        perror("Error: ");
        /*return (-1);*/
    }
    else if ((argv) && (pid == 0))
    {
        actual_command = argv[0];
        if (execve(actual_command, argv, environ) == -1)
        {
            perror("Error: ");
        }
        exit(0);
    }
    else
    {
        wait(&status);
    }
}
