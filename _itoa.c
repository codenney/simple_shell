#include "main.h"

/**
 * _itoa - function entry
 * Description: A function that converts int into a string
 * @n: number to convert
 * Return: string pointer
 */
char *_itoa(int n)
{
	unsigned int num;
	int length = _numlen(n);
	char *buf;

	buf = malloc(sizeof(char) * (length + 1));
	if (buf == 0)
		return (NULL);

	*(buf + length) = '\0';

	if (n < 0)
	{
		num = n * -1;
		buf[0] = '-';
	}
	else
		num = n;

	length--;

	do {
		*(buf + length) = (num % 10) + '0';
		num = num / 10;
		length--;
	} while (num > 0);

	return (buf);
}
