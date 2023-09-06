#include "main.h"
/**
 * _strncat - a function that concatenates two strings
 * @dest: the destination string
 * @src: the source string
 * @n: the maximum amount of bytes to concatenate
 *
 * Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; j < n && src[j]; j++, i++)
		dest[i] = src[j];
	dest[i] = '\0';
	return (dest);
}
