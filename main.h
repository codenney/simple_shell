#ifndef MAIN_H
#define MAIN_H

extern char **environ;

#define BUFSIZE 1024

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <wait.h>
#include <errno.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>


/**
 * struct data - contains all relevant data on the runtime
 * @av: arguments count
 * @input: command line entered by the user
 * @args: tokens of the command line
 * @status: last status of the shell command
 * @count: lines counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int count;
	char **_environ;
	char *pid;
} data_input;

/**
 * struct r_var_list - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;

/**
 * struct sep_list_s - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

int len_num(int n);
char *my_itoa(int n);
char *_strdup(const char *s);
char *read_line(int *readLine);
char *without_comment(char *in);
int check_syntax_error(data_input *datum, char *input);
char *rep_var(char *input, data_input *datash);
int split_commands(data_input *datash, char *input);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strlen(const char *s);
void _memcpy(void *newptr, const void *ptr, unsigned int size);
int repeated_char(char *input, int i);
int error_sep_op(char *input, int i, char last);
int first_char(char *input, int *i);
void print_syntax_error(data_input *datash, char *input, int i, int bool);
int check_syntax_error(data_input *datash, char *input);
int _atoi(char *s);
void check_env(r_var **h, char *in, data_input *data);
int check_vars(r_var **h, char *in, char *st, data_input *data);
char *replaced_input(r_var **head, char *input, char *new_input, int nlen);
char *rep_var(char *input, data_input *datash);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);




#endif /* MAIN_H */
