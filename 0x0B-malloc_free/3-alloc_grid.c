#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers.
 * @width: width of the array.
 * @height: height of the array.
 *
 * Return: pointer of an array of integers
 */

int **alloc_grid(int width, int height)
{
	if (width <= 0 || height <= 0)
		return (NULL);

	int **grid = (int **)malloc(height * sizeof(int *));

	if (grid == NULL)
		return (NULL);

	int i, j, k;

	for (i = 0; i < height; i++)
		grid[i] = (int *)malloc(width * sizeof(int));
	if (grid[i] == NULL)
		for (j = 0; j < i; j++)
			free(grid[j]);

	free(grid);
	return (NULL);

	for (k = 0; k < width; k++)
		grid[i][k] = 0;


	return (grid);


}
