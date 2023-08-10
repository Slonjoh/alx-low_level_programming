#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * malloc_checked - Allocates memory using malloc.
 * @b: The size of memory to allocate.
 *
 * Return: A pointer to the allocated memory.
 *         Causes process termination with status 98 if allocation fails.
 */
void *malloc_checked(unsigned int b)
{
	void *ptr = malloc(b);

	if (ptr == NULL)
	{
		exit(98);
	}
	return (ptr);
}
