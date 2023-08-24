#include "main.h"
/**
 * reverse_array - a function that reverses the content of an array of integers
 * @a: an array of integers
 * @n: the number of elements to swap
 *
 * Return: void
 */
void reverse_array(int *a, int n)
{
	int prev, i;

	for (i = n - 1; i >= (n / 2); i--)
	{
		prev = a[n - 1 - i];
		a[n - 1 - i] = a[i];
		a[i] = prev;
	}
}
