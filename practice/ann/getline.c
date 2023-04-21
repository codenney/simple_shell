#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *out_put;
    size_t nbytes = 100;
    int get_output;

    printf("$ ");
    out_put = (char *)malloc(nbytes);
    get_output = getline(&out_put, &nbytes, stdin);
    if (get_output == -1)
    {
        printf("error");
    }
    else
    {
        printf("%s", out_put);
    }
    free(out_put); // deallocating memory
    return (0);
}