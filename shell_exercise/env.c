#include <stdio.h>
#include <string.h>
#include "main.h"

#define DELIM "="

void **allocMem;
int allocated = 0 ;
int sizeAllocMem = 84;

/**
 * _getenv - gets the variable value from the current enviroment
 *
 * @varName: The enviroment variable to search for
 *
 * Return: returns a pointer to a string containing the value of the
 * enviroment variable returns NULL if the variable wasn't found
 */

char *_getenv(const char *name)
{
	size_t index;
	char **varToken;
	char *varDup;

	for (index = 0; environ[index] != NULL; index++)
	{
		varDup = _strdup(environ[index]);
		varToken = tokenize(varDup, DELIM);

		if (strcmp(varToken[0], name) == 0)
		{
			return (varToken[1]);
			addAddress(varDup);
			addAddress(varToken);
		}

		free(varDup);
		free(varToken);
	}
	return (NULL);
}


/**
 * _setenv - this function adds a variable name and its value to the current envioment
 *
 * @name: the name of the variable to be added
 * @value: the value of the variable to be added
 * @overwrite: whether to overwrite the variable value if the variable already exists
 * an overwrite value of zero disables overwriting and non zero enables it
 *
 * Return: returns zero on success or -1 on error, wth errno set to indicate the error
 */

int _setenv(char *name, const char *value, int overwrite)
{
	size_t envLen, varLen, i;
	char *varPair, *full, **buffer, *varDup, **temp;
	char join[] = "=";
	int seen = 0;

	temp = malloc(1024 * sizeof(char *));

	full = strcon(name, join);
	varPair = strcon(full, value);
	free(full);


	for (envLen = 0; environ[envLen] != NULL; envLen++)
	{
		varDup = _strdup(environ[envLen]);
		buffer = tokenize(varDup, DELIM);
		if ((strcmp(buffer[0], name) == 0))
		{
			if (overWrite == 1)
			{
				temp[envLen] = varPair;
			}
			seen == 1;
			temp[envLen] = environ[envLen];
		}
		else
			temp[envLen] = environ[envLen];

		free(varDup);
		free(buffer);
	}
	
	if (seen != 1)
		temp[envLen++] = varPair;

	temp = realloc(temp, (envLen + 1) * sizeof(char *));

	temp[envLen] = NULL;
	environ = temp;

	addAddress((void *)temp);
	addAddress((void *)varPair);

	return 0;
}

/**
 * _unsetenv - this function removes a variable and its value from the enviroment
 *
 * @name: the name of the variable to remove
 *
 * Return: returns 0 on failure
 */

int _unsetenv(char *name)
{
	size_t envLen, newEnvLen, size;
	size = 80;
	char **newEnv;
	char **buffer;
	char *env_dup;

	newEnv = malloc(size * sizeof(char *));
	
	for (envLen = 0, newEnvLen = 0; environ[envLen] != NULL; envLen++)
	{
		if (newEnvLen == size - 1)
		{
			size *= 1.5;
			newEnv = realloc(newEnv, size * sizeof(char *));

			if (!size)
			{
				perror("Memory allocation error");
				exit(EXIT_FAILURE);
			}
		}
		
		env_dup = _strdup(environ[envLen]);
		buffer = tokenize(env_dup, DELIM);
		
		if (strcmp(buffer[0], name) != 0)
		{
			newEnv[newEnvLen] = environ[envLen];
			newEnvLen ++;
		}
		free(buffer);
		free(env_dup);
		
	}

	newEnv[newEnvLen] = NULL;
	size = newEnvLen + 1;
	newEnv = realloc(newEnv, size * sizeof(char *));
	if (!size)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	
	environ = newEnv;
	addAddress(newEnv);

	return 0;
}

int main(void)
{
	allocMem = malloc(sizeAllocMem * sizeof(void));
	allocMem[0] = NULL;

	char envName[] = "PA2TH";
	char value[] = "I/SEE/THE/MOON";
	char newVal[] = "The/Moon/See/mee";

	for (size_t env = 0; environ[env] != NULL; env++)
		printf("%s\n", environ[env]);

	_setenv(envName, value, 1);

	for (size_t env = 0; environ[env] != NULL; env++)
		printf("%s\n", environ[env]);

	
	_setenv(envName, newVal, 1);

	for (size_t env = 0; environ[env] != NULL; env++)
		printf("%s\n", environ[env]);

	_unsetenv(envName);

	for (size_t env = 0; environ[env] != NULL; env++)
		printf("%s\n", environ[env]);

	freeMem();
	return 0;
}
