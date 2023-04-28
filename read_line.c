#include "main.h"

/**
 * read_input - function entry
 * Description: a function that reads the input string
 * @readline: a pointer to store the status of getline
 * Return: address of the buffer
 */
char *read_input(int *readline)
{
	char *buf = NULL;
	size_t size = 0;

	*readline = getline(&buf, &size, stdin);

	return (buf);
}
