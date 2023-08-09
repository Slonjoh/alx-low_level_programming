#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * strtow - Splits a string into words.
 * @str: The input string.
 *
 * Return: A pointer to an array of strings (words).
 *         The last element of the array is NULL.
 *         Returns NULL if str == NULL or str is an empty string.
 */

char **strtow(char *str)
{
	int word_count = 0;
	int in_word = 0;
	int i;
	char **words;
	char *token;
	int index;

	if (str == NULL || *str == '\0')
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			if (!in_word)
			{
				word_count++;
				in_word = 1;
			}
		}
		else
		{
			in_word = 0;
		
		}
	
	}

	words = (char **)malloc((word_count + 1) * sizeof(char *));

	if (words == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(str, " ");

	while (token != NULL)
	{
		words[index] = token;
		token = strtok(NULL, " ");
		index++;
	
	}

	words[index] = NULL;

	return (words);
}
