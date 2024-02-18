#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

void handle_error(int code, const char *message, int fd1, int fd2);

/**
* main - Copies the content of one file to another with specified requirements.
* @argc: Number of arguments.
* @argv: Array of argument strings.
*
* Return: 0 on success, or appropriate exit code on failure.
*/
int main(int argc, char *argv[])
{
int fd_from, fd_to, read_count, write_count;
char buffer[BUFFER_SIZE];

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
exit(97);
}

fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
{
handle_error(98, "Error: Can't read from file %s\n", fd_from, -1);
}

fd_to = open(argv[2],
O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
if (fd_to == -1)
{
handle_error(99, "Error: Can't write to file %s\n", fd_from, fd_to);
}

do {
read_count = read(fd_from, buffer, BUFFER_SIZE);
if (read_count == -1)
{
handle_error(98, "Error: Can't read from file %s\n", fd_from, fd_to);
}

write_count = write(fd_to, buffer, read_count);
if (write_count == -1 || write_count != read_count)
{
handle_error(99, "Error: Can't write to file %s\n", fd_from, fd_to);
}
} while (read_count > 0);

if (close(fd_from) == -1 || close(fd_to) == -1)
{
handle_error(100, "Error: Can't close fd %d\n", fd_from, fd_to);
}

return (0);
}

/**
* handle_error - Handles errors and exits the program.
* @code: Exit code.
* @message: Error message format.
* @fd1: File descriptor 1 (if applicable).
* @fd2: File descriptor 2 (if applicable).
*/
void handle_error(int code, const char *message, int fd1, int fd2)
{
dprintf(STDERR_FILENO, message, fd1, fd2);
if (fd1 != -1)
close(fd1);
if (fd2 != -1)
close(fd2);
exit(code);
}
