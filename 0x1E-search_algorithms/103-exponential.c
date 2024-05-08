#include "search_algos.h"
#include <stdio.h>
#include <stddef.h>


/**
 * exponential_search - a function that searches through an array
 * for an element using the exponential search algorithm
 *
 * @array: the array to be searched
 * @value: the value being searched for
 * @size: the size of the array
 *
 * Return: the index of the first occurence of value else -1
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t i, hi, lo;
	int result;

	i = 1;

	while (i < size && array[i] <= value)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		i *= 2;
	}

	lo = i / 2;
	hi = i;
	if (i >= size)
		hi = size - 1;
	printf("Value found between indexes [%lu] and [%lu]\n", lo, hi);

	result = binary_search(&array[lo], (hi - lo) + 1, value);
	return (result == -1 ? result : result + (int)lo);
}


/**
 * binary_search -  a function that searches for a value in a
 * sorted array of integers using the Binary search algorithm
 *
 * @array: the array to be searched
 * @size: the size of the array
 * @value: the value to search for in the array
 *
 * Return: the index of the first occurence of value
 */
int binary_search(int *array, size_t size, int value)
{
	size_t mid, start, end;

	if (array == NULL || size == 0)
		return (-1);

	start = 0;
	end = size - 1;
	mid = end / 2;
	while (start <= end)
	{
		printf("Searching in array: ");
		print_array(&array[start], (end - start) + 1);
		if (value == array[mid])
			return (mid);
		else if (value < array[mid])
			end = mid - 1;
		else
			start = mid + 1;
		mid = start + (end - start) / 2;
	}

	if (array[start] == value)
		return (start);
	else
		return (-1);
}

/**
 * print_array - a function to print an array of integers
 *
 * @array: the array to be printed
 * @size: the size of the array
 */
void print_array(int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		printf("%d",  array[i]);

		if (i != (size - 1))
			printf(", ");
		else
			printf("\n");
	}
}
