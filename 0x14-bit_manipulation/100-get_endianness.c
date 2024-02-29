#include "main.h"

/**
* get_endianness - checks the endianness
*
* Return: 0 if big endian, 1 if little endian
*/
int get_endianness(void)
{
unsigned int test = 1;
char *endian_test = (char *)&test;

return (*endian_test);
}

