#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 * main - simple shell that executes ls -l /tmp in 5 different child processes
 *
 * return: always 0
 */

int main(int argc, char *argv[])
{
	char *env[] = {NULL};
	int status;
	pid_t child_pid;
	
	for (int i = 0; i < 5; i++)
	{
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("At forking ERROR:");
			return (-1);
		}

		if (child_pid == 0)
		{
			if (execve(argv[1], (char **)&argv[1], env) == -1)
			{
				perror("At execve ERROR:");
				return (-1);
			}
		}
		else
		{
			wait(&status);
			printf("done\n");
			sleep(3);
		}
	}

	return (0);
}
