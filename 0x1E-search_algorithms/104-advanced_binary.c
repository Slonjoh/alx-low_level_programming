#include <stdio.h>
#include "search_algos.h"

/**
 * advanced_binary - Searches for a value in a sorted
 *                   array using advanced binary search.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: The index where the value is located, or -1 if not found.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (binary_search_recursive(array, 0, size - 1, value));
}

/**
 * binary_search_recursive - Recursively searches for a value
 *                           in a sorted array using binary search.
 * @array: Pointer to the first element of the array to search in.
 * @low: The lower bound of the search range.
 * @high: The upper bound of the search range.
 * @value: Value to search for.
 *
 * Return: The index where the value is located, or -1 if not found.
 */
int binary_search_recursive(int *array, size_t low, size_t high, int value)
{
	size_t mid;

	if (low > high)
		return (-1);

	print_array(array, low, high);
	mid = (low + high) / 2;

	if (array[mid] == value)
	{
		if (mid > 0 && array[mid - 1] == value)
			return (binary_search_recursive(array, low, mid, value));
		return (mid);
	}
	else if (array[mid] < value)
		return (binary_search_recursive(array, mid + 1, high, value));
	else
		return (binary_search_recursive(array, low, mid - 1, value));
}

/**
 * print_array - Prints the elements of the array
 *               between left and right indices.
 * @array: Pointer to the first element of the array.
 * @left: Left index.
 * @right: Right index.
 */
void print_array(int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");

	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}
