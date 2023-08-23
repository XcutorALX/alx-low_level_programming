#include "main.h"
/**
 * _strncpy - a function that copies a string
 * @dest: array the string shoudl be copied to
 * @src: the array the stringshoul be copied from
 * @n: the amount of bytes to copy
 *
 * Return: a pointer to the copied string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;

	for (j = 0; dest[j] != '\0'; j++)
		;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	if (n > (i + 1))
	{
		for (; i < n; i++)
			dest[i] = '\0';
	}
	return (dest);
}
