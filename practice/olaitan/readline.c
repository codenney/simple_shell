#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * main - function entry
 * Description: A program that prints "$ ",
 * wait for the user to enter a command,
 * prints it on the next line.
 * Return: 0 on success
 */
int main(void)
{
	size_t n = 10;
	int bufsize;
	char *buf = NULL;

	printf("$ ");
	bufsize = getline(&buf, &n, stdin);
	if (bufsize == -1)
		perror("Error\n");

	printf("%s", buf);
	free(buf);
}
