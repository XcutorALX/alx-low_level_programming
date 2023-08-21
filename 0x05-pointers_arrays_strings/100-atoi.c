#include "main.h"
/**
 * _atoi - a function that convert a string to an integer
 * @s: string to test
 *
 * Return: the number
 */
int _atoi(char *s)
{
	int i, sign, num, seen;

	num = 0;
	seen = 0;
	sign = 1;

	for (i = 0; seen < 2; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			num = (num * 10) + (s[i] - '0');
			seen = 1;
		}
		else
			if (seen == 1)
				seen++;
			else if (s[i] == '-')
				sign = -sign;
			else if (s[i] == '\0')
				break;
	}
	num = num * sign;
	return (num);
}
