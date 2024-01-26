#include "function_pointers.h"
#include <stddef.h>
/**
* print_name - prints a name
*@name: name to be printed
*@f: pointer to a function that prints a name in a specific way
*/
void print_name(char *name, void (*f)(char *))
{
if (name != NULL && f != NULL)
f(name);
}
