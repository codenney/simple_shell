#include "main.h"

/**
 * _strdup - function entry
 * Description: duplicate of the string pointed to by s
 * @s: pointer to the string
 * Return: a pointer to the duplicated string s
 */
char *_strdup(const char *s)
{
	char *newS;
	size_t len;

	len = _strlen(s);
	newS = malloc(sizeof(char) * (len + 1));

	if (newS == NULL)
		return (NULL);

	_memcpy(newS, s, len + 1);

	return (newS);
}
