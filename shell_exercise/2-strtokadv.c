#include <stdio.h>
#include "main.h"

/**
 * strTokadv: parsing strings without strtok
 *
 * str: the string to be parsed
 * delim: the delimiter to watch out for
 *
 *Return: returns a pointer to an array of strings
**/

char **strTok(char *str, char *delim)
{
	size_t count, size, start, len, index;
	int newToken = 1;
	char **split;

	size = 1024;
	count = 0;
	index = 0;
	split = malloc(size * sizeof(char *));

	if (!str)
	{
		return (NULL);
	}

	if (!split)
	{
		perror("Memory reallocation error");
		exit(EXIT_FAILURE);
	}

	for (len = 0; str[len] != '\0'; len++)
	{
		for (size_t i = 0; delim[i] != '\0'; i++)
		{
			if (str[len] == delim[i])
			{
				str[len] = '\0';
				break;
			}
		}
	}

	for (start = 0; count < len; count++)
	{
		if (index == size - 1)
		{
			size *= 1.5;
			split = realloc(split, size * sizeof(char *));
			
			if (!split)
			{
				perror("Memory reallocation errror");
				exit(EXIT_FAILURE);
			}
		}
		if (count)
		{
			if (str[count - 1] != '\0' && str[count] == '\0')
				split[index++] = &str[start];
			else if (str[count - 1] == '\0' && str[count] != '\0')
				start = count;
		}
	}

	split[index++] = NULL;
	size = index + 1;

	split = realloc(split, size * sizeof(char *));
	
	if (!split)
	{
		perror("Memory reallocation error");
		exit(EXIT_FAILURE);
	}

	return (split);
}
