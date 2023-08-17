#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>


/**
 * print_strings - Prints strings, followed by a new line.
 * @separator: The string to be printed between strings
 * @n: Number of strings passed to the function
 * @...: Variable number of strings
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	char *str;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(args, char *);

		if (str == NULL)
			printf("(nil)");
		else
			printf("%s", str);

		if (separator && i != n - 1)
			printf("%s", separator);
	}

	printf("\n");

	va_end(args);
}
