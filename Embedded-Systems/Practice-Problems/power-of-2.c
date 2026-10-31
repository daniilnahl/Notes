/****** 
 * WHAT WAS CORE IDEA?
 
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used was a simple bit pattern where for a value to be a power of 2 you must subtract a 1 from it and then AND those 2 values and those values will never have a 1 bit in the same postion. 
 * 
 * Key concepts that I learned were: the trick of finding a value thats a power of 2.
 *  
 * WHAT TIME COMPLEXITY? O(1)
 * 
 * WHAT SPACE COMPLEXITY? O(1)
 * 
 *  ***/

#include <stdbool.h>

bool isPowerOfTwo(int n) {
    if (n < 0) return false;
    if (n==1) return true;
    return ((n & (n-1)) == 0);
}