#include <stdio.h>
#include <main.h>
/**
 * main - prints _putchar, followed by a new line
 *
 * Return: Always 0
 */
int main(void)
{
	char word = "_putchar";

	while (word)
	{
		_putchar(word);
		word++;
	}
	_putchar('\n');

	return (0);
}
