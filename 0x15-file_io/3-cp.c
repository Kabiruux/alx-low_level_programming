#include "main.h"

/**
 * main - Copies the data from one file to another
 * @argc: The number of arguments passed, including the command
 * @argv: Pointer to the first pointer in an array of pointers each pointing
 * to the first character in a string containing each argument, including the
 * command
 *
 * Return: 1 for success
 */
int main(int argc, char **argv)
{
	ssize_t fd_to, fd_from;
	ssize_t read_res, write_res;
	char buffer[1024];

	if (argc != 3)
		printerr("Usage: cp file_from file_to", "", 97);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to < 0)
		printerr("Error: Can't write to ", argv[2], 99);

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from < 0)
		printerr("Error: Can't read from file ", argv[1], 98);

	do {
		read_res = read(fd_from, buffer, 1024);
		if (read_res < 0)
			printerr("Error: Can't read from file ", argv[1], 98);

		write_res = write(fd_to, buffer, read_res);
		if (write_res < 0 || write_res != read_res)
			printerr("Error: Can't write to ", argv[2], 99);
	} while (write_res == 1024);

	if (close(fd_from))
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", (int)fd_from);
		exit(100);
	}

	if (close(fd_to))
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", (int)fd_to);
		exit(100);
	}

	return (0);
}

/**
 * printerr - Prints an error and exits with a certain status
 * @msg: The message to be printed with the error
 * @file: String to be printed at the end of the error
 * @status: Status to be exited with
 */
void printerr(char *msg, char *file, int status)
{
	dprintf(STDERR_FILENO, "%s%s\n", msg, file);

	exit(status);
}
