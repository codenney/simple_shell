#include "main.h"

/**
 * main - main entry for the program
 * @argc: The number of arguments supplied to the program
 * @argv: An array of pointers to the arguments.
 * Return: 0 as success
 */
int main(int __attribute__((unused)) argc, char *argv[])
{
	/*int returnLine;*/
	ssize_t user_input;
	char *cmd = NULL;
	char *actual_command = NULL;
	size_t n = 0;
	char *token;
	int Addons_token = 0;
	int i;
	const char *delim = "\n";

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		user_input = getline(&cmd, &n, stdin);
		if (user_input == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			return (-1);
			/*free(cmd);*/
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
	free(cmd);
	free(actual_command);
	return (0);
}
