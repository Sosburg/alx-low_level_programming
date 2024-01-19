#include "main.h"
#include <stdlib.h>

/**
* argstostr - concatenates all the arguments of the program
* @ac: number of arguments
* @av: array of argument strings
*
* Return: a pointer to a new string containing concatenated arguments
* or NULL if it fails
*/
char *argstostr(int ac, char **av)
{
char *concat_str;
int total_length = 0, i, j, k = 0;

/* Return NULL if no arguments or array is NULL */
if (ac == 0 || av == NULL)
return (NULL);

/* Calculate the total length of the concatenated string */
for (i = 0; i < ac; i++)
{
for (j = 0; av[i][j] != '\0'; j++)
total_length++;
total_length++; /* For the newline character */
}

/* Allocate memory for the concatenated string */
concat_str = malloc((total_length + 1) * sizeof(char));

if (concat_str == NULL)
return (NULL);

/* Copy each argument and add newline character */
for (i = 0; i < ac; i++)
{
for (j = 0; av[i][j] != '\0'; j++)
{
concat_str[k] = av[i][j];
k++;
}
concat_str[k] = '\n';
k++;
}

/* Add null terminator to the end of the concatenated string */
concat_str[k] = '\0';

return (concat_str);
}
