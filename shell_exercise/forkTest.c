#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;

	printf("Before fork\n");
	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		return (1);
	}

	if (pid == 0)
		printf("Child: %u\n", getpid());
	else
	{
		printf("Parent: %u\n", getpid());
		printf("%u is my child\n", pid);
	}
	return (0);
}
