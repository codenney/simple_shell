#include "main.h"

/**
 * free_data - frees data structure
 * @datastru: data structure
 * Return: no return
*/
void free_data(shell_data *datastru)
{
unsigned int i;
for (i = 0; datastru->_environ[i]; i++)
{
	free(datastru->_environ[i]);
}
free(datastru->_environ);
free(datastru->pid);
}
/**
 * set_data  - initialize data structure
 * @datastru: data structure
 * @av: argument vector
 * Return: no return
*/
void set_data(shell_data *datastru, char **av)
{
unsigned int i;
datastru->av = av;
datastru->input = NULL;
datastru->args = NULL;
datastru->status = 0;
datastru->counter = 1;

for (i = 0; environ[i]; i++)
;
datastru->_environ = malloc(sizeof(char *) * (i + 1));
for (i = 0; environ[i]; i++)
{
datastru->_environ[i] = _strdup(environ[i]);
}
datastru->_environ[i] = NULL;
datastru->pid = aux_itoa(getpid());
}
/**
 * main - The entry point
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success
*/
int main(int ac, char **av)
{
	shell_data datastru;
	(void) ac;
	signal(SIGINT, get_sigint);
	set_data(&datastru, av);
	loop_in_shell(&datastru);
	free_data(&datastru);
	if (datastru.status < 0)
	    return (255);
	return (datastru.status);
}