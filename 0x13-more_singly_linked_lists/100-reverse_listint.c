#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t linked list.
 * @head: A pointer to a pointer to the head of the list.
 * Return: Pointer to the first node of the reversed list.
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *current = *head;
	listint_t *next = NULL;

	while (current != NULL)
	{
		listint_t *temp = current->next;
		current->next = next;
		next = current;
		current = temp;
	}

	*head = next;
	return (next);
}
