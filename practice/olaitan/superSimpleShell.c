#include "main.h"

/**
 * main - main entry
 * Description: First version of a super simple shell that can run
 * commands with their full path, without any argument.
 * Return: 0 as success
 */
int main(void)
{
	char *cmd = NULL;
	size_t n = 0;
	pid_t pid;
	char *cmd_cpy = NULL;
	int val, status;

	while (1)
	{
		printf("$ ");
		if (getline(&cmd, &n, stdin) == -1)
			return (-1);
		/* add the null character as the last character in cmd */
		cmd[strcspn(cmd, "\n")] = '\0';

		cmd_cpy = strdup(cmd); /* make a copy of the command */
		if (cmd_cpy == NULL)
			return (1);

		pid = fork(); /* Create a child process */
		if (pid == -1)
		{
			perror("Error:");
			return (1);
		}
		else if (pid == 0)
		{
			char *argv[] = {cmd_cpy, NULL};

			val = execve(cmd_cpy, argv, environ);
			if (val == -1)
				perror("Error");
		}
		else
		{
			wait(&status);
			/* printf("The child %d exited with status %d\n", pid, status); */
		}
	}
	free(cmd), free(cmd_cpy);
	return (0);
}
