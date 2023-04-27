#include "main.h"

/**
 * read_line - function entry
 * Description: reads the input string
 * @i_eof: return value of getline function
 * Return: input string
 */
char *read_line(int *readLine)
{
	char *input = NULL;
	size_t bufsize = 0;

	*readLine = getline(&input, &bufsize, stdin);

	return (input);
}
