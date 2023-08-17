#include "main.h"
/**
 * print_most_numbers - prints numbers from 0-9
 *
 * Return: void
 */
void print_most_numbers(void)
{
	int i;

	for (i = 48; i < 58; i++)
		if (!(i == '2' || i == '4'))
			_putchar(i);
	_putchar('\n');
}
