#include "search_algos.h"
#include <stddef.h>
#include <stdio.h>


/**
 * interpolation_search - a function that searches for a value in
 * a sorted array of integers using the interpolation search algorithm
 *
 * @size: the size of the array
 * @array: the array to be searched
 * @value: the value to be searched for
 *
 * Return: the index of the first occurence of value else -1
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t pos, hi, lo;


	if (array == NULL || size == 0)
		return (-1);
	hi = size - 1;
	lo = 0;


	while (lo <= hi)
	{
		pos = lo + (((double)(hi - lo) / (array[hi] - array[lo]))
			* (value - array[lo]));

		printf("Value checked array[%lu] ", pos);

		if (pos >= size)
		{
			printf("is out of range\n");
			return (-1);
		}

		printf("= [%d]\n", array[pos]);

		if (array[pos] == value)
			return (pos);
		else if (array[pos] < value)
			hi = pos - 1;
		else
			lo = pos + 1;
	}

	return ((array[hi] == value) ? (int)hi : -1);
}
