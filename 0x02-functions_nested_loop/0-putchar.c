#include <stdio.h>

/**
 *main - A program that prints _putchar,
 *followed by a new line.
 *_putchar() - Records and returns a single character
 * c - is a character argument
 * Return: Always 0
 */

int _putchar(char c);
int main(void)
{
	_putchar('_');
	_putchar('p');
	_putchar('u');
	_putchar('t');
	_putchar('c');
	_putchar('h');
	_putchar('a');
	_putchar('r');
	_putchar('\n');
	return (0);
}

int _putchar(char c)
{
	return (putchar(c));
}
