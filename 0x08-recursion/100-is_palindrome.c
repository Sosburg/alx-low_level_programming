#include "main.h"

/**
* is_palindrome - Checks if a string is a palindrome.
* @s: The string to be checked.
* Return: 1 if the string is a palindrome, 0 otherwise.
*/
int is_palindrome(char *s)
{
int length = 0;

while (s[length] != '\0')
length++;

return (check_palindrome(s, 0, length - 1));
}

/**
* check_palindrome - Helper function to check if
* a string is a palindrome recursively.
* @s: The string to be checked.
* @start: The starting index.
* @end: The ending index.
*
* Return: 1 if the string is a palindrome, 0 otherwise.
*/
int check_palindrome(char *s, int start, int end)
{
if (start >= end)
return (1); /* It's a palindrome */

if (s[start] != s[end])
return (0); /* It's not a palindrome */

return (check_palindrome(s, start + 1, end - 1));
}
