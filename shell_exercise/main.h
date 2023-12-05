#include <stdlib.h>
#include <stdio.h>
#ifndef MAIN_H
#define MAIN_H

int getLine(char **lineptr, size_t *bufferSize, FILE *stream);
char **strTok(char *str, char *delim);
char **tokenize(char *str, char *delim);
int shellHelper(char **argv);

#endif
