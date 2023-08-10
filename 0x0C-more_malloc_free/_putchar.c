#include <unistd.h>

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to write.
 *
 * Return: The number of characters written (1).
 */
int _putchar(char c)
{
	return write(1, &c, 1);
}
