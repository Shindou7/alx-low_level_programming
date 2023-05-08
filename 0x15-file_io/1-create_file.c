#include "main.h"

/**
 * create_file - creates a file.
 * @filename: the name of file.
 * @text_content: content of the text.
 * Return: if the file already exists, truncate it
 * ........if filename is NULL return -1
 * ........if text_content is NULL create an empty file.
 */
int create_file(const char *filename, char *text_content)
{
	int _open, _write, length = 0;

/** The created file must have those permissions: rw------- */
	mode_t mode = S_IRUSR | S_IWUSR;

	if (!filename)
		return (-1);
	if (text_content != NULL)
	{
		length = 0;
		while (text_content[length])
			length++;
	}

	_open = open(filename, O_WRONLY | O_RDWR | O_CREAT | O_TRUNC, mode);
	if (_open == -1)
		return (-1);

	_write = write(_open, text_content, length);
	if (_write == -1)
	{
		close(_open);
		return (-1);
	}
	close(_open);
	return (1);
}
