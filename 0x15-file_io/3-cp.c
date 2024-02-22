#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

void handle_error(int code,
const char *message, const char *file_name1, const char *file_name2);

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
handle_error(98, "Error: Can't read from file %s\n", argv[1], argv[2]);
}

fd_to = open(argv[2],
O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
if (fd_to == -1)
{
handle_error(99, "Error: Can't write to file %s\n", argv[1], argv[2]);
}

do {
read_count = read(fd_from, buffer, BUFFER_SIZE);
if (read_count == -1)
{
handle_error(98, "Error: Can't read from file %s\n", argv[1], argv[2]);
}

write_count = write(fd_to, buffer, read_count);
if (write_count == -1 || write_count != read_count)
{
handle_error(99, "Error: Can't write to file %s\n", argv[1], argv[2]);
}
} while (read_count > 0);


if (close(fd_from) == -1 || close(fd_to) == -1)
{
char fd_from_str[12];
char fd_to_str[12];
sprintf(fd_from_str, "%d", fd_from);
sprintf(fd_to_str, "%d", fd_to);
handle_error(100, "Error: Can't close fd %s\n", fd_from_str, fd_to_str);
}

return (0);
}

/**
* handle_error - Handles errors and exits the program.
* @code: Exit code.
* @message: Error message format.
* @file_name1: File name 1 (if applicable).
* @file_name2: File name 2 (if applicable).
*/
void handle_error(int code,
const char *message, const char *file_name1, const char *file_name2)
{
dprintf(STDERR_FILENO, message, file_name1);
if (file_name2 != NULL)
{
dprintf(STDERR_FILENO, " %s\n", file_name2);
}
else
{
dprintf(STDERR_FILENO, "\n");
}
exit(code);
}

