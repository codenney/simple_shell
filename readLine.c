#include "main.h"

/**
 * readLine - reads the string input
 * @i_eof: return value of getline function
 * Return: string input
*/
char *readLine(int *i_eof)
{
    char *user_input = NULL;
    size_t bufsize = 0;

    *i_eof = getline(&user_input, &bufsize, stdin);
    return (user_input);
}