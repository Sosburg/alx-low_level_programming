#include "main.h"

/**
* wildcmp - Compares two strings and returns 1 if they are identical,
*            otherwise returns 0.
* @s1: The first string.
* @s2: The second string with wildcard character *.
*
* Return: 1 if strings are identical, 0 otherwise.
*/
int wildcmp(char *s1, char *s2)
{
if (*s1 == '\0' && *s2 == '\0')
return (1); /* Both strings are empty, consider them identical */

if (*s2 == '*')
{
if (*s1 == '\0')
return (wildcmp(s1, s2 + 1)); /* * can replace an empty string */

return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
}

if (*s1 == *s2)
return (wildcmp(s1 + 1, s2 + 1));

return (0); /* Characters don't match */
}
