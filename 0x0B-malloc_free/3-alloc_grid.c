#include "main.h"
#include <stdlib.h>

/**
* alloc_grid - allocates a 2-dimensional array of integers
* @width: width of the grid
* @height: height of the grid
*
* Return: a pointer to the allocated grid, or NULL on failure
*/
int **alloc_grid(int width, int height)
{
int **grid;
int i, j;

/* Check for invalid width or height */
if (width <= 0 || height <= 0)
return (NULL);

/* Allocate memory for the rows */
grid = (int **)malloc(height * sizeof(int *));

if (grid == NULL)
return (NULL);

/* Allocate memory for the columns in each row */
for (i = 0; i < height; i++)
{
grid[i] = (int *)malloc(width * sizeof(int));

if (grid[i] == NULL)
{
/* Free allocated memory on failure */
for (j = 0; j < i; j++)
free(grid[j]);
free(grid);
return (NULL);
}
}

/* Initialize each element to 0 */
for (i = 0; i < height; i++)
{
for (j = 0; j < width; j++)
{
grid[i][j] = 0;
}
}

return (grid);
}

