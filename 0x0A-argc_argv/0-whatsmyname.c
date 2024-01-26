#include <stdio.h>

/**
*  * main - Entry point
*   * @argc: The number of command-line arguments
*    * @argv: An array of command-line argument strings
*     *
*      * Return: 0 on success
*/
int main(int argc, char *argv[])
{
if (argc > 0)
{
printf("%s\n", argv[0]);
return (0);
}

return (1);
}
