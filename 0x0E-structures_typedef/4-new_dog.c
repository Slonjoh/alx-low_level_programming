#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * new_dog - Creates a new dog
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Owner of the dog
 *
 * Return: Pointer to the newly created dog, or NULL if failed
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog_ptr;
	int i, lname, lowner;

	lname = strlen(name);
	lowner = strlen(owner);

	new_dog_ptr = malloc(sizeof(dog_t));
	if (new_dog_ptr == NULL)
		return (NULL);

	new_dog_ptr->name = malloc(lname + 1);
	if (new_dog_ptr->name == NULL)
	{
		free(new_dog_ptr);
		return (NULL);
	}

	for (i = 0; i < lname; i++)
		new_dog_ptr->name[i] = name[i];

	new_dog_ptr->name[i] = '\0';

	new_dog_ptr->age = age;

	new_dog_ptr->owner = malloc(lowner + 1);

	if (new_dog_ptr->owner == NULL)
	{
		free(new_dog_ptr->name);
		free(new_dog_ptr);

		return (NULL);
	}

	for (i = 0; i < lowner; i++)
		new_dog_ptr->owner[i] = owner[i];

	new_dog_ptr->owner[i] = '\0';

	return (new_dog_ptr);
}
