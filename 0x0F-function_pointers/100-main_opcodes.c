#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point of the program
 * @argc: Argument count
 * @argv: Array of argument strings
 *
 * Return: 0 on success, or an error code on failure
 */

int main(int argc, char *argv[])
{
	int num_bytes, i;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	num_bytes = atoi(argv[1]);

	if (num_bytes < 0)
	{
		printf("Error\n");
		return (2);
	}

	unsigned char *main_ptr = (unsigned char *)main;

	for (i = 0; i < num_bytes - 1; i++)
		printf("%02x ", main_ptr[i]);

	printf("%02x\n", main_ptr[i]);

	return (0);
}

