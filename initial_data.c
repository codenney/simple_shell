#include "main.h"

/**
 * initial_data - function entry
 * Description: Initialize data structure
 * @datum: data structure
 * @argv: argument vector
 * Return: void
 */
void initial_data(data_input *datum, char **argv)
{
	unsigned int i;

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

}
