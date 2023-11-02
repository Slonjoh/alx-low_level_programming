#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the hash table array
 *
 * Return: A pointer to the created sorted hash table or NULL on failure
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *sht;
	unsigned long int i;

	sht = malloc(sizeof(shash_table_t));

	if (sht == NULL)
		return (NULL);

	sht->size = size;
	sht->array = malloc(sizeof(shash_node_t *) * size);

	if (sht->array == NULL)
	{
		free(sht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		sht->array[i] = NULL;

	sht->shead = NULL;
	sht->stail = NULL;

	return (sht);
}
/**
 * insert_sorted_node - Inserts a node into a sorted linked list
 * @ht: The sorted hash table
 * @new_node: The node to insert
 * Return: Pointer to the inserted node
 */
shash_node_t *insert_sorted_node(shash_table_t *ht, shash_node_t *new_node)
{
	shash_node_t *current;

	if (ht == NULL || new_node == NULL)
		return (NULL);

	if (ht->shead == NULL)
	{
		ht->shead = new_node;
		ht->stail = new_node;
		new_node->sprev = NULL;
		new_node->snext = NULL;
		return (new_node);
	}
	current = ht->shead;
	while (current)
	{
		if (strcmp(new_node->key, current->key) <= 0)
		{
			new_node->snext = current;
			new_node->sprev = current->sprev;
			if (current->sprev)
				current->sprev->snext = new_node;
			else
				ht->shead = new_node;
			current->sprev = new_node;
			return (new_node);
		}
		if (current->snext == NULL)
		{
			new_node->snext = NULL;
			new_node->sprev = current;
			current->snext = new_node;
			ht->stail = new_node;
			return (new_node);
		}
		current = current->snext;
	}
	return (NULL);
}

/**
 * shash_table_set - Adds an element to the sorted hash table
 * @ht: The sorted hash table
 * @key: The key to add (string)
 * @value: The value associated with the key (string)
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node, *node, *prev;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	node = ht->shead;
	prev = NULL;

	while (node != NULL && strcmp(node->key, key) < 0)
	{
		prev = node;
		node = node->snext;
	}

	if (node != NULL && strcmp(node->key, key) == 0)
	{
		free(node->value);
		node->value = strdup(value);
		return (1);
	}
	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->sprev = prev;
	new_node->snext = node;

	if (prev != NULL)
		prev->snext = new_node;
	else
		ht->shead = new_node;

	if (node != NULL)
		node->sprev = new_node;
	else
		ht->stail = new_node;

	return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key
 * @ht: The sorted hash table
 * @key: The key to look up (string)
 *
 * Return: The value associated with key, or NULL if key couldn't be found
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *node;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}

	return (NULL);
}

/**
 * shash_table_print - Prints sorted hash table in ascending order by key
 * @ht: The sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current;
	int first = 1;

	if (ht == NULL)
		return;

	printf("{");
	current = ht->shead;
	while (current != NULL)
	{
		if (first == 0)
			printf(", ");
		printf("'%s': '%s'", current->key, current->value);
		first = 0;
		current = current->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints sorted hash table in descending order by key
 * @ht: The sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current;
	int first = 1;

	if (ht == NULL)
		return;

	printf("{");
	current = ht->stail;
	while (current != NULL)
	{
		if (first == 0)
			printf(", ");
		printf("'%s': '%s'", current->key, current->value);
		first = 0;
		current = current->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes the sorted hash table
 * @ht: The sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *current, *tmp;

	if (ht == NULL)
		return;

	current = ht->shead;
	while (current != NULL)
	{
		tmp = current;
		current = current->snext;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
	free(ht->array);
	free(ht);
}
