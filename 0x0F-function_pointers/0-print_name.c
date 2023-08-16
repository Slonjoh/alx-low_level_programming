#include <stdio.h>
#include "function_pointers.h"

/**
 * print_name - Prints a name using a provided function
 * @name: Name to be printed
 * @f: Pointer to a function that takes a char* argument and returns void
 *
 * Return: void
 */

void print_name(char *name, void (*f)(char *))
{
	if (name && f)
		f(name);
}
