#include "main.h"
/**
 * print_sign - checks for uppe and lower case
 *@n: the character to be checked
 *
 * Return: 0 for zero, -1 for ngative
 *  and 1 for positive
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n < 0)
	{
		_putchar('-');
		return (-1);
	}
	else
	{
		_putchar('0');
		return (0);
	}
}
