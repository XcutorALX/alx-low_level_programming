#include <stddef.h>
#include "function_pointers.h"
/**
  * print_name - a function that prints a name
  *@name: name to be printed
  *@f: a pointer to a function
  *
  *return: void
  */
void print_name(char *name, void (*f)(char *))
{
	f(name);
}
