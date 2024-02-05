#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: A pointer to the head of the skip list to search in.
 * @value: The value to search for.
 *
 * Return: A pointer on the first node where value is located.
 *         If value is not present in list or if head is NULL, return NULL.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *express, *current;

	if (!list)
		return (NULL);
	express = list->express;
	current = list;
	while (express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				express->index, express->n);
		if (express->n >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
					current->index, express->index);
			break;
		}
		current = express;
		express = express->express;
	}

	if (!express)
	{
		current = list;
		while (current->next)
			current = current->next;
		printf("Value found between indexes [%lu] and [%lu]\n",
				current->index, current->index + 1);
	}
	while (current)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				current->index, current->n);
	if (current->n == value)
		return (current);
	else if (current->n > value)
		break;
	current = current->next;
	}
	return (NULL);
}
