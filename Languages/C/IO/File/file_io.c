#include <stdio.h>

int main() {
    // Writing to a file
    FILE *outfile = fopen("example.txt", "w"); // Open in write mode
    if (outfile == NULL) {
        perror("Error opening output file");
        return 1;
    }
    fprintf(outfile, "This is some engineering.\n");
    fclose(outfile);
    printf("Data written to example.txt\n");

    // Reading from a file
    FILE *infile = fopen("example.txt", "r"); // Open in read mode
    if (infile == NULL) {
        perror("Error opening input file");
        return 1;
    }
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), infile) != NULL) {
        printf("Read from file: %s", buffer);
    }
    fclose(infile);

    return 0;
}
/*** 
Function Name	Parameters	                                                    Description	                                                                                        Typical Use
fopen()	        const char *filename, const char *mode	                        Opens a file for reading, writing, or appending. Returns a file pointer.	                        Establishing a connection to a file before performing any operations.
fclose()	    FILE *stream	                                                Closes an opened file, flushing any buffered output.	                                            Releasing the connection to a file after operations are complete, ensuring data is saved.

fprintf()	    FILE *stream, const char *format, ...	                        Writes formatted output to a file stream.	                                                        Writing text data to a file in a specific format (like printf but for files).
fscanf()	    FILE *stream, const char *format, ...	                        Reads formatted input from a file stream.	                                                        Reading text data from a file in a specific format (like scanf but for files).

fread()	        void *ptr, size_t size, size_t count, FILE *stream	            Reads a block of raw data (bytes) from a file stream.	                                            Reading binary data from a file (e.g., images, audio, data structures).
fwrite()	    const void *ptr, size_t size, size_t count, FILE *stream	    Writes a block of raw data (bytes) to a file stream.	                                            Writing binary data to a file (e.g., images, audio, data structures).

fgets()	        char *str, int n, FILE *stream	                                Reads at most one less than n characters from a file stream into str. Stops at a newline or EOF.	Reading a line of text from a file, including the newline character if present and fits within the buffer.
**/