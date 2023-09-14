#include "function_pointers.h"
#include <stddef.h>

/**
 * int_index - a function that searches for an integer
 * @array: an array of elements to check
 * @size: the size of the array
 * @cmp: a pointer to a function to compare elements
 *
 * Return: -1 if there are no integers and any the index of integer if spotted
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;
	int result;
	
	if (size <= 0 || !array || !cmp)
		return (-1);

	for (i = 0; i < size; i++)
	{
		result = cmp(array[i]);
		if (result != 0)
			return (i);
	}
	return (-1);
}
