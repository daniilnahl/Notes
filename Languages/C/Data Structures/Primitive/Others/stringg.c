#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() { 

    /******
     * What is a string?
     * An array of characters that is null terminated("\0"at the end).
     * 
     */

    char nam1[] = "GAY"; //direct declaration
    char nam2[4]; //chracter declaration
    nam2[0] = 'G';
    nam2[1] = 'A';
    nam2[2] = 'Y';
    nam2[3] = '\0';













    //MEMORY ALLOCATION FOR STRING
    char* variable;
    /****What is this? 
    a pointer towards an adress in memory. Specfically, the first character of a sequence of characters. The address holds a sequence of characters which make up a string.
    To finalize a string, NULL TERMINATOR must be added to the end. ***/

    /**** How to use this? 
     * 1. Allocate memory for the string using malloc() or calloc().
     * 2. Assign values to the string.
     * 3. Add null terminator at the end of the string.
    */

    variable = malloc(17);

    for (int i = 0; i < 16; i++){ //ascii manipulation
        variable[i] = 'A' + i;
    }
    variable[16] = '\0'; // Null terminator to indicate the end of the string.
    printf("%s", variable);



/**** 
    FUNCTIONS

    In C, snprintf() function is a standard library function that is used to print the specified string till a specified length in the specified format. It is defined in the <stdio.h> header file.
    CAN USE snprintf to convert types to string: variable[i] = '\0';

    int len = snprintf(NULL, 0, "%f", sum); // Determine the required buffer size for the formatted string.
    char *result = malloc(len + 1); // Allocate memory on the heap for the formatted string, including null terminator.
    snprintf(result, len + 1, "%0.02f", sum); // Format the sum as a string with two decimal places and store it in the allocated memory.
    return result; // Return a pointer to the heap-allocated string.

    free(result); This should be called AFTER the string is no longer needed by the caller.
*****/
    char message[] = "Hello"; // Compiler adds a null terminator '\0'
    int length = strlen(message); // Use strlen from string.h to find the length

    printf("Message: %s\n", message); // Use %s format specifier to print a string
    printf("Length of message: %d\n", length);

    //strcpy()
    char destination[20];    // Destination buffer (must be large enough to hold the source string, including the null terminator)
    strcpy(destination, message);


    //strcat() string concatenation
    char str1[30] = "Programming in ";    
    char str2[] = "C";

    strcat(str1, str2);

    //strlen()
    int len = strlen(str1); //returns size of string

    //strcmp(str1, str2): compares two strings lexicographically -------------> the manner of a dictionary, or sorted alphabetically, where the order is determined by comparing characters sequentially from left to right
    int comparison = strcamp(str1, str2);
    return 0;
}


/**
 * Tip: 
 * When working with character arrays for strings in C, always ensure that you allocate enough memory to store the string, including the null terminator. 
 * Operations that modify strings (like strcpy or strcat) can lead to buffer overflows if the destination array is not large enough to hold the result. 
 * Consider using safer alternatives like strncpy or strncat if available, or carefully manage memory allocation.
 * 
 * Be mindful of scanf with %s: The %s format specifier in scanf reads characters until it encounters whitespace. Use field width limits (e.g., %49s) to prevent buffer overflows. Consider using safer alternatives like fgets for reading entire lines of input.
 * 
 * 
 */
