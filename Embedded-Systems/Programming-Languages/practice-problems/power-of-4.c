// Given an integer, determine whether it is a power of four.

// Example 1:

// Input: n = 16
// Output: true
// Explanation: 16 = 4^2
// Example 2:

// Input: n = 5
// Output: false
// Example 3:

// Input: n = 1
// Output: true
// Explanation: 4^0 = 1

#include <stdbool.h>
//0000001 - 1     = 4^0
//0000100 - 4     = 4^1
//0010000 - 16    = 4^2
//1000000 - 64    = 4^3

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

bool isPowerOfFour(int num) {
    if (num < 0) return false;
    if (num == 1) return true;
    //value must be a power of 2 and follow the pattern that powers of 4s have 1s in every even position
    return (num & (num-1) == 0) && (num & 0x55555555);
}

// --- Test your solution ---
int main() {
    return 0;
}
