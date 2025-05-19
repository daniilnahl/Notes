#include <stdio.h>

int main() {
    unsigned char a = 5;  // Binary: 00000101
    unsigned char b = 3;  // Binary: 00000011

    unsigned char and_result = a & b; // Binary: 00000001 (Decimal: 1)
    unsigned char or_result = a | b;  // Binary: 00000111 (Decimal: 7)
    unsigned char xor_result = a ^ b; // Binary: 00000110 (Decimal: 6)
    unsigned char not_result = ~a;  // Binary: 11111010 (Decimal: 250 for unsigned char)
    unsigned char left_shift = a << 2; // Binary: 00010100 (Decimal: 20)
    unsigned char right_shift = a >> 1; // Binary: 00000010 (Decimal: 2)

    printf("a = %d (Binary: %08b)\n", a, a); // Assuming %b is a hypothetical binary format specifier
    printf("b = %d (Binary: %08b)\n", b, b);

    printf("a & b = %d (Binary: %08b)\n", and_result, and_result);
    printf("a | b = %d (Binary: %08b)\n", or_result, or_result);
    printf("a ^ b = %d (Binary: %08b)\n", xor_result, xor_result);
    printf("~a  = %d (Binary: %08b)\n", not_result, not_result);
    printf("a << 2 = %d (Binary: %08b)\n", left_shift, left_shift);
    printf("a >> 1 = %d (Binary: %08b)\n", right_shift, right_shift);

    unsigned char status = 0; // Initially all bits are 0

    // Define masks for individual bits (assuming bit 0 is the least significant)
    unsigned char ERROR_FLAG = 0b00000001; // Mask for bit 0
    unsigned char WARNING_FLAG = 0b00000010; // Mask for bit 1
    unsigned char DATA_READY_FLAG = 0b00000100; // Mask for bit 2

    printf("Initial status: %d (Binary: %08b)\n", status, status);

    // Setting the ERROR_FLAG (bit 0)
    status = status | ERROR_FLAG;
    printf("Status after setting ERROR_FLAG: %d (Binary: %08b)\n", status, status);

    // Checking if the WARNING_FLAG (bit 1) is set
    if (status & WARNING_FLAG) {
        printf("Warning flag is set.\n");
    } else {
        printf("Warning flag is not set.\n");
    }

    // Setting the WARNING_FLAG (bit 1)
    status = status | WARNING_FLAG;
    printf("Status after setting WARNING_FLAG: %d (Binary: %08b)\n", status, status);

    // Checking if the WARNING_FLAG (bit 1) is set again
    if (status & WARNING_FLAG) {
        printf("Warning flag is set.\n");
    } else {
        printf("Warning flag is not set.\n");
    }

    // Clearing the ERROR_FLAG (bit 0)
    status = status & (~ERROR_FLAG);
    printf("Status after clearing ERROR_FLAG: %d (Binary: %08b)\n", status, status);

    //ANOTHER bits manipulation example

    unsigned char data = 0b10110010; // Example byte

    // Mask for the 5th bit (index 4)
    unsigned char BIT_5_MASK = 0b00010000;

    printf("Original data: %d (Binary: %08b)\n", data, data);

    // Check if the 5th bit is set
    if (data & BIT_5_MASK) {
        printf("The 5th bit is set (1).\n");
    } else {
        printf("The 5th bit is clear (0).\n");
    }

    // Set the 1st bit (index 0)
    unsigned char BIT_1_MASK = 0b00000001;
    data = data | BIT_1_MASK;
    printf("Data after setting 1st bit: %d (Binary: %08b)\n", data, data);

    // Clear the 6th bit (index 5)
    unsigned char BIT_6_MASK = 0b00100000;
    data = data & (~BIT_6_MASK);
    printf("Data after clearing 6th bit: %d (Binary: %08b)\n", data, data);

    // Toggle the 3rd bit (index 2)
    unsigned char BIT_3_MASK = 0b00000100;
    data = data ^ BIT_3_MASK;
    printf("Data after toggling 3rd bit: %d (Binary: %08b)\n", data, data);


    return 0;
}