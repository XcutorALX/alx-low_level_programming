#include "main.h"
#include <stdio.h>
/**
 * _strlen - a function that returns the length of a string
 * @s: returns the lenght of a string
 *
 * Return: the integer value of the length
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}
