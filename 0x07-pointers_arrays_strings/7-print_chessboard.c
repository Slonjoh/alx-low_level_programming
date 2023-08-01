#include "main.h"
#include <stdio.h>
/**
 * print_chessboard - prints the chessboard
 * @a: input pointer.
 * Return: no return.
 */
void print_chessboard(char (*a)[8])

{
	int i;

	for (i = 0; i < 8; i++)
    {
	    int j;

	    for (j = 0; j < 8; j++)
	    {
		    putchar(a[i][j]);
		    putchar(' ');
	    }
        putchar('\n');
    }
}
