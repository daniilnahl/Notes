/*
Implement a function that computes the two's complement (additive inverse) of a 
32-bit integer using only bitwise operators.


INPUTS:
1. Input is a 32-bit unsigned integer.
2. Allowed operators: &, |, ^, ~, <<, >>.
3. Prohibited operators: +, -, *, /, %, ++, --.
4. No standard library arithmetic functions.

OUTPUTS:
1. Return the 32-bit two's complement of the input.
2. The result must be correct modulo \(2^{32}\).
3. Handle zero and 0x80000000 correctly.
*/

#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
//The core idea is to create a set bit mask for every bit start with the LS bit.
//then use such a mask and XOR it with input value to inform what bits to flip starting with after the right most
//LS bit. So the mask only XORs every bit after LSB.

uint32_t twos_complement(uint32_t num){
    uint32_t mask = num;      

    mask |= mask << 1;        // spread set bits 1 position left
    mask |= mask << 2;        // spread set bits 2 more positions left
    mask |= mask << 4;        // spread set bits 4 more positions left
    mask |= mask << 8;        // spread set bits 8 more positions left
    mask |= mask << 16;       // spread set bits 16 more positions left

    // shift mask to preserve the lowest set bit and trailing zeros
    // XOR flips all higher bits, producing the two's complement
    return num ^ (mask << 1);
}

int main(void) {
    struct {
        uint32_t input;
        uint32_t expected;
    } tests[] = {
        {0x00000000, 0x00000000}, // Zero
        {0x00000001, 0xFFFFFFFF}, // One
        {0x00000002, 0xFFFFFFFE}, // Two
        {0x0000002C, 0xFFFFFFD4}, // 44
        {0x80000000, 0x80000000}, // Minimum signed 32-bit value
        {0x7FFFFFFF, 0x80000001}, // Maximum signed 32-bit value
        {0xFFFFFFFF, 0x00000001}, // All bits set
    };

    int failed = 0;
    size_t count = sizeof(tests) / sizeof(tests[0]);

    for (size_t i = 0; i < count; i++) {
        uint32_t result = twos_complement(tests[i].input);

        if (result == tests[i].expected) {
            printf("Test %zu: PASS\n", i + 1);
        } else {
            printf("Test %zu: FAIL (Got: 0x%08X, Expected: 0x%08X)\n",
                   i + 1,
                   (unsigned int)result,
                   (unsigned int)tests[i].expected);
            failed++;
        }
    }

    printf("\nResults: %zu/%zu passed\n", count - failed, count);

    return failed ? 1 : 0;
}