#include "main.h"
#include <stdio.h>
/**
 * print_chessboard - prints the chessboard
 * @a: input pointer.
 * Return: no return.
 */
void print_chessboard(char (*a)[8])

{
	for (int i = 0; i < 8; i++)
    {
	    for (int j = 0; j < 8; j++)
	    {
		    putchar(a[i][j]);
		    putchar(' ');
	    }
        putchar('\n');
    }
}
