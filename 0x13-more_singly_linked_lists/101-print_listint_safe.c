#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: A pointer to the head of the list.
 * Return: The number of nodes in the list.
 */

size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow = head, *fast = head;
	size_t count = 0;

	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		count++;
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			printf("-> [%p] %d\n", (void *)slow, slow->n);
			fprintf(stderr, "Linked list has a loop\n");
			exit(98);
		}
	}

	while (slow != NULL)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		count++;
		slow = slow->next;
	}

	return (count);
}
