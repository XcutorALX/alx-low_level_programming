#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int main(void)
{
	int digit;
	char myChar;

	for (digit = 48; digit < 58; digit++)
	{
		putchar(digit);
	}
	for (myChar = 'a'; myChar <= 'f'; myChar++)
	{
		putchar(myChar);
	}
	putchar('\n');
	return (0);
}
