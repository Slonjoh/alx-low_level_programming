#include "main.h"
#include <stdio.h>
/**
 * _memset - fills memory with a constant byte,
 * @s: memory area.
 * @b: constant byte.
 * @n: bytes filled.
 * Return: the pointer to dest.
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;
	for (i = 0; i < n; i++)
	{
		*(s + i) =  b;
	}
	return (s);
}
int main()
{
	char arr[10];
	char *result = _memset(arr, 'A', 10);

	for (int i = 0; i < 10; i++)
	{
		printf("%p ", (void*)&result[i]);
	}

	return (0);
}
