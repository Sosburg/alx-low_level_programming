#include "main.h"

/**
* _strlen - Returns the length of a string
* @str: The string to find the length of
*
* Return: The length of the string
*/
int _strlen(char *str)
{
int len = 0;

while (str[len] != '\0')
len++;

return len;
}

/**
* _putnbr - Prints an integer to the standard output
* @n: The integer to print
*/
void _putnbr(int n)
{
if (n < 0)
{
_putchar('-');
n = -n;
}

if (n / 10 != 0)
_putnbr(n / 10);

_putchar(n % 10 + '0');
}
