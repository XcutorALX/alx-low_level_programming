#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int main(void)
{
	char myChar;

	for (myChar = 'a'; myChar <= 'z'; myChar++)
	{
		if ((myChar == 'q') || (myChar == 'e'))
		{
		}
		else
		{
			putchar(myChar);
		}
	}
	putchar('\n');
	return (0);
}
