#include <stdio.h>
#include <stdlib.h>

extern char **environ;
int main()
{
	int i;
	char **evn = environ;

	for (i = 0; environ[i]; i++)
	{
		printf("%s\n", evn[i]);
		return (0);
	}
}
