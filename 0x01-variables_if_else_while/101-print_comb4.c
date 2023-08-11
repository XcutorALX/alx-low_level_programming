#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int main(void)
{
	int m, n, i;

	for (n = 48; n < 58; n++)
	{
		for (m = 48; m < 58; m++)
		{
			for (i = 50; i < 58; i++)
			{
				if (i > m && m > n)
				{
					putchar(n);
					putchar(m);
					putchar(i);
					if (n != 55 || m != 56)
					{
						putchar(',');
						putchar(' ');
					}
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
