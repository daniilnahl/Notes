// You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

// You should return the array of nums such that the the array follows the given conditions:

// Every consecutive pair of integers have opposite signs.
// For all integers with the same sign, the order in which they were present in nums is preserved.
// The rearranged array begins with a positive integer.
// Return the modified array after rearranging the elements to satisfy the aforementioned conditions.


//FIRST SOLUTION: inefficient, time complexity of O (n + n) and space complexity O (n * m)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] >= 0){
                pos.push_back(nums[i]);
            } else {
                neg.push_back(nums[i]);
            }
        }

        for (int j = 0; j < pos.size(); j++){
            res.push_back(pos[j]);
            res.push_back(neg[j]);
        }
        
    return res;
    }

    
};


//SECOND SOLUTION: efficient and actually using two pointers
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       int n = nums.size();
        vector<int> res(n, 0);

        int positive = 0, negative = 1;
        for (int i = 0; i < n; i++){
            if (nums[i] > 0){
                res[positive] = nums[i];
                positive+=2; 

            } else {
                res[negative] = nums[i];
                negative+=2;
            }
        }

    return res;
    }  
};

/****** 
 * WHAT WAS CORE IDEA?
The core idea in the more efficient solution wa first to create a vector of equal size to nums and initialize all values in it to 0.
Then using two pointers traverse nums. If a + value is encountered its added and its pointer is incremented by 2, so it leaves one space for the negative and then begins where the next positve would go. 
Same process applies to negative pointer. Basically, the pointers are just skipping each other and leave spaces for others values by the increment of 2.
Even if nums is something like [1,2,3,4,5,6,-1,-2,-3,-4,-5,-6] the algo will work.
it will first put the + values in their correct places: [1,0,2,0,3,0...] then the negative pointer will replace all 0s with the negative values.
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used was two pointers.
 * Key concepts that I learned were:
 *  Key concept that I learned is that I can initialize a vector and fill it up with values by doing {name}({size}, {value});
 * WHAT TIME COMPLEXITY?
 *  Time compleixty is O (n) because traversing the loop only once.
 * WHAT SPACE COMPLEXITY?
 * Space complexity is O (n) because creating a vector of n size, n being size of nums.
 *  ***/

