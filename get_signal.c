#include "main.h"

/**
 * get_sigint - function entry
 * Description: Handle the crtl + c call in prompt
 * @sig: Signal handler
 */
void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n~$ ", 4);
}
