#include "search_algos.h"
#include <stddef.h>
#include <stdio.h>


/**
 * linear_search - this function searches for an element in a list
 * using the linear search algprithm
 *
 * @array: the array to be searched
 * @size: the size of the array
 * @value: the value being searched for
 *
 * Return: the first index where value is located
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}
