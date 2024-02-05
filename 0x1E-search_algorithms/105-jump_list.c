#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted
 *             list using the Jump search algorithm.
 * @list: Pointer to the head of the list to search in.
 * @size: Number of nodes in the list.
 * @value: Value to search for.
 *
 * Return: Pointer to the first node where value is located,
 *         or NULL if not found.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t jump = sqrt(size);
	listint_t *current = list;
	listint_t *prev = NULL;
	size_t i;

	if (list == NULL)
		return (NULL);

	while (current && current->n < value)
	{
		prev = current;
		for (i = 0; current && i < jump; i++)
			current = current->next;
		if (current)
			printf("Value checked at index [%lu] = [%d]\n",
					current->index, current->n);
	}

	if (!current)
		return (NULL);

	printf("Value found between indexes [%lu] and [%lu]\n",
			prev->index, current->index);

	while (prev && prev->index <= current->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}

	return (NULL);
}
