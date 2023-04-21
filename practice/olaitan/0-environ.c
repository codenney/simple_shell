#include <stdio.h>
#include <stdlib.h>

extern char **environ;
int main()
{
	char **evn = environ;
	int i = 0;

	while (evn[i])
	{
		printf("%s\n", evn[i]);
		evn++;
	}
	return (0);
}
