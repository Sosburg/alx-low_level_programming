#include "lists.h"
#include <stdlib.h>

/**
* print_listint_safe - Prints a listint_t linked list safely
* @head: Pointer to the head of the linked list
* Return: Number of nodes in the list
*/
size_t print_listint_safe(const listint_t *head)
{
const listint_t *slow, *fast;
size_t count = 0;

slow = head;
fast = head;

while (fast && fast->next)
{
count++;

if (slow == fast)
{
exit(98); /* Exit with status 98 if loop is detected */
}

slow = slow->next;
fast = fast->next->next;
}

return (count);
}
