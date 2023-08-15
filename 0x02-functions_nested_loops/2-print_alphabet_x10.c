#include "main.h"

/**
 * print_alphabet_x10 - prints alphabets
 *
 * Return: none
 */
void print_alphabet_x10(void)
{
	int i;
	char myChar;

	for (i = 0; i < 10; i++)
	{
		for (myChar = 'a'; myChar <= 'z'; myChar++)
		{
			_putchar(myChar);
		}
		_putchar('\n');
	}
}
