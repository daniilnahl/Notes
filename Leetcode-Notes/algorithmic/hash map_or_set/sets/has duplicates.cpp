//Given an integer array nums, return true if any value appears more than once in the array, otherwise return false.

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> set;

        for(int i = 0; i < nums.size(); i++){
            if(set.count(nums[i])){ 
                return true;
            }else{
                set.insert(nums[i]);
            }
        }

        return false;
     }
};

/****** 
 * WHAT WAS CORE IDEA?
The core idea was to iterate through the whole all the nums and insert them into a has_set and before inserting a num into a set check if
its already in a set, if yes return true if not continue.
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used was hash map/set. 
 * 
 * Key concepts that I learned were:
 *  I learned how to intialize a set<> in c++; 
 *  I learned that in this program since I am specifically asked to return true when a num appears 2 times it means I can just use a set instead of a map 
 * which is more efficient than a map when using the count() function.
 * WHAT TIME COMPLEXITY?
 *  Time complexity is O (n) for n elements in the vector.
 * WHAT SPACE COMPLEXITY?
 *  Space complexity is O (n) for n elements in the hash set.

 * WHAT IS THE SUMMARY OF THIS?
 * In summary used a hash set as a temp container to count if a value has already appeared, if did return true if not return false.
 *  ***/

