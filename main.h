#ifndef MAIN_H
#define MAIN_H

extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

#define BUFSIZE 1024    

/*get line function*/
void bringLine(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t getLine(char **lineptr, size_t *n, FILE *stream);
#endif /* MAIN_H */
