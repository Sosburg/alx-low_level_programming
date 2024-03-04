#include "variadic_functions.h"
#include <stdio.h>

/**
* print_all - prints anything
* @format: list of types of arguments passed to the function
*/
void print_all(const char * const format, ...)
{
va_list args;
unsigned int i = 0;
char *str;
char separator = 0;

va_start(args, format);

while (format && format[i])
{
if (separator)
printf(", ");

switch (format[i])
{
case 'c':
printf("%c", va_arg(args, int));
separator = 1;
break;
case 'i':
printf("%d", va_arg(args, int));
separator = 1;
break;
case 'f':
printf("%f", va_arg(args, double));
separator = 1;
break;
case 's':
str = va_arg(args, char *);
if (str == NULL)
str = "(nil)";
printf("%s", str);
separator = 1;
break;
default:
separator = 0;
break;
}
i++;
}
va_end(args);
printf("\n"); }
