#include "main.h"

/**
 * get_error - calls the error according the builtin, syntax or permission
 * @datum: data structure that contains arguments
 * @eval: error value
 * Return: error
 */
int get_error(data_input *datum, int eval)
{
	char *error;

	switch (eval)
	{
	case -1:
		error = error_env(datum);
		break;
	case 126:
		error = error_path_126(datum);
		break;
	case 127:
		error = error_not_found(datum);
		break;
	case 2:
		if (_strcmp("exit", datum->args[0]) == 0)
			error = error_exit_shell(datum);
		else if (_strcmp("cd", datum->args[0]) == 0)
			error = error_get_cd(datum);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}

	datum->status = eval;
	return (eval);
}
