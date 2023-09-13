#include <stddef.h>
#include "function_pointers.h"

/**
 * array_iterator -  a function that executes a function given
 *  as a parameter on each element of an array
 *@array: the array of parameters for the function
 *@size: the size of the array
 *@action: pointer to the function
 *
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (!array || !action)
		return;

	for (i = 0; i < size; i++)
		action(array[i]);
}
