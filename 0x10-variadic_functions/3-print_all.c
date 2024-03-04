#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
* print_all - prints anything
* @format: list of types of arguments passed to the function
*/
void print_all(const char * const format, ...)
{
va_list args;
unsigned int i = 0;
char *str;

va_start(args, format);

while (format && format[i])
{
if (i > 0)
printf(", ");

switch (format[i])
{
case 'c':
printf("%c", va_arg(args, int));
break;
case 'i':
printf("%d", va_arg(args, int));
break;
case 'f':
printf("%f", va_arg(args, double));
break;
case 's':
str = va_arg(args, char *);
if (str == NULL)
str = "(nil)";
printf("%s", str);
break;
default:
break;
}

i++;
}

va_end(args);

printf("\n");
}

