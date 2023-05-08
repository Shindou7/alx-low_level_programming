#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file.
 * @filename: the name offile.
 * @text_content:  content of the text.
 *
 * Return: Return: 1 on success and -1 on failure.
 * If filename is NULL return -1
 * If text_content is NULL, do not add anything to the file.
 * Return 1 if the file exists and -1 if the file does not exist or
 * if you do not have the required permissions to write the file
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int _open, _write, length = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		while (text_content[length] != '\0')
			length++;
	}
	_open = open(filename, O_WRONLY | O_APPEND);
	if (_open == -1)
		return (-1);

	if (text_content != NULL)
	{
		_write = write(_open, text_content, length);
		if (_write != length)
		{
			close(_open);
			return (-1);
		}
	}
	close(_open);
	return (1);
}
