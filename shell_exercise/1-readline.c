#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * main: prints '$ 'and waits for user to enter a line
 * 
 * Return: always returns 0
 */

int main(void)
{
	size_t bufferSize = 1024;
	char *lineptr = NULL;
	
	printf("$ ");
	while(getLine(&lineptr, &bufferSize, stdin) != -1)
	{
		printf("%s", lineptr);
		printf("$ ");
	}
	
	free(lineptr);
	printf("\n");
	return (0);
}
