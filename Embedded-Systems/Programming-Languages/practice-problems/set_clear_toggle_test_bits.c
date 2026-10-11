
#include <stdbool.h>

// x is the register
// bit is the location of the bit we will be operating on
unsigned setBit(unsigned x, unsigned bit) {
    x |= (1u << bit);
    return x;

}

unsigned clearBit(unsigned x, unsigned bit) {
    x &= ~(1u << bit);
    return x;
}

unsigned toggleBit(unsigned x, unsigned bit) {
    x ^= (1u << bit);
    return x;
}

bool testBit(unsigned x, unsigned bit) {
    return x & (1u << bit);
}

/****** 
 * WHAT WAS CORE IDEA?
 
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used 
 * 
 * Key concepts that I learned were:
 *  
 * WHAT TIME COMPLEXITY?
 * 
 * WHAT SPACE COMPLEXITY?
 * 
 * WHAT IS THE SUMMARY OF THIS?
 * 
 *  ***/

