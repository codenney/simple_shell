#ifndef MAIN_H
#define MAIN_H

extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

/**
 * struct data - contains all relevant data from the runtime
 * @argv: arguments count
 * @input: user input
 * @args: tokens of the command line
 * @status: last status of the shell command
 * @count: counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */
typedef struct data
{
	char **argv;
	char *input;
	char **args;
	int status;
	int count;
	char **_environ;
	char *pid;
} data_input;

void execmd(char **argv);
int shell_loop(char **argv);
void initial_data(data_input *datash, char **argv);
char *_strdup(const char *s);
char *_itoa(int n);
void _memcpy(void *dest, const void *src, size_t n);
int _strlen(const char *s);
int _numlen(int n);

#endif /*MAIN_H*/
