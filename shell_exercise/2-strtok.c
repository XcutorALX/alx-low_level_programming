#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <string.h>

/**
 * strTok: a function that splits a string into an array of string according to
 * a delim provided
 *
 * str: the string to be parsed
 * delim: the delimeter to look out for
 *
 * return: returns an array of strings
 */

char **strTok(char *str, char delim)
{
	size_t count, size;
	char **split;
	char *buffer;

	size = 1024;
	split = malloc(size * sizeof(char));

	if (!split)
	{
		perror("Memory reallocation error");
		exit(EXIT_FAILURE);
	}

	buffer = strtok(str, &delim);
	split[0] = buffer;

	for (count = 1; buffer = strtok(NULL, &delim); count++)
	{
		if (count == size - 1)
		{
			size *= 1.5;
			split = realloc(split, size * sizeof(char));

			if (!split)
			{
				perror("Memory reallocation error");
				exit(EXIT_FAILURE);
			}
		}
		split[count] = buffer;
	}
	split[count++] = NULL;
	size = count + 1;

	split = realloc(split, size * sizeof(split));
	
	if (!split)
	{
		perror("Memory reallocation error");
		exit(EXIT_FAILURE);
	}

	return (split);
}	
