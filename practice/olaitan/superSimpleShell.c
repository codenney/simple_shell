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

	while (1)
	{
		printf("$ ");
		if (getline(&cmd, &n, stdin) == -1)
			return (-1);
	}

	return (0);
}
