#include "main .h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory.
 * @str: string.
 *
 * Return: pointer of an array of chars
 */

char *_strdup(char *str)
{
	char *strcp;
	size_t length;

	if (str == NULL)
	{
		return (NULL);
	}

	length = strlen(str);

	strcp = (char *)malloc((length + 1) * sizeof(char));

	if (strcp == NULL)
	{
		return (NULL);
	}

	strcpy(strcp, str);
	return (strcp);

}
