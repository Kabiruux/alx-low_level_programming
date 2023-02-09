#include "main.h"

/**
 * append_text_to_file - Appends text to a file if it exists
 * @filename: The name of the file to be created/filled
 * @text_content: The text to put into the new file
 *
 * Return: 1 for success, -1 for fail
 */
int append_text_to_file(const char *filename, char *text_content)
{
	ssize_t fd, wr_res;
	int len;

	if (!filename)
		return (-1);

	fd = open(filename, O_RDWR | O_APPEND);
	if (fd < 0)
		return (-1);

	if (!text_content)
	{
		close(fd);
		return (1);
	}

	for (len = 0; text_content[len]; len++)
		;

	wr_res = write(fd, text_content, len);
	if (wr_res < 0 || wr_res != len)
		return (-1);

	if (close(fd))
		return (-1);

	return (1);
}
