/***
 * What is uint8_t?
    A type alias for an unsigned integer that is exactly 8 bits wide.
    Defined in the <stdint.h> header file,  stands for "unsigned integer,", "8" indicates the number of bits, can hold values ranging from 0 to 255 (2^8 - 1).
    Guarantees that 8 bits of memory are used.

 * How does uint8_t work?
    uint8_t holds a sequence of 8 bits of the value its assigned, so it can hold a float, an int or a char. (Stores binary representation of a the vale assigned to it). 
 
    * When to use?
    Working with binary data; Storing small, non-negative integers; Optimizing memory usage;
    When writing code that needs to run on different architectures; When working with cryptographic functions:
****/

#include <stdio.h>
#include <stdint.h>

void printBinary(uint8_t value) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
    }
    printf("\n");
}
//converts '1' to 1 in uint8_t
//here you are not subtracting the characters but their ASCII values
//ASCII value of '0' is 48 and '1' is 49
//returns the numerical difference between the ASCII value. '0' is 48 and '1' is 49, 49 - 48 = 1
uint8_t char_to_int(uint8_t character) {
    return character - '0';
}

int main() {
    uint8_t integer_one = 9;
    uint8_t character_one = '9';
    uint8_t charaa = char_to_int(character_one);

    printf("Integer 9: %u, Binary: ", integer_one);
    printBinary(integer_one);

    printf("Character 9: %u, Binary: ", character_one);
    printBinary(character_one);

    printf("Integer 9 after conversion: %u, Binary: ", charaa);
    printBinary(charaa);


    return 0;
}