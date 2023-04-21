#include <stdio.h>

// prints the env't
// Return always 0

int main(int ac, char **av, char **env)
{
    unsigned int i;
    i = 0;
    // for(i = 0; env[i] != NULL; i++)
    while (env[i] != NULL)
    {
        printf("%s\n", env[i]);
        i++;
    }

    return (0);
}