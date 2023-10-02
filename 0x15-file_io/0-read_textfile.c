#include "main.h"
/**
 * read_textfile - a function that reads a text file and prints
 * it to the POSIX standard output.
 * @filename: file name.
 * @letters: numbers of letters printed.
 *
 * Return: returns the actual number of letters it could read and print
 * if the file can not be opened or read, return 0
 * if filename is NULL return 0
 * if write fails or does not write the expected amount of bytes, return 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
int file;
ssize_t read_file, write_file;
char *bufer;
if (!filename)
{
return (0);
}
file = open(filename, O_RDONLY);
if (file == -1)
{
return (0);
}
bufer = malloc(sizeof(char) * (letters));
if (!bufer)
{
return (0);
}
read_file = read(file, bufer, letters);
write_file = write(STDOUT_FILENO, bufer, read_file);
close(file);
free(bufer);
return (write_file);
}
