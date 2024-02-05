#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array using jump search.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: The index where the value is located, or -1 if not found.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t jump = sqrt(size);  /*Jump step*/
	size_t prev = 0;           /*Previous jump index*/
	size_t current = 0;        /*Current jump index*/
	size_t i;

	if (array == NULL)
		return (-1);

	while (current < size && array[current] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", current, array[current]);
		prev = current;
		current += jump;

		if (current >= size)
			break;
	}
	printf("Value found between indexes [%lu] and [%lu]\n", prev, current);

    /*
     * Perform linear search in the identified block
     */
	for (i = prev; i <= current && i < size; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);

		if (array[i] == value)
			return (i);
	}

	return (-1); /*Value not found*/
}
