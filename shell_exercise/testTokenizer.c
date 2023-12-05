#include <stdio.h>
#include "main.h"

int main(void)
{
	char **argv;
	char str[] = "/bin/ls";
	char delim[] = " ";

	argv = tokenize(str, delim);

	if (argv[1] == NULL)
	{
		printf("Correct");
	}
	return (0);
}
