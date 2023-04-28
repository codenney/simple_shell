#include "main.h"

/**
 * main - main entry for the shell program
 * @argc: The number of arguments in the program
 * @argv: An array of pointers of the arguments.
 * Return: 0 as success
 */
int main(int __attribute__((unused)) argc, char **argv)
{
	data_input datum;

	initial_data(&datum, argv);
	/**
	 * prompt_loop(&datum);
	 * free_data(&datum);
	*/

	return (0);
}
