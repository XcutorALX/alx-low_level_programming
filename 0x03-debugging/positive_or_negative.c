#include "main.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * main -Entry point
 *@i: input number
 * Description: 'Checks the last digit of a number'
 *
 * Return: Always 0(success)
 */

void positive_or_negative(int i)
{
	if (i > 0)
	{
		printf("%d is positive\n", i);
	}
	else if (i < 0)
	{
		printf("%d is negative\n", i);
	}
	else
	{
		printf("%d is zero\n", i);
	}
}
