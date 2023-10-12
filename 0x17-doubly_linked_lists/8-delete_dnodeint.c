#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at a given index
 * @head: Pointer to a pointer to the head of the list
 * @index: Index of the node to be deleted
 * Return: 1 if successful, -1 if the node doesn't exist or deletion fails
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;
	dlistint_t *temp = NULL;
	unsigned int i = 0;

	if (!current)
		return (-1);

	if (index == 0)
	{
		*head = current->next;
		if (*head)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	while (current && i < index - 1)
	{
		current = current->next;
		i++;
	}

	if (!current || !current->next)
		return (-1);

	temp = current->next;
	current->next = temp->next;

	if (temp->next)
		temp->next->prev = current;

	free(temp);
	return (1);
}
