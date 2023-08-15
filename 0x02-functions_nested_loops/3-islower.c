#include "main.h"
/**
 * _islower - checks for uppe and lower case
 *@c: the character to be checked
 *
 * Return: 0 for upper case and 1 for lower
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
