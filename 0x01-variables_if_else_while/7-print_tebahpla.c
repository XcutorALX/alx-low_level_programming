#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int main(void)
{
	char myChar;

	for (myChar = 'z'; myChar >= 'a'; myChar--)
	{
		putchar(myChar);
	}
	putchar('\n');
	return (0);
}
