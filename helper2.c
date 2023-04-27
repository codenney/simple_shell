#include "main.h"

/**
 * _unsetenv - deletes a environment variable
 *
 * @datum: data relevant (env name)
 *
 * Return: 1 on success.
 */
int _unsetenv(data_input *datum)
{
	char **realloc_environ;
	char *var_env, *name_env;
	int i, j, k;

	if (datum->args[1] == NULL)
	{
		/* get_error(datum, -1); */
		return (1);
	}
	k = -1;
	for (i = 0; datum->_environ[i]; i++)
	{
		var_env = _strdup(datum->_environ[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, datum->args[1]) == 0)
		{
			k = i;
		}
		free(var_env);
	}
	if (k == -1)
	{
		/* get_error(datum, -1); */
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (i));
	for (i = j = 0; datum->_environ[i]; i++)
	{
		if (i != k)
		{
			realloc_environ[j] = datum->_environ[i];
			j++;
		}
	}
	realloc_environ[j] = NULL;
	free(datum->_environ[k]);
	free(datum->_environ);
	datum->_environ = realloc_environ;
	return (1);
}

/**
 * cd_shell - changes current directory
 *
 * @datum: data relevant
 * Return: 1 on success
 */
int cd_shell(data_input *datum)
{
	char *dir;
	int ishome, ishome2, isddash;

	dir = datum->args[1];

	if (dir != NULL)
	{
		ishome = _strcmp("$HOME", dir);
		ishome2 = _strcmp("~", dir);
		isddash = _strcmp("--", dir);
	}

	if (dir == NULL || !ishome || !ishome2 || !isddash)
	{
		cd_to_home(datum);
		return (1);
	}

	if (_strcmp("-", dir) == 0)
	{
		cd_previous(datum);
		return (1);
	}

	if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
	{
		cd_dot(datum);
		return (1);
	}

	cd_to(datum);

	return (1);
}

/**
 * exit_shell - exits the shell
 *
 * @datum: data relevant (status and args)
 * Return: 0 on success.
 */
int exit_shell(data_input *datum)
{
	unsigned int ustatus;
	int is_digit;
	int str_len;
	int big_number;

	if (datum->args[1] != NULL)
	{
		ustatus = _atoi(datum->args[1]);
		is_digit = _isdigit(datum->args[1]);
		str_len = _strlen(datum->args[1]);
		big_number = ustatus > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || big_number)
		{
			/* get_error(datum, 2); */
			datum->status = 2;
			return (1);
		}
		datum->status = (ustatus % 256);
	}
	return (0);
}
