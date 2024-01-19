#include "main.h"
#include <stdlib.h>

/**
* str_concat - concatenates two strings
* @s1: the first string
* @s2: the second string
*
* Return: a pointer to the newly allocated space
* containing the concatenated string
* or NULL on failure.
*/
char *str_concat(char *s1, char *s2)
{
char *concat_str;
unsigned int len_s1, len_s2, i, j;

/* Treat NULL as an empty string */
if (s1 == NULL)
s1 = "";
if (s2 == NULL)
s2 = "";

/* Calculate the length of the strings */
for (len_s1 = 0; s1[len_s1] != '\0'; len_s1++)
;
for (len_s2 = 0; s2[len_s2] != '\0'; len_s2++)
;

/* Allocate memory for the concatenated string */
concat_str = malloc((len_s1 + len_s2 + 1) * sizeof(char));

if (concat_str == NULL)
return (NULL);

/* Copy s1 to the concatenated string */
for (i = 0; i < len_s1; i++)
concat_str[i] = s1[i];

/* Copy s2 to the concatenated string */
for (j = 0; j < len_s2; j++)
concat_str[i + j] = s2[j];

/* Add null terminator to the end of the concatenated string */
concat_str[i + j] = '\0';

return (concat_str);
}
