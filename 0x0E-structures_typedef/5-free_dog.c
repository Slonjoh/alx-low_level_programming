#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_dog - Frees memory allocated for a dog
 * @d: Pointer to a dog_t structure
 *
 * Return: void
 */

void free_dog(dog_t *d)
{
	if (d)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}

