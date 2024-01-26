#include <stdio.h>
#include <stdlib.h>

/**
*  * main - prints the opcodes of its own main function
*   * @argc: number of arguments
*    * @argv: array of arguments
*     *
*Return: 0 on success, 1 for incorrect number of
*arguments, 2 for negative bytes
*/

int main(int argc, char *argv[])
{
int num_bytes;
int i;
unsigned char *main_addr;

if (argc != 2)
{
printf("Error\n");
return (1);
}

num_bytes = atoi(argv[1]);

if (num_bytes < 0)
{
printf("Error\n");
return (2);
}

main_addr = (unsigned char *)main;
for (i = 0; i < num_bytes; i++)
printf("%02x ", main_addr[i]);

printf("\n");
return (0);
}
