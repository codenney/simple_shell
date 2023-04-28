#include "main.h"

/**
 * initial_data - function entry
 * Description: initialize the data structure
 * @datum: data structure
 * @argv: argument vector
 * Return: void
 */
void initial_data(data_input *datum, char **argv)
{
	unsigned int i;

	datum->argv = argv;
	datum->input = NULL;
	datum->args = NULL;
	datum->status = 0;
	datum->count = 1;

	while (environ[i])
		i++;

	datum->_environ = malloc(sizeof(char *) * (i + 1));

	i = 0;
	while (environ[i])
		datum->_environ[i] = _strdup(environ[i]);

	datum->_environ[i] = NULL;
	datum->pid = _itoa(getpid());

}
