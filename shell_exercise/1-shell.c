#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * main: simple shell that runs commands without any argument and
 * with their full path
 * 
 * Return: always returns 0
 */

int main(void)
{
	size_t bufferSize = 1024;
	char *lineptr = NULL;
	char delim[] = " ";
	char **command;
	
	printf("$ ");
	while(getLine(&lineptr, &bufferSize, stdin) != -1)
	{
		command = tokenize(lineptr, delim);
		shellHelper(command);
		printf("$ ");
	}
	
	free(lineptr);
	printf("\n");
	return (0);
}
