#include "main.h"

/**
 * main - function entry
 * Description: A program that executes the command ls -l /tmp
 * in 5 different child processes
 * Return: 0 as success
*/
int main(void)
{
	int i = 0, status, val;
	char **evn = environ;
	pid_t pid;
	char *argv[] = {"ls", "-l", "/tmp", NULL};

	while (i < 5)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("Error:");
			return (1);
		}
		else if (pid == 0)
		{
			val = execve("/bin/ls", argv, evn);
			if (val == -1)
			{
				perror("Error");
			}
		}
		else
		{
			wait(&status);
			printf("The child %d exited with status %d\n", pid, status);
		}
		i++;
	}
	return (0);
}
