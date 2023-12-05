#include <stdio.h>
#include <string.h>
#include "main.h"

#define DELIM "="

extern char **environ;

char *getEnv(const char *varName)
{
	size_t index;
	char **varPair;

	for (index = 0; environ[index] != NULL; index++)
	{
		varPair = tokenize(environ[index], DELIM);

		if (strcmp(varPair[0], varName) == 0)
		{
			return (varPair[1]);
		}

		free(varPair);
	}
	return (NULL);
}
