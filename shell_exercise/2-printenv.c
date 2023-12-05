#include <stdio.h>

extern char **environ;

int main(int ac,char **av, char **env)
{
	for (int i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);
	printf("\n");
	for (int i = 0; env[i]; i++)
		printf("%s\n", env[i]);
	printf("\n");
	return 0;
}
