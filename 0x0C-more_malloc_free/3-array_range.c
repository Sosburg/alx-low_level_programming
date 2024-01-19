#include "main.h"
#include <stdlib.h>

/**
* array_range - Creates an array of integers.
* @min: The minimum value of the array (included).
* @max: The maximum value of the array (included).
*
* Return: A pointer to the newly created array, or NULL on failure.
*/
int *array_range(int min, int max)
{
int *arr;
int i, size;

/* If min is greater than max, return NULL */
if (min > max)
return (NULL);

/* Calculate the size of the array */
size = max - min + 1;

/* Allocate memory for the array using malloc */
arr = malloc(sizeof(int) * size);

/* Check if memory allocation was successful */
if (arr == NULL)
return (NULL);

/* Populate the array with values from min to max */
for (i = 0; i < size; i++)
arr[i] = min++;

return (arr);
}
