#include "main.h"
/**
 * _isalpha - checks for uppe and lower case
 *@c: the character to be checked
 *
 * Return: 0 for non alphabets and 1 for alphabets
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
