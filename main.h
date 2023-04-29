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

/**
 * struct replace_var - struct entry
 * Description: single linked list to store variables
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 */
typedef struct replace_var
{
	int len_var;
	char *val;
	int len_val;
	struct replace_var *next;
} rp_var;

/**
 * struct seperators - struct entry
 * Description: a single linked list datatype to store separators
 * @separator: ; | &
 * @next: next node
 */
typedef struct seperators
{
	char separator;
	struct seperators *next;
} sep_list;

/**
 * struct command_lines - struct entry
 * Description: single linked list to store command lines
 * @cmd: command line
 * @next: next node
 */
typedef struct command_lines
{
	char *cmd;
	struct command_lines *next;
} cmd_list;

void execmd(char **argv);
int shell_loop(char **argv);
void initial_data(data_input *datash, char **argv);
char *_strdup(const char *s);
char *_itoa(int n);
void _memcpy(void *dest, const void *src, size_t n);
int _strlen(const char *s);
int _numlen(int n);
char *read_input(int *readline);
char *no_comment(char *buf);
int if_syntax_error(data_input *datum, char *str);
char *replace_vars(char *input, data_input *datum);
int divide_cmds(data_input *datum, char *input);
void *_realloc(void *ptr, unsigned int size, unsigned int new_size);
int first_char(char *input, int *i);
void print_syntax_error(data_input *datum, char *input, int i, int bool);
int error_seperator(char *input, int i, char last_read);
void print_syntax_error(data_input *datum, char *input, int i, int bool);
int repeated_char(char *input, int i);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, const char *src);
int check_vars(rp_var **h, char *input, char *status, data_input *data);


#endif /*MAIN_H*/
