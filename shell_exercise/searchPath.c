#include <stdio.h>
#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#define DELIM ":"
/**
 * searchFile: this function searches for a file in the system PATH
 *
 * @fileName: the name of the file to search for
 *
 * Return: 1 if found and 0 if not found
 */

int searchFile(char *fileName)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char **pathTokens;
	char *fullPath;
	size_t index, fileLength, i;
	struct stat st;

	pathTokens = tokenize(path, DELIM);
	
	if (!pathTokens)
	{
		perror("Unable to get paths");
		return (-1);
	}

	for (fileLength = 0; fileName[fileLength] != '\0'; fileLength++);
	
	fullPath = malloc(1024);

	for (index = 0; pathTokens[index]; index++)
	{
		for (i = 0; pathTokens[index][i] != '\0'; i++)
		{
			fullPath[i] = pathTokens[index][i];
		}
		fullPath[i++] = '/';
		for (size_t j = 0; fileName[j] != '\0'; j++,i++)
		{
			fullPath[i] = fileName[j];
		}
		fullPath[i] = '\0';
		
		if (stat(fullPath, &st) == 0)
		{
			free(fullPath);
			return 1;
		}
	}

	free(fullPath);
	return 0;
}
