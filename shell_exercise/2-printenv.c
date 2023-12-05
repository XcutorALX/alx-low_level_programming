#include <stdio.h>

extern char **environ;

int main(void)
{
	for (int i = 0; environ[i]; i++)
		printf("%s", environ[i]);

	return 0;
}
