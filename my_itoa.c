#include "main.h"

/**
 * my_itoa - function entry
 * Description: A function that converts int into a string
 * @n: number to convert
 * Return: string of n
 */
char *my_itoa(int n)
{
	unsigned int num;
	int length = len_num(n);
	char *buffer;

	buffer = malloc(sizeof(char) * (length + 1));
	if (buffer == 0)
		return (NULL);

	*(buffer + length) = '\0';

	if (n < 0)
	{
		num = n * -1;
		buffer[0] = '-';
	}
	else
	{
		num = n;
	}

	length--;
	do {
		*(buffer + length) = (num % 10) + '0';
		num = num / 10;
		length--;
	} while (num > 0);

	return (buffer);
}
