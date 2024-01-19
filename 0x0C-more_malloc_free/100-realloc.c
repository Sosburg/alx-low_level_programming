#include "main.h"
#include <stdlib.h>

/**
* _realloc - Reallocates a memory block using malloc and free.
* @ptr: Pointer to the memory block to be reallocated.
* @old_size: Size of the old memory block in bytes.
* @new_size: Size of the new memory block in bytes.
*
* Return: A pointer to the newly allocated memory block, or NULL on failure.
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
void *new_ptr;
unsigned int i, copy_size;

/* If new_size is zero, and ptr is not NULL, equivalent to free(ptr) */
if (new_size == 0 && ptr != NULL)
{
free(ptr);
return (NULL);
}

/* If ptr is NULL, equivalent to malloc(new_size) */
if (ptr == NULL)
return (malloc(new_size));

/* If new_size is equal to old_size, do not do anything and return ptr */
if (new_size == old_size)
return (ptr);

/* Allocate memory for the new block using malloc */
new_ptr = malloc(new_size);

/* Check if memory allocation was successful */
if (new_ptr == NULL)
return (NULL);

/**
 * Determine the size to be copied based on
 * the minimum of old_size and new_size
 */
copy_size = (old_size < new_size) ? old_size : new_size;

/* Copy contents from the old block to the new block */
for (i = 0; i < copy_size; i++)
*((char *)new_ptr + i) = *((char *)ptr + i);

/* Free the old memory block */
free(ptr);

return (new_ptr);
}

