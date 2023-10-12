#include <stdlib.h>
#include "lists.h"

/**
 * sum_dlistint - computes the sum of all elements in a dlistint_t list
 * @head: pointer to the head of the list
 * Return: the sum of all elements, or 0 if the list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
