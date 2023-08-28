#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: A pointer to the head of the list.
 * Return: The number of nodes in the list.
 */

size_t print_listint_safe(const listint_t *head)
{
	int pdiff, count, a;

	if (head == NULL)
		return (0);
	for (count = 0; head; count++)
	{
		pdiff = head - head->next;
		printf("[%p] %d\n", (void *)head, head->n);
		if (pdiff > 0)
			head = head->next;
		else
		{
			a = (head->next)->n;
			printf("-> [%p] %d\n", (void *)head->next, a);
			count++;
			break;
		}
	}
	return (count);
}
