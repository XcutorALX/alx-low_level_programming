#include "main.h"

/**
 * print_alphabet - prints alphabets
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
