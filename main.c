#include "main.h"

/**
 * main - main entry for the program
 * @argc: The number of arguments supplied to the program
 * @argv: An array of pointers to the arguments.
 * Return: 0 as success
 */
int main(int __attribute__((unused)) argc, char **argv)
{
	data_input datum;
	char *input;
	int readLine, to_continue = 1;

	signal(SIGINT, get_sigint);
	initial_data(&datum, argv);
	prompt_loop(&datum);
	free_data(&datum);

	return (0);
}
