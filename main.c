#include "main.h"

/**
 * main - main entry for the program
 * @argc: The number of arguments supplied to the program
 * @argv: An array of pointers to the arguments.
 * Return: 0 as success
 */
int main(int __attribute__((unused)) argc, char **argv)
{
	data_input *datum;
	int i, sig, readLine, to_continue = 1;
	char *input;

	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 4);

	datum->av = argv;
	datum->input = NULL;
	datum->args = NULL;
	datum->status = 0;
	datum->count = 1;

	for (i = 0; environ[i]; i++)
		;

	datum->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		datum->_environ[i] = _strdup(environ[i]);
	}
	datum->_environ[i] = NULL;
	datum->pid = my_itoa(getpid());

	while (to_continue)
	{
		write(STDIN_FILENO, "$ ", 3);
		input = read_line(&readLine);

		if (readLine != -1)
		{
			input = without_comment(input);
			if (input == NULL)
				continue;

			if (check_syntax_error(datum, input) == 1)
			{
				datum->status = 2;
				free(input);
				continue;
			}
			input = rep_var(input, datum);
			to_continue = split_commands(datum, input);
			datum->count += 1;
			free(input);
		}
		else
		{
			to_continue = 0;
			free(input);
		}
	}

	return (0);
}

