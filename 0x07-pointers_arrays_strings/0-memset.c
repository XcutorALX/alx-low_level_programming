#include "main.h"

/**
 * _memset - Fills memory with a constant byte
 * @a: buffer array
 * @b: constant byte
 * @n: number of bytes of memory area to fill
 * Return: Pointer to memory area `a`
 */

char *_memset(char *a, char b, unsigned int n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		a[i] = b;
		n--;
		i++;
	}
	return (a);
}
