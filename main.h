#ifndef MAIN_H
#define MAIN_H

extern char **environ;

#define BUFSIZE
#define TOKEN_BUFSIZE 128
#define TOKEN_DELIM " \t\r\n\a"

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
#include <limits.h>
#include <linux/limits.h>


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

/**
 * struct builtin_s - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(data_input *datash);
} builtin_t;

void get_sigint(int sig);
int len_num(int n);
void prompt_loop(data_input *datum);
char *my_itoa(int n);
char *_strdup(const char *s);
char *read_line(int *readLine);
void free_data(data_input *datum);
void initial_data(data_input *datash, char **argv);
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
void free_rvar_list(r_var **head);
r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval);
char *swap_char(char *input, int bool);
void add_nodes(sep_list **head_s, line_list **head_l, char *input);
void go_next(sep_list **list_s, line_list **list_l, data_input *datum);
int split_commands(data_input *datum, char *input);
char **split_line(char *input);
sep_list *add_sep_node_end(sep_list **head, char sep);
void free_sep_list(sep_list **head);
line_list *add_line_node_end(line_list **head, char *line);
void free_line_list(line_list **head);
char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);
int run(data_input *datum);
int (*get_builtin(char *cmd))(data_input *);
int cmp_env_name(const char *nenv, const char *name);
char *_getenv(const char *name, char **_environ);
int _env(data_input *datum);
char *copy_info(char *name, char *value);
void set_env(char *name, char *value, data_input *datum);
int _setenv(data_input *datum);
int _unsetenv(data_input *datum);
int cd_shell(data_input *datum);
int exit_shell(data_input *datum);
int get_help(data_input *datash);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);
void cd_dot(data_input *datash);
void cd_to(data_input *datash);
void cd_previous(data_input *datash);
void cd_to_home(data_input *datash);
void rev_string(char *s);
int is_cdir(char *path, int *i);
char *_which(char *cmd, char **_environ);
int is_executable(data_input *datash);
int check_error_cmd(char *dir, data_input *datash);
int cmd_exec(data_input *datash);
int get_error(data_input *datum, int eval);



#endif /* MAIN_H */
