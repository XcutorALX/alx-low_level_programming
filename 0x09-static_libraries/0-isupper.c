#include "main.h"
/**
 * _isupper - checkes if a charactee is upper case
 * @c: tehe character to be tested
 * Return: rerturns 1 for uppercase and 0 for lower
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
