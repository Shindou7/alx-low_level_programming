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

	if (!filename)
		return (-1);
	if (text_content != NULL)
	{
		while (text_content[length])
			length++;
	}

	_open = open(filename, O_CREAT | O_RDWR | O_WRONLY | O_TRUNC, 0600);

	_write = write(_open, text_content, length);

	if (_write == -1 || _open == -1)
		return (-1);

	close(_open);
	return (1);
}
