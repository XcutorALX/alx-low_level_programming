#include "main.h"
/**
 * print_diagonal - prints a diagonal line
 *@n: lenght of diagonal
 *
 * Return: void
 */
void print_diagonal(int n)
{
	int j, i;

	if (n <= 0)
		_putchar('\n');
	for (i = 0; i < n; i++)
	{
		for (j = i; j > 0; j--)
			_putchar(' ');
		_putchar('\\');
		_putchar('\n');
	}
}
