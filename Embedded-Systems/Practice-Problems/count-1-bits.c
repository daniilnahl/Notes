#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

//APPROACH 1: no bit manipulation just plain simple algorithm
int hammingWeight_1(uint32_t n) {
    int count = 0;
    while (n != 0){
        if (n % 2 == 1) count++; 
        n = n/2;
    }

    return count;
}

/**APPROACH 2: bit manipulation
* Uses a bit manipulation rule created by Brian Kernighan
* Eg:
* 1000 (-1) = 0111
* increment by 1
* 1000 & 0111 = 0000
* return 1
* bit manipulation trick
**/

int hammingWeight(uint32_t n) {
    int count = 0;
    while (n>0){
        n = n & (n-1);
        count++;
    }

    return count;
}

//--- Test your solution ---
int main() {
    int nums[] = {11, 128, 2147483645, 3, 16};
    int bit_counts[] = {3, 1, 30, 2, 1};
    for (size_t i = 0; i < sizeof(nums)/sizeof(nums[0]); i++){
        int result = hammingWeight(nums[i]);
        if (result == bit_counts[i]) printf("Passed test case %zu\n", i);
        else printf("Failed test case %zu\n", i);
    }

    return 0;
}