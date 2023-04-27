#include "main.h"

/**
 * cmp_env_name - compares env variables names
 * with the name passed.
 * @nenv: name of the environment variable
 * @name: name passed
 *
 * Return: 0 if are not equal. Another value if they are.
 */
int cmp_env_name(const char *nenv, const char *name)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * _getenv - get an environment variable
 * @name: name of the environment variable
 * @_environ: environment variable
 *
 * Return: value of the environment variable if is found.
 * In other case, returns NULL.
 */
char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int i, mov;

	/* Initialize ptr_env value */
	ptr_env = NULL;
	mov = 0;
	/* Compare all environment variables */
	/* environ is declared in the header file */
	for (i = 0; _environ[i]; i++)
	{
		/* If name and env are equal */
		mov = cmp_env_name(_environ[i], name);
		if (mov)
		{
			ptr_env = _environ[i];
			break;
		}
	}

	return (ptr_env + mov);
}

/**
 * _env - prints the evironment variables
 *
 * @datum: data relevant.
 * Return: 1 on success.
 */
int _env(data_input *datum)
{
	int i, j;

	for (i = 0; datum->_environ[i]; i++)
	{

		for (j = 0; datum->_environ[i][j]; j++)
			;

		write(STDOUT_FILENO, datum->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datum->status = 0;

	return (1);
}

/**
 * copy_info - copies info to create
 * a new env or alias
 * @name: name (env or alias)
 * @value: value (env or alias)
 *
 * Return: new env or alias.
 */
char *copy_info(char *name, char *value)
{
	char *new;
	int len_name, len_value, len;

	len_name = _strlen(name);
	len_value = _strlen(value);
	len = len_name + len_value + 2;
	new = malloc(sizeof(char) * (len));
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);
	_strcat(new, "\0");

	return (new);
}

/**
 * set_env - sets an environment variable
 *
 * @name: name of the environment variable
 * @value: value of the environment variable
 * @datum: data structure (environ)
 * Return: no return
 */
void set_env(char *name, char *value, data_input *datum)
{
	int i;
	char *var_env, *name_env;

	for (i = 0; datum->_environ[i]; i++)
	{
		var_env = _strdup(datum->_environ[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, name) == 0)
		{
			free(datum->_environ[i]);
			datum->_environ[i] = copy_info(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	datum->_environ = _reallocdp(datum->_environ, i, sizeof(char *) * (i + 2));
	datum->_environ[i] = copy_info(name, value);
	datum->_environ[i + 1] = NULL;
}


/**
 * _setenv - compares env variables names
 * with the name passed.
 * @datum: data relevant (env name and env value)
 *
 * Return: 1 on success.
 */
int _setenv(data_input *datum)
{

	/**
     * if (datum->args[1] == NULL || datum->args[2] == NULL)
	{
		get_error(datum, -1);
		return (1);
	}
    */

	set_env(datum->args[1], datum->args[2], datum);

	return (1);
}

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
 * @datash: data relevant (status and args)
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

/**
 * _reallocdp - reallocates a memory block of a double pointer.
 * @ptr: double pointer to the memory previously allocated.
 * @old_size: size, in bytes, of the allocated space of ptr.
 * @new_size: new size, in bytes, of the new memory block.
 *
 * Return: ptr.
 * if new_size == old_size, returns ptr without changes.
 * if malloc fails, returns NULL.
 */
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newptr;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(sizeof(char *) * new_size);
	if (newptr == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		newptr[i] = ptr[i];

	free(ptr);

	return (newptr);
}
