#include <stdio.h>

char **environ;
int main(int ac, char **av, char **env)
{
    int i;
    printf("Address of env is: %p\n", &env);
    printf("Address of environ is: %p\n", &environ);
}