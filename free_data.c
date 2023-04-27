#include "main.h"

/**
 * free_data - function entry
 * Description: frees data structure
 * @datum: data structure
 * Return: no return
 */
void free_data(data_input *datum)
{
	unsigned int i;

	for (i = 0; datum->_environ[i]; i++)
	{
		free(datum->_environ[i]);
	}

	free(datum->_environ);
	free(datum->pid);
}
