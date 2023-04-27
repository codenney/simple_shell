#include "main.h"

/**
 * len_num - function entry
 * Description: Get the length of a number
 * @n: first argument
 * Return: number length
 */
int len_num(int n)
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
