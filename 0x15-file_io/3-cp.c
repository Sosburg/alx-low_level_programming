#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void print_error_and_exit(int code, const char *message,
const char *file_name, int fd);

/**
* main - Copies the content of one file to another.
* @argc: Number of arguments.
* @argv: Array of arguments.
* Return: 0 on success, appropriate exit code on failure.
*/
int main(int argc, char *argv[])
{
int fd_from, fd_to;
ssize_t read_count, write_count;
char buffer[BUFFER_SIZE];

if (argc != 3)
{
dprintf(2, "Usage: %s file_from file_to\n", argv[0]);
exit(97);
}

fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
print_error_and_exit(98, "Error: Can't read from file",
argv[1], 0);

fd_to = open(argv[2],
O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
if (fd_to == -1)
print_error_and_exit(99, "Error: Can't write to file", argv[2], fd_from);

do {
read_count = read(fd_from, buffer, BUFFER_SIZE);
if (read_count == -1)
print_error_and_exit(98, "Error: Can't read from file", argv[1], fd_from);

write_count = write(fd_to, buffer, read_count);
if (write_count == -1)
print_error_and_exit(99, "Error: Can't write to file", argv[2], fd_from);
} while (read_count > 0);

if (close(fd_from) == -1)
print_error_and_exit(100, "Error: Can't close fd", argv[1], fd_from);

if (close(fd_to) == -1)
print_error_and_exit(100, "Error: Can't close fd", argv[2], fd_to);

return (0);
}

/**
* print_error_and_exit - Prints an error message and exits the program.
* @code: Exit code.
* @message: Error message.
* @file_name: File name.
* @fd: File descriptor.
*/
void print_error_and_exit(int code,
const char *message, const char *file_name, int fd)
{
dprintf(2, "%s %s", message, file_name);
if (fd != 0)
close(fd);
exit(code);
}

