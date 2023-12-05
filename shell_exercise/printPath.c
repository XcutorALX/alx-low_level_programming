#include <stdio.h>
#include "main.h"
#define DELIM ":"

extern char **environ;

void printPath(void)
{
	char name[] = "PATH";
	char *path = getEnv(name);
	char **splitPaths;

	splitPaths = tokenize(path, DELIM);

	for (size_t i = 0; splitPaths[i]; i++)
		printf("%s\n", splitPaths[i]);
}

int main(void)
{
	printPath();
	return 0;
}
