#include <stdio.h>

/**
* premain - prints a message before the main function is executed
*/
void __attribute__ ((constructor)) premain(void)
{
printf("You're beat! and yet, you must allow, ");
printf("\nI bore my house upon my back!\n");
}

