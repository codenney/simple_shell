#include "main.h"

/**
 * shell_loop - Loop of shell
 * @datum: data relevant (av, input, args)
 *
 * Return: no return.
 */
void prompt_loop(data_input *datum)
{
	int loop, i_eof;
	char *input;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "~$ ", 3);
		input = read_line(&i_eof);
		if (i_eof != -1)
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
			loop = split_commands(datum, input);
			datum->count += 1;
			free(input);
		}
		else
		{
			loop = 0;
			free(input);
		}
	}
}
