#include <stdio.h>
#include <limits.h>
//The goal was to get a complement of a number. Two edge cases were addressed at the start.
//The the program creates a mask of 1 bit and increases that mask in widht by 1 bit while maintainings its previous states thus resulting in an ever increasign
//1 bit mask, eg-> 1, 11, 111, 1111,...
//after loop is finish the num is XORed with mask-1 to get the complement of num. mask-1 is necessary to ensure that mask is of the same width as num.
int findComplement(int num) {
    if (num == 0) return 1;
    if (num == 1) return 0;

    unsigned int mask = 1;
    while (mask <= num){

        mask = mask | (mask << 1);    
    }
    num = num ^ (mask-1);
   
    return num;
}





int main(){
    // Test Case 1: A simple case
    int num1 = 5; // Binary: 101
    int expected1 = 2; // Binary: 010
    printf("Test 1: Input = %d, Output = %d, Expected = %d\n", num1, findComplement(num1), expected1);

    // Test Case 2: A single bit number
    int num2 = 1; // Binary: 1
    int expected2 = 0; // Binary: 0
    printf("Test 2: Input = %d, Output = %d, Expected = %d\n", num2, findComplement(num2), expected2);

    // Test Case 3: A number with alternating bits
    int num3 = 10; // Binary: 1010
    int expected3 = 5; // Binary: 0101
    printf("Test 3: Input = %d, Output = %d, Expected = %d\n", num3, findComplement(num3), expected3);

    // Test Case 4: A number that is a power of 2 minus 1 (all ones in binary)
    int num4 = 7; // Binary: 111
    int expected4 = 0; // Binary: 000
    printf("Test 4: Input = %d, Output = %d, Expected = %d\n", num4, findComplement(num4), expected4);
    int num5 = 16; // Binary: 10000
    int expected5 = 15; // Binary: 01111
    printf("Test 5: Input = %d, Output = %d, Expected = %d\n", num5, findComplement(num5), expected5);
    printf("\n\n\n");

    // --- Edge Cases ---
    printf("--- Edge Cases ---\n");

    // Test Case 6: Input is 0
    int num6 = 0; // Binary: 0
    int expected6 = 1; // Binary: 1
    printf("Test 6: Input = %d, Output = %d, Expected = %d\n", num6, findComplement(num6), expected6);

    // Test Case 7: Maximum integer value
    int num7 = INT_MAX; // Binary: 0111... (31 ones)
    int expected7 = 0;  // Binary: 0000...
    printf("Test 7: Input = %d, Output = %d, Expected = %d\n", num7, findComplement(num7), expected7);

    // Test Case 8: A large power of 2
    int num8 = 1073741824; // 2^30, Binary: 0100...0 (1 followed by 30 zeros)
    int expected8 = 1073741823; // Binary: 0011...1 (30 ones)
    printf("Test 8: Input = %d, Output = %d, Expected = %d\n", num8, findComplement(num8), expected8);

    return 0;
}
