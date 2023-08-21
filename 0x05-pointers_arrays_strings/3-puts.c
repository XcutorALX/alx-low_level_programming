#include "main.h"
/**
 * _puts -prints inputed string
 * @str: the string to be printed
 *
 * Return: none
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	_putchar('\n');
}
