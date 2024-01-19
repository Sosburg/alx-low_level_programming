#include "main.h"
#include <stdlib.h>

/**
* string_nconcat - Concatenates two strings.
* @s1: The first string.
* @s2: The second string.
* @n: The maximum number of bytes from s2 to concatenate.
*
* Return: A pointer to the concatenated string (s1 + s2), or NULL on failure.
*/
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
unsigned int len1, len2, i, j;
char *concat;

/* If s1 is NULL, treat it as an empty string */
if (s1 == NULL)
s1 = "";

/* If s2 is NULL, treat it as an empty string */
if (s2 == NULL)
s2 = "";

/* Calculate the length of s1 */
for (len1 = 0; s1[len1] != '\0'; len1++)
;

/* Calculate the length of s2 */
for (len2 = 0; s2[len2] != '\0'; len2++)
;

/* Allocate memory for the concatenated string */
concat = malloc(sizeof(char) * (len1 + (n >= len2 ? len2 : n) + 1));

/* Check if memory allocation was successful */
if (concat == NULL)
return (NULL);

/* Copy characters from s1 to the concatenated string */
for (i = 0; i < len1; i++)
concat[i] = s1[i];

/* Copy up to n characters from s2 to the concatenated string */
for (j = 0; j < n && s2[j] != '\0'; i++, j++)
concat[i] = s2[j];

/* Null-terminate the concatenated string */
concat[i] = '\0';

return (concat);
}
