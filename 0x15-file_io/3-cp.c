#include "main.h"
#include <stdarg.h>

/**
 * print_error - Prints an error message to stderr.
 * @code: The error code.
 * @format: The format string for the error message.
 */

void print_error(int code, const char *format, ...)
{
	va_list args;

	va_start(args, format);
	dprintf(2, "Error: ");
	dprintf(2, format, args);
	va_end(args);
	exit(code);
}

/**
 * main - Entry point of the program.
 * @argc: The number of arguments.
 * @argv: The array of argument strings.
 *
 * Return: 0 on success, otherwise the appropriate error code.
 */

int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t bytes_read, bytes_written;
	char buffer[1024];

	if (argc != 3)
		print_error(97, "Usage: cp file_from file_to\n");
	fd_from = open(argv[1], O_RDONLY);

	if (fd_from == -1)
		print_error(98, "Can't read from file %s\n", argv[1]);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		print_error(99, "Can't write to file %s\n", argv[2]);

	while ((bytes_read = read(fd_from, buffer, sizeof(buffer))) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
			print_error(99, "Can't write to file %s\n", argv[2]);
	}

	if (bytes_read == -1)
		print_error(98, "Can't read from file %s\n", argv[1]);

	if (close(fd_from) == -1)
		print_error(100, "Can't close fd %d\n", fd_from);

	if (close(fd_to) == -1)
		print_error(100, "Can't close fd %d\n", fd_to);

	return (0);
}
