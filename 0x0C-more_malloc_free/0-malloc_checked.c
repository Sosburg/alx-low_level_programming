#include "main.h"

/**
 * malloc_checked - Allocates memory using malloc
 * @b: Size of the memory to allocate
 *
 * Return: Pointer to the allocated memory
 *         If malloc fails, exit with status value 98
 */
void *malloc_checked(unsigned int b)
{
    void *ptr = malloc(b);

    if (ptr == NULL)
    {
        exit(98);
    }

    return (ptr);
}
