#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: The name of  file
 * @letters: letters to reads & prints
 * Return: the actual number of letters it could read and print
 * if the file can not be opened or read, return 0
 * if filename is NULL return 0
 * if write fails or does not write the expected amount of bytes, return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t _read, _write, _open;
	char *buf;

	if (!filename)
		return (0);

	buf = malloc(sizeof(char *) * letters);

	if (!buf)
		return (0);

	_open = open(filename, O_RDONLY);
	_read = read(_open, buf, letters);
	_write = write(STDOUT_FILENO, buf, _read);

	if (_read == -1 || _write == -1 || _open == -1)
		return (0);

	free(buf);
	close(_open);

	return (_write);
}
