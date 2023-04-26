#include "main.h"
/**
 * without_comment - removes comments from the input
 * @in: string input
 * Return: input without comments
*/
char *without_comment(char *in)
{
    int i, upTo;
    upTo = 0;
    for (i = 0; in[i]; i++)
    {
        if (in[i] == '#')
        {
            if (i == 0)
            {
                free(in);
                return(NULL);
            }
            if (in[i - 1] == ' ' || in[i -1] == '\t' || in[i - 1] == ';')
            upTo = i;
        }
    }
    if (upTo != 0)
    {
        in = _realloc(in, i, upTo + 1);
        in[upTo] = '\0';
    }
    return (in);
}
/**
 * loop_in_shell - shell loop
 * @datastru: data relevant (av, input, args)
 * Return: no return
*/
void loop_in_shell(shell_data *datastru)
{
    int loop, i_eof;
    char *user_input;

    loop = 1;
    while (loop == 1)
    {
        write(STDIN_FILENO, "$ ", 4);
        user_input = readLine(&i_eof);
        if (i_eof != -1)
        {
            user_input = without_comment(user_input);
            if (user_input == NULL)
            continue;

         if (check_syntaxError(datastru, user_input) == 1)
         {
            datastru->status = 2;
            free(user_input);
            continue;
         }
         user_input = rep_var(user_input, datastru);
         loop = split_commands(datastru, user_input);
         datastru->counter += 1;
         free(user_input);
        }
        else
        {
            loop = 0;
            free(user_input);
        }
    }
}