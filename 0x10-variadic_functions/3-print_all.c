#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

void print_char(va_list arg);
void print_int(va_list arg);
void print_float(va_list arg);
void print_string(va_list arg);
void print_all(const char * const format, ...);

/**
 * print_char - Prints a character.
 * @arg: Argument list containing the character to be printed.
 */
void print_char(va_list arg)
{
	printf("%c", va_arg(arg, int));
}

/**
 * print_int - Prints an integer.
 * @arg: Argument list containing the integer to be printed.
 */
void print_int(va_list arg)
{
	printf("%d", va_arg(arg, int));
}

/**
 * print_float - Prints a float.
 * @arg: Argument list containing the float to be printed.
 */
void print_float(va_list arg)
{
	printf("%f", va_arg(arg, double));
}

/**
 * print_string - Prints a string.
 * @arg: Argument list containing the string to be printed.
 */
void print_string(va_list arg)
{
	char *str;

	str = va_arg(arg, char *);
	str == NULL ? printf("(nil)") : printf("%s", str);
}

/**
 * print_all - Prints arguments based on the format provided.
 * @format: A list of types of arguments passed to the function.
 * @...: Variable number of arguments.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char *separator = "";

	va_start(args, format);


	while (format && format[i])
	{
		if ((format[i] == 'c' && (print_char(args), 1)) ||
				(format[i] == 'i' && (print_int(args), 1)) ||
				(format[i] == 'f' && (print_float(args), 1)) ||
				(format[i] == 's' && (print_string(args), 1)))
		{
			if ((format[i] == 'c' || format[i] == 'i' ||
						format[i] == 'f' || format[i] == 's') &&
					format[i + 1] != '\0')
			{
				printf("%s", separator);
				separator = ", ";
			}
		}

		i++;
	}
	printf("\n");

	va_end(args);
}
