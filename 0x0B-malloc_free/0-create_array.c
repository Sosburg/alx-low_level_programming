#include "main.h"
#include <stdlib.h>
#include <stddef.h>
/**
* create_array - create an array of chars
* and initializes it with a specific char.
* @size: the size of the array.
* @c: the char to initialize the array with.
*
* Return: a pointer to the array, or NULL if it fails.
*/
char *create_array(unsigned int size, char c)
{
char *arr;
unsigned int i;

if (size == 0)
return (NULL);

arr = malloc(size * sizeof(char));

if (arr == NULL)
return (NULL);

for (i = 0; i < size; i++)
arr[i] = c;

return (arr);
}
