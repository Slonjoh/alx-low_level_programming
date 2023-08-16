#include "function_pointers.h"
#include <stdio.h>

/**
 * array_iterator - Executes a function on each element of an array
 * @array: Pointer to the array
 * @size: Size of the array
 * @action: Pointer to the function to be executed on each element
 *
 * Return: void
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	if (array && action)
	{
		for (size_t i = 0; i < size; i++)
		{
			action(array[i]);
		}
	}
}

