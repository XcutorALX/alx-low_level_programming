#include "main.h"

/**
 * main - entry point
 *
 * Return: always zero
 */

void print_alphabet(void)
{
	char myChar;

	for (myChar = 'a'; myChar <= 'z'; myChar++)
		_putchar(myChar);
	_putchar('\n');
}
