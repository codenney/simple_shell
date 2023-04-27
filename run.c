#include "main.h"

/**
 * run - finds builtins and commands
 *
 * @datum: data relevant (args)
 * Return: 1 on success.
 */
int run(data_input *datum)
{
	int (*builtin)(data_input *datum);

	if (datum->args[0] == NULL)
		return (1);

	builtin = get_builtin(datum->args[0]);

	if (builtin != NULL)
		return (builtin(datum));

	return (cmd_exec(datum));
}
