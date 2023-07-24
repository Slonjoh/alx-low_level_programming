#include <"main.h">
void print_rev(char *s)
{
	if (s == NULL)
	{
		_putchar('\n');
		return;
	}

	int length = 0;
	while (s[length] != '\0') 
	length++;
	for (int i = length - 1; i >= 0; i--)
       	{
		_putchar(s[i]);
	}
    _putchar('\n');
}

