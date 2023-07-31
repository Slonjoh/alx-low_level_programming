#include "main.h"
#include <stdio.h>

char *_memset(char *s, char b, unsigned int n)
{
	for (unsigned int i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}

int main(void)
{
	char arr[10];
	char *result = _memset(arr, 'A', 10);

	for (int i = 0; i < 10; i++)
	{
		printf("%c ", result[i]);
	}

	return (0);
}
