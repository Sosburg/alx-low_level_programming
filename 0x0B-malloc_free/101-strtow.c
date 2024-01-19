#include "main.h"
#include <stdlib.h>

/**
* strtow - splits a string into words
* @str: the input string
*
* Return: a pointer to an array of strings (words), or NULL if it fails
*/
char **strtow(char *str)
{
char **words;
int i, j, k, word_count, len, in_word;

if (str == NULL || *str == '\0')
return (NULL);

len = 0;
while (str[len] != '\0')
len++;

words = malloc((len + 1) * sizeof(char *));
if (words == NULL)
return (NULL);

word_count = 0;
in_word = 0;

for (i = 0, j = 0; i <= len; i++)
{
if (str[i] == ' ' || str[i] == '\0')
{
if (in_word)
{
words[word_count] = malloc((j + 1) * sizeof(char));
if (words[word_count] == NULL)
{
/* Free allocated memory on failure */
for (k = 0; k < word_count; k++)
free(words[k]);
free(words);
return (NULL);
}

for (k = 0; k < j; k++)
words[word_count][k] = str[i - j + k];
words[word_count][k] = '\0';

word_count++;
in_word = 0;
j = 0;
}
}
else
{
in_word = 1;
j++;
}
}

words[word_count] = NULL;

return (words);
}
