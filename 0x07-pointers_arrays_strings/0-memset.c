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

	char buffer[98] = {0x00};
	char *result = _memset(buffer, 0x01, 95);

	for (int i = 0; i < 98; i++)
	{
		
		printf("%p \n",(void*)result);
		printf("-------------------------------------------------\n");
		printf("%p ", *&buffer);
	}

	return (0);
}
