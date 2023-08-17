#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>


/**
 * print_numbers - Prints numbers, followed by a new line.
 * @separator: The string to be printed between numbers
 * @n: Number of integers passed to the function
 * @...: Variable number of integers
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(args, int));

		if (separator && i != n - 1)
			printf("%s", separator);
	}

	printf("\n");

	va_end(args);
}
