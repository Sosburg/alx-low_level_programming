#include "main.h"

/**
* read_textfile - Reads a text file and prints it to the POSIX standard output.
* @filename: The name of the file to read.
* @letters: The number of letters to read and print.
* Return: The actual number of letters it could read and print.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
int file_descriptor;
ssize_t read_count, write_count;
char *buffer;

if (filename == NULL)
return (0);

file_descriptor = open(filename, O_RDONLY);
if (file_descriptor == -1)
return (0);

buffer = malloc(sizeof(char) * letters);
if (buffer == NULL)
{
close(file_descriptor);
return (0);
}

read_count = read(file_descriptor, buffer, letters);
if (read_count == -1)
{
free(buffer);
close(file_descriptor);
return (0);
}

write_count = write(STDOUT_FILENO, buffer, read_count);
if (write_count == -1 || write_count != read_count)
{
free(buffer);
close(file_descriptor);
return (0);
}

free(buffer);
close(file_descriptor);
return (read_count);
}
