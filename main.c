#include "main.h"

/**
 * main - main entry for the program
 * @argc: The number of arguments supplied to the program
 * @argv: An array of pointers to the arguments.
 * Return: 0 as success
 */
int main(int argc, char *argv[])
{
	int returnLine;
	char *cmd = NULL;
	size_t n = 0;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		returnLine = getline(&cmd, &n, stdin);
		if (returnLine == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			free(cmd);
		}
	}
	free(cmd);
	return (0);
}
