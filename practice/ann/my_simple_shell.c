#include "main.h"

int main(int __attribute__((unused)) argc, char **argv)
{
    ssize_t user_input;          // variable to hold the return value of getline function to ndle reaching the EOF character  or when user types CTRL + D
    char *user_argu;             // stores the address of the buffer containing the text
    size_t n = 0;                // stores the allocated size in bytes
    char *user_argu_copy = NULL; // variable that holds the copy of the string to be passed to strtok
    const char *delim = "\n";    // delimeter of strtok funct
    int Addons_token = 0;        // token counter
    char *token;                 // stores the token generated by strtok
    int i = 0;
    pid_t pid;
    int status;

    for (;;)
    {
        printf("#cisfun$ ");
        user_input = getline(&user_argu, &n, stdin);
        // checks if the getline function failed or reached EOF
        if (user_input == -1)
        {
            printf("Out of the shell...\n");
            return (-1);
        }
        // allocate space for a copy of the user_argu
        user_argu_copy = malloc(sizeof(char) * user_input);
        if (user_argu_copy == NULL)
        {
            perror("Error: ");
            return (-1);
        }
        // copying user argu to userargucpy
        strcpy(user_argu_copy, user_argu);
        // splitting the string user argu into an arr of words
        token = strtok(user_argu, delim);
        while (token != NULL)
        {
            Addons_token++;
            token = strtok(NULL, delim);
        }
        Addons_token++;
        // allocates space to hold the arr of strings
        argv = malloc(sizeof(char *) * Addons_token);
        // store each token in the argv array
        token = strtok(user_argu_copy, delim);
        for (i = 0; token != NULL; i++)
        {
            argv[i] = malloc(sizeof(char) * strlen(token));
            strcpy(argv[i], token);

            token = strtok(NULL, delim);
        }
        argv[i] = NULL;

        // Execute the command
        pid = fork();
        if (pid == -1)
        {
            perror("Error: ");
            return(1);
        }
        else if ((argv) && (pid == 0))
        {
            user_argu_copy = argv[0];
            if (execve(user_argu_copy, argv,environ) == -1)
            {
                perror("Error: ");
            }
            exit(1);
        }
        else
        {
         wait(&status);
        }

        //    printf("%s\n", user_argu);
    }
    free(user_argu_copy);
    free(user_argu); // frees up allocated memory
    return 0;
}
