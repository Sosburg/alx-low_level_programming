#include "lists.h"
#include <stdlib.h>

/**
* free_listint_safe - frees a listint_t list safely
* @h: pointer to the head of the list
*
* Return: the size of the list that was freed
*/
size_t free_listint_safe(listint_t **h)
{
listint_t *current, *temp;
size_t size = 0;

if (h == NULL || *h == NULL)
return (0);

current = *h;

while (current != NULL)
{
size++;
temp = current;
current = current->next;

/* Check if we have visited this node before */
if (temp->next == NULL)
{
free(temp);
*h = NULL; /* Set head to NULL to avoid dangling pointers */
return (size);
}

/* Mark the node as visited */
temp->next = NULL;
free(temp);
}

*h = NULL; /* Set head to NULL to avoid dangling pointers */
return (size);
}

