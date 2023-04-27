#include "main.h"

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
