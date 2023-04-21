#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    char *argv[5];
    argv[0] = "/bin/ls";
    argv[1] = "-l";
    argv[2] = "/tmp";
    argv[3] = NULL;

    char *envp[] = {NULL};

    pid_t child_pid;
    pid_t my_pid;
    int status;

    //    ppid = fork();
    child_pid = fork();
    child_pid = fork();

    if (my_pid == 0)
    {
        my_pid = getpid();
        printf("Father is %u\n: ", my_pid);
        execve(argv[0], argv, NULL);
        perror("Error: ");
        exit(1);
    }
    while (wait(&status) != my_pid)
        ;
}