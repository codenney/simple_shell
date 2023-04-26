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
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024    


/**main.c*/
void free_data(shell_data *datastru);
void set_data(shell_data *datastru, char **av);
/**
 * struct data - struct that contains all relevant data on runtime
 * @av: argument vector
 * @input: command line written by user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @_environ: environment variable
 * @pid: Process ID of the shell
*/

typedef struct data
{
    char **av;
    char *input;
    char **args;
    int status;
    int counter;
    char **_environ;
    char *pid;
}shell_data;

/*get_signint.c*/
void get_sigint(int sig);

/*shell.c*/
char *without_comment(char *in);
void loop_in_shell(shell_data *datastru);

/*readline.c*/
char *readLine(int *i_eof);

/*get line function*/
void bringLine(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t getLine(char **lineptr, size_t *n, FILE *stream);

/*check_syntaxError.c*/
int repeated_char(char *input, int i);
int error_sep_op(char *input, int i, char last);
int first_char(char *input, int *i);
void print_syntax_error(data_shell *datastru, char *input, int i, int bool);
int check_syntax_error(data_shell *datastru, char *input);

#endif /* MAIN_H */
