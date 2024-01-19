#include <stdio.h>
#include <stdlib.h>

void multiply(char *num1, char *num2);

int is_digit_string(char *str);

int main(int argc, char *argv[])
{
if (argc != 3)
{
printf("Error\n");
return (98);
}

if (!is_digit_string(argv[1]) || !is_digit_string(argv[2]))
{
printf("Error\n");
return (98);
}

multiply(argv[1], argv[2]);

return (0);
}

int is_digit_string(char *str)
{
while (*str)
{
if (*str < '0' || *str > '9')
{
return (0);
}
str++;
}

return (1);
}

void multiply(char *num1, char *num2)
{
int len1 = 0, len2 = 0, i, j, carry = 0;

while (num1[len1] != '\0')
len1++;

while (num2[len2] != '\0')
len2++;

int result[len1 + len2];

for (i = 0; i < len1 + len2; i++)
result[i] = 0;

for (i = 0; i < len1; i++)
{
carry = 0;
int digit1 = num1[len1 - i - 1] - '0';

for (j = 0; j < len2; j++)
{
int digit2 = num2[len2 - j - 1] - '0';
int temp = digit1 * digit2 + result[i + j] + carry;

result[i + j] = temp % 10;
carry = temp / 10;
}

result[i + len2] = carry;
}

int start_index = len1 + len2 - 1;
while (start_index >= 0 && result[start_index] == 0)
start_index--;

if (start_index == -1)
{
printf("0\n");
return;
}

for (; start_index >= 0; start_index--)
printf("%d", result[start_index]);

printf("\n");
}
