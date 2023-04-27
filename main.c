#include "main.h"
/**
 * main - main entry for the program
 * @argc: The number of arguments supplied to the program
 * @argv: An array of pointers to the arguments.
 * Return: 0 as success
 */
int main(int __attribute__((unused)) argc, char *argv[])
{
	char *cmd = NULL;
	char *actual_command = NULL;
	
	shell_loop(argv);

	free(cmd);
	free(actual_command);
	return (0);
}

