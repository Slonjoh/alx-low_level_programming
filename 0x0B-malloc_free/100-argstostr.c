#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * argstostr - concatenates all the arguments of a program.
 * @ac: argument count.
 * @av: argument vector.
 *
 * Return: pointer of an array of char
 */

char *argstostr(int ac, char **av)

{
	if (ac == 0 || av == NULL)
		return (NULL);

	int total_length = 0;
	int i, j;

	for (i = 0; i < ac; i++)
	{
		total_length += strlen(av[i]) + 1;
	}

	char *result = (char *)malloc(total_length + 1);

	if (result == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	int index = 0;

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			result[index] = av[i][j];
			index++;
		}

		result[index] = '\n';
		index++;
	}

	result[index] = '\0';
	return (result);




}
