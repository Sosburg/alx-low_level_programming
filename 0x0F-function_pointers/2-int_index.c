#include "function_pointers.h"

/**
*  * int_index - searches for an integer in an
*  array using a comparison function
*   * @array: array to search
*    * @size: number of elements in the array
*     * @cmp: pointer to the comparison function
*      *
*Return: index of the first element for which cmp does not return 0,
* or -1 if no such element is found
*/
int int_index(int *array, int size, int (*cmp)(int))
{
int i;

if (array != NULL && cmp != NULL)
{
for (i = 0; i < size; i++)
{
if (cmp(array[i]) != 0)
return (i);
}
}
return (-1);
}
