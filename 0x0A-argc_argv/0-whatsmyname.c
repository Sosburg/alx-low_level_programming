#include <stdio.h>

/**
 *  * print_program_name - Prints the name of the program
 *   * @name: Name of the program
 *    */
void print_program_name(char *name)
{
	    /* Print the name of the program followed by a new line */
	    while (*name != '\0')
		        {
				        _putchar(*name);
					        name++;
						    }
	        _putchar('\n');
}
