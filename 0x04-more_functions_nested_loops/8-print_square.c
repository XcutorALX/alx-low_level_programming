#include "main.h"
/**
 * print_square - prints a square
 * @size: size of the square
 *
 * Return: void
 */
void print_square(int size)
{
	int i, j;
	
	if (size == 0)
		_putchar('\n');
	for (j = size; j > 0; j--)
	{
		for (i = 0; i < size; i++)
			_putchar('#');
		_putchar('\n');
	}
}
