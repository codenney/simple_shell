#include "main.h"

/**
 * _strlen - function entry
 * Description: to find the length of a string
 * @s: the pointer to the string
 * Return: length of the string
 */
int _strlen(const char *s)
{
	int len = 0;

	while (s[len] != 0)
		len++;

	return (len);
}
