#include "main.h"
/**
 * cap_string - a function that capitalizes all words of a string
 * @str: the string to be changed
 *
 * Return: returns the pointer to the converted string
 */
char *cap_string(char *str)
{
	int i, newWord;

	newWord = 1;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (newWord == 1)
		{
			if (str[i] >= 'a' &&
				str[i] <= 'z')
			{
				newWord = 0;
				str[i] -= 32;
			}
			else if (str[i] >= 'A' &&
				str[i] <= 'Z')
			{
				newWord = 0;
			}
		}
		else if (str[i] == ' ' ||
			str[i] == '\t' ||
			str[i] == '\n' ||
			str[i] == ',' ||
			str[i] == ';' ||
			str[i] == '.' ||
			str[i] == '!' ||
			str[i] == '?' ||
			str[i] == '"' ||
			str[i] == '(' ||
			str[i] == ')' ||
			str[i] == '{' ||
			str[i] == '}')
			newWord = 1;
	}
	return (str);
}
