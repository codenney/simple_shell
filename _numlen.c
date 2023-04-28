#include "main.h"

/**
 * _numlen - function entry
 * Description: calculate the length of a number
 * @n: first argument
 * Return: length of the number
 */
int _numlen(int n)
{
	unsigned int num;
	int length = 1;

	if (n < 0)
	{
		length++;
		num = n * -1;
	}
	else
		num = n;

	while (num > 9)
	{
		length++;
		num = num / 10;
	}

	return (length);
}
