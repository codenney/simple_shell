#include "main.h"

/**
 * prompt_loop - function entry
 * Description: a function that keep accepting input and perform actions
 * @datum: prefilled data based on user inputs and arguments
 * Return: see nothing!
 */
void prompt_loop(data_input *datum)
{
	int to_continue, status;
	char *buf;

	to_continue = 1;
	while (to_continue)
	{
		write(STDIN_FILENO, "~$ ", 3);
		buf = read_input(&status);
		if (status != -1)
		{
			buf = no_comment(buf);
			if (buf == NULL)
				continue;

			if (if_syntax_error(datum, buf) == 1)
			{
				datum->status = 2;
				free(buf);
				continue;
			}
			buf = replace_vars(buf, datum);
			to_continue = divide_cmds(datum, buf);
			datum->count += 1;
			free(buf);
		}
		else
		{
			to_continue = 0;
			free(buf);
		}
	}
}
