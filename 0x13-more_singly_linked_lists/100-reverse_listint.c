#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t linked list.
 * @head: A pointer to a pointer to the head of the list.
 * Return: Pointer to the first node of the reversed list.
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *current = *head;
	listint_t *temp;

	while (head != NULL)
	{
		temp = (*head)->next;
		(*head)->next = current;

		current = *head;
		*head = temp;
	}

	*head = current;
	return current;
}
