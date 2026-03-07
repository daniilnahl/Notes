#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        //max pair is the sum val of a pair and is largest out of all the pairs.
        //basically find the pairs that give the smallest sum. Create pairs that have 
        //the smallest possible sum and from those find the largest sum.

        sort(nums.begin(), nums.end());

        int left = 0, right = nums.size()-1, largest_sum = 0, sum;

        while (left < right){ //no need for equal 
            sum = nums[left] + nums[right];
            if (largest_sum < sum) largest_sum = sum;
            left++;
            right--;
        }

        return largest_sum;
    }
};

int main(){
    
    return 0;
}


/****** 
 * WHAT WAS CORE IDEA?
 The core idea was to find 'minimized pairs' and from those find the greatest sum of pair values. This basically means
 find a way to pair the largest values with the smallest values and from those pairs find the pair that gives the greatest sum.
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used was two pointers when I was navagating the sorted array. 
 * Key concepts that I reinforced was using two pointers method of solving leetcode.
 *  
 * WHAT TIME COMPLEXITY? Time complexity is O (n log n + n) but only the slowest part is left thus it is O (n log n)
 * WHAT SPACE COMPLEXITY? The space complexity is O(1). The vector sort() is done 'in place' which means its O(1).
 *  ***/

