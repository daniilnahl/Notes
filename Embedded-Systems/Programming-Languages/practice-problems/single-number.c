
//USES XOR operation basically whenever there is a number this is XOR againt itself the output will be 0 and whenever XOR happens with a value and a 0 the value will be the output thus:
// [4, 1, 2, 1, 2]
// 4 ^ 1 = 100 ^ 001 = 101
// 5 ^ 2 = 101 ^ 010 = 111
// 7 ^ 1 = 111 ^ 001 = 110
// 6 ^ 2 = 110 ^ 010 = 100
// = 4 
// all the XOR operations cancel out the repeating numbers and only leave the number that has 1 occurence. 
#include <stdio.h>

int singleNumber(const int* nums, int numsSize) {
    int single_num = 0;

    for (size_t i=0; i < numsSize; i++){
        single_num = single_num ^ nums[i];
    }

    return single_num;
}

int main() {
    // Test Case 1
    int nums1[] = {2, 2, 1};
    int result1 = singleNumber(nums1, sizeof(nums1) / sizeof(nums1[0]));
    printf("Test Case 1: Input = {2, 2, 1}, Output = %d, Expected = 1\n", result1);

    // Test Case 2
    int nums2[] = {4, 1, 2, 1, 2};
    int result2 = singleNumber(nums2, sizeof(nums2) / sizeof(nums2[0]));
    printf("Test Case 2: Input = {4, 1, 2, 1, 2}, Output = %d, Expected = 4\n", result2);

    // Test Case 3
    int nums3[] = {1};
    int result3 = singleNumber(nums3, sizeof(nums3) / sizeof(nums3[0]));
    printf("Test Case 3: Input = {1}, Output = %d, Expected = 1\n", result3);

    return 0;
}