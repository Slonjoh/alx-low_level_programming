#include <stddef.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list.
 * @h: A pointer to a pointer to the head of the list.
 * Return: The size of the list that was freed.
 */

size_t free_listint_safe(listint_t **h)
{
	listint_t *current = *h;
	listint_t *temp;
	size_t count = 0;

	while (current != NULL)
	{
		count++;
		temp = current;
		current = current->next;
		free(temp);

		if (temp == *h)
		{
			*h = NULL;
			break;
		}
	}

	return (count);
}
