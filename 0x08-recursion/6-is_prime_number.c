#include "main.h"

/**
* is_prime_number - Checks if a number is a prime number.
* @n: The number to be checked.
*
* Return: 1 if the number is prime, 0 otherwise.
*/
int is_prime_number(int n)
{
if (n <= 1)
return (0);  /* 0 and 1 are not prime numbers */

return (check_prime(n, 2));
}

/**
* check_prime - Helper function to check if a number is prime recursively.
* @n: The number to be checked.
* @i: The current divisor to check.
*
* Return: 1 if the number is prime, 0 otherwise.
*/
int check_prime(int n, int i)
{
if (i * i > n)
return (1);  /* n is not divisible by any i, so it's prime */
if (n % i == 0)
return (0);  /* n is divisible by i, so it's not prime */
return (check_prime(n, i + 1));
}
