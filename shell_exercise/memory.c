#include <stdio.h>
#include "main.h"

/**
 * addAddress - adds an address to the global array keeping track
 * of dynamically allocated memory
 *
 * @addr: the address to add to the array
 *
 * Return: returns 0
 */

int addAddress(void *ptr)
{
	if (allocated == sizeAllocMem - 1)
	{
		sizeAllocMem *= 1.5;
		allocMem = realloc(allocMem, sizeAllocMem * sizeof(void *));

		if (!allocMem)
		{
			perror("Memory reallocation failed");
			exit(EXIT_FAILURE);
		}
	}
	allocMem[allocated] = ptr;

	allocated += 1;
	allocMem[allocated] = NULL;

	return 0;
}

/**
 * freeMem - frees all dynamically allocated memory not freed
 *
 * Return: always 0
 */

int freeMem(void)
{
	size_t i;

	for (i = 0; allocMem[i]; i++)
	{
		free(allocMem[i]);
	}
	
	free(allocMem);
	return 0;
}
