#include "main.h"
/**
 * _isdigit - checks for digits
 * @c: digit to be tested
 * Return: returns 1 for digits and 0 for non digits
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 58)
		return (1);
	else
		return (0);
}
