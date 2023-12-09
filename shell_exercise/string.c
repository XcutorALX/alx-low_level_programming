#include <stdio.h>
#include "main.h"

/**
 * _strdup - duplicates a string
 *
 * @str: string to be duplicated
 *
 * Return: returns a pointer to the duplicate
 */

char *_strdup(char *str)
{
	char *duplicate;
	size_t size, index;

	size = 1024;
	duplicate = malloc(size * sizeof(char));

	for (index = 0; str[index] != '\0'; index++)
	{
		if (index == size - 1)
		{
			size *= 1.5;
			duplicate = realloc(duplicate, size * sizeof(char));
			
			if (!duplicate)
			{
				perror("Memory allocation error");
				exit(EXIT_FAILURE);
			}
		}
		duplicate[index] = str[index];
	}

	duplicate[index] = '\0';
	duplicate = realloc(duplicate, (index + 1) * sizeof(char));

	if (!duplicate)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	return duplicate;
}

/**
 * strcon - concatenates two strings
 *
 * @strOne: the first string
 * @strTwo: the second string
 *
 * return: a pointer to the concatenated string
 */

char *strcon(const char *strOne,const char *strTwo)
{
	char *strCon;
	size_t first, second, index;

	for (first = 0; strOne[first] != '\0'; first++);
	for (second = 0; strTwo[second] != '\0'; second++);

	strCon = malloc((first + second + 1) * sizeof(char));

	if (!strCon)
	{
		perror("memory allocation failed");
		exit(EXIT_FAILURE);
	}

	for (first = 0, index = 0; strOne[first] != '\0'; first++, index++)
		strCon[index] = strOne[first];

	for (second = 0; strTwo[second] != '\0'; second++, index++)
		strCon[index] = strTwo[second];

	strCon[index] = '\0';

	return strCon;
}
