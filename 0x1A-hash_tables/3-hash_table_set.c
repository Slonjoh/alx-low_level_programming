#include "hash_tables.h"
#include <string.h>
#include <stdlib.h>

/**
 * add_node_to_list - Add a new node to the beginning of a linked list.
 * @ht: The hash table.
 * @index: The index where the node should be added.
 * @key: The key (string).
 * @value: The value associated with the key (string).
 *
 * Return: 1 if it succeeded, 0 otherwise.
 */

int add_node_to_list(hash_table_t *ht, unsigned long int index,
		const char *key, const char *value)
{
	hash_node_t *new_node = NULL;

	new_node = malloc(sizeof(hash_node_t));

	if (new_node == NULL)
		return (0);
	new_node->key = strdup(key);
	new_node->value = strdup(value);

	if (new_node->key == NULL || new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (0);
	}

	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}

/**
 * hash_table_set - Adds or updates an element in the hash table.
 * @ht: The hash table.
 * @key: The key (string).
 * @value: The value associated with the key (string).
 *
 * Return: 1 if it succeeded, 0 otherwise.
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *current = NULL;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	index = key_index((unsigned char *)key, ht->size);
	current = ht->array[index];

	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = strdup(value);
			if (current->value == NULL)
				return (0);
			return (1);
		}
		current = current->next;
	}

	return (add_node_to_list(ht, index, key, value));
}
