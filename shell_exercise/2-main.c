#include <stdio.h>
#include "main.h"

/**
 * main - entry point
 *
 * Return: always 0
 */

int main(void)
{
	size_t count;
	char str[] = "This is the day that i win";
	char delim[] = " ";
	char **split;

	split = strTok(str, delim);

	for (count = 0; split[count]; count++)
	{
		printf("%s \n", split[count]);
	}

	return (0);
}
