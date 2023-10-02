#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

ssize_t read_textfile(const char *filename, size_t letters) {
    if (filename == NULL) {
        return 0;
    }

    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        return 0; // Failed to open the file
    }

    char *buffer = (char *)malloc(sizeof(char) * (letters + 1));
    if (buffer == NULL) {
        close(fd);
        return 0; // Memory allocation failed
    }

    ssize_t bytes_read = read(fd, buffer, letters);
    if (bytes_read == -1) {
        close(fd);
        free(buffer);
        return 0; // Failed to read the file
    }

    buffer[bytes_read] = '\0'; // Null-terminate the string

    ssize_t bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
    if (bytes_written == -1 || (size_t)bytes_written != bytes_read) {
        close(fd);
        free(buffer);
        return 0; // Failed to write or didn't write the expected amount of bytes
    }

    close(fd);
    free(buffer);

    return bytes_read;
}

int main() {
    const char *filename = "example.txt"; // Replace with the name of your text file
    size_t letters_to_read = 100; // Replace with the number of letters you want to read

    ssize_t letters_read = read_textfile(filename, letters_to_read);
    if (letters_read == 0) {
        printf("Error: Unable to read or print the file.\n");
    } else {
        printf("Successfully read and printed %zd letters from the file.\n", letters_read);
    }

    return 0;
}
