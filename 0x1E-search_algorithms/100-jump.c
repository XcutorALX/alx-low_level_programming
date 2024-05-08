#include "search_algos.h"
#include <stddef.h>
#include <stdio.h>
#include <math.h>


/**
 * jump_search - this function searches for a value in a sorted array
 * of integers using the jump search algorithm
 *
 * @array: the array to be searched
 * @size: the size of the array
 * @value: the value to be searched for
 *
 * Return: the index of the first element matching value in the array
 * else -1
 */
int jump_search(int *array, size_t size, int value)
{
	size_t i, j, m;

	m = (size_t)sqrt((double)size);
	i = 0;

	if (array == NULL || size == 0)
		return (-1);

	while (array[i * m] < value && (i * m) < size)
	{
		printf("Value checked array[%lu] = [%d]\n", i * m, array[i * m]);

		if (array[i * m] == value)
			return (i * m);

		i += 1;
	}

	if (i == 0)
		return (-1);

	printf("Value found between indexes [%lu] and [%lu]\n", (i - 1) * m, i * m);
	for (j = ((i - 1) * m); j <= (i * m) && j < size; j++)
	{
		printf("Value checked array[%lu] = [%d]\n", j, array[j]);
		if (array[j] == value)
			return (j);
	}
	return (-1);
}
