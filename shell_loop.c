#include "main.h"

/**
 * shell_loop - function entry
 * Description: function for shell loop
 * @argv: argument vector
 * Return: 0
 */
int shell_loop(char **argv)
{
	ssize_t user_input;
	char *actual_command = NULL, *cmd = NULL, *token, *delim = "\n";
	size_t n = 0;
	int Addons_token = 0, i;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		user_input = getline(&cmd, &n, stdin);
		if (user_input == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			return (-1);
		}
		actual_command = malloc(sizeof(char) * user_input);
		if (actual_command == NULL)
		{
			perror("Error: ");
			return (-1);
		}
		strcpy(actual_command, cmd);
		token = strtok(cmd, delim);
		while (token != NULL)
		{
			Addons_token++;
			token = strtok(NULL, delim);
		}
		Addons_token++;
		argv = malloc(sizeof(char *) * Addons_token);
		token = strtok(actual_command, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		execmd(argv);
	}
	free(actual_command);
}
