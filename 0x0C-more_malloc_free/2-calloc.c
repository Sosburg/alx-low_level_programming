#include "main.h"
#include <stdlib.h>

/**
* _calloc - Allocates memory for an array and initializes it with zero.
* @nmemb: Number of elements in the array.
* @size: Size of each element in bytes.
*
* Return: A pointer to the allocated memory, or NULL on failure.
*/
void *_calloc(unsigned int nmemb, unsigned int size)
{
void *ptr;
unsigned int i;
unsigned int total_size;

/* If nmemb or size is 0, return NULL */
if (nmemb == 0 || size == 0)
return (NULL);

/* Calculate the total size of memory to be allocated */
total_size = nmemb * size;

/* Allocate memory using malloc */
ptr = malloc(total_size);

/* Check if memory allocation was successful */
if (ptr == NULL)
return (NULL);

/* Initialize the allocated memory to zero */
for (i = 0; i < total_size; i++)
*((char *)ptr + i) = 0;

return (ptr);
}
