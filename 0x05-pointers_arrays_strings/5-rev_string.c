#include "main.h"
/**
 * rev_string - prints a string in reverse
 * @s: string to be reversed
 *
 * Return: none
 */
void rev_string(char *s)
{
	int i, j, max;
	char temp;

	for (i = 0; s[i] != '\0'; i++)
		;
	max = i;
	for (i--, j = 0; j < max / 2; i--, j++)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}
