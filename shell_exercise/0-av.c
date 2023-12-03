#include <stdio.h>
#include <unistd.h>

/**
 * main: prints all the arguments passed into the program without ac
 *ac: the number of arguments passed
 *av: a null terminated list of strings
 *
 * Return: always 0
 */

int main(int ac, char *av[])
{
	size_t i;

	for (i = 0; av[i] != NULL; i++)
	{
		printf("%s \n", av[i]);
	}

	return (0);
}
