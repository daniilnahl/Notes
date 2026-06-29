// Given an array of integers nums and an integer target, return the indices i and j such that nums[i] + nums[j] == target and i != j.
// You may assume that every input has exactly one pair of indices i and j that satisfy the condition.
// Return the answer with the smaller index first.





class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> map;
        for (int i = 0; i < nums.size(); i++){
            map[nums[i]] = i;
        }

        for (int j = 0; j < nums.size(); j++){
            int num_needed = target - nums[j];
            if (map.count(num_needed) && j != map[num_needed]){
                return {j, map[num_needed]};
                break;
            }
        }


        return {};
    }
};


/****** 
 * WHAT WAS CORE IDEA?
 The core idea was to use a hash map to store all the values from the vector. Then in a second loop get the difference between target and value at nums[i] and check if that difference exists in the hash map if yes return the vector if not continue.
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used was utilizing a hash map to store values and then checking for those values.
 * 
 * Key concepts that I learned were:
 *  I reinforced my understanding of using a hash map.
 * 
 * WHAT TIME COMPLEXITY?
 * The time complexity is no the best but its O ( n log n). I could improve it to O (n) with a single loop. So each loop is O (n) and within each loop I am interacting with hash map which gives O (log n) thus each loop is O (n log n) which together gives O 2 * (n log n), but I dont think the 2 * ... matters so just O (n log n).
 * WHAT SPACE COMPLEXITY?
 * Space complexity is O (n) for every n element i store in hash map.
 * WHAT IS THE SUMMARY OF THIS?
 *  In summary used a hash map to store values and then check if a needed value is within the hashmap.
 *  ***/

