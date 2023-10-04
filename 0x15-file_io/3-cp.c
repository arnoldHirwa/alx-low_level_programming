#include "main.h"

/**
 * close_file - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * _copy - Copies the content of one file to another.
 * @file_from: The name of the source file.
 * @file_to: The name of the destination file.
 *
 * Description: This function copies the contents of the file specified
 *              by `file_from` to the file specified by `file_to`.
 */
void _copy(char *file_from, char *file_to)
{
	ssize_t bytes_written = 0, bytes_to_write, o_to, o_from, rb, w;
	char buffer[1024];

	o_from = open(file_from, O_RDONLY);
	if (o_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from %s\n", file_from);
		exit(98);
	}
	o_to = open(file_to, O_CREAT | O_RDWR | O_TRUNC, 0664);
	if (o_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		exit(99);
	}
	while ((rb = read(o_from, buffer, sizeof(buffer))) > 0)
	{
		if (rb + bytes_written > (long)sizeof(buffer))
		{
			bytes_to_write = sizeof(buffer) - bytes_written;
			w = write(o_to, buffer, bytes_to_write);
		}
		else
		{
			w = write(o_to, buffer, rb);
		}
		if (w == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			exit(99);
		}
		bytes_written += w;
	}
	close_file(o_from);
	close_file(o_to);
}

/**
 * main - Entry point, copies a file's content to another file.
 * @argc: The number of command-line arguments.
 * @av: An array of command-line argument strings.
 *
 * Description: This is the entry point of the program. It checks for the
 *              correct number of command-line arguments and then calls the
 *              _copy function to copy the content of one file to another.
 *
 * Return: 0 on success, or an error code on failure.
 */
int main(int argc, char **av)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	_copy(av[1], av[2]);
	return (0);
}
