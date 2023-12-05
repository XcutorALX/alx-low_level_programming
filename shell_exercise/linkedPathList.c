#include <stdio.h>
#include <string.h>
#include "main.h"
#define DELIM ":"


list_l *linkedPathList(void)
{
	char *name = "PATH";
	char *path = getEnv(name);
	char **pathTokens;
	list_l *pathList;

	pathTokens = tokenize(path, DELIM);
	pathList = createList();

	for (size_t i = 0; pathTokens[i]; i++)
	{
		add_node(pathList, pathTokens[i]);
	}
	
	print_list(pathList);

	return (pathList);
}

int main(void)
{
	linkedPathList();
	return 0;
}
