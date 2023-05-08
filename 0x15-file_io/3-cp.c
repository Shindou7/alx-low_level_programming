#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void close_the_file(int fd, char *file_to);
int main(int argc, char *argv[]);

/**
 * close_the_file - Closes file.
 * @fb: _open file.
 * @file_to: name of file.
 *
 * Return: nothing
 */
void close_the_file(int fd, char *file_to)
{
	int _close = close(fd);

	if (_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		dprintf(STDERR_FILENO, "Error closing file: %s\n", file_to);
		exit(100);
	}
}
/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of argument.
 * @argv: pointers to the arguments.
 * Return: 0 on success, otherwise exits with an error code.
 */
int main(int argc, char *argv[])
{
	char buffer[1024];
	ssize_t bytes_read, bytes_written;
	int fb_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fb_from = open(argv[1], O_RDONLY);
	if (fb_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close_the_file(fb_from, argv[1]);
		exit(99);
	}
	while ((bytes_read = read(fb_from, buffer, sizeof(buffer))) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close_the_file(fb_from, argv[1]);
			close_the_file(fd_to, argv[2]);
			exit(99);
		}
	}

	close_the_file(fb_from, argv[1]);
	close_the_file(fd_to, argv[2]);
	return (0);
}
