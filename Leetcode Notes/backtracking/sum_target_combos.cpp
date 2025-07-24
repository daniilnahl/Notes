// You are given an array of distinct integers nums and a target integer target. Your task is to return a list of all unique combinations of nums where the chosen numbers sum to target.
// The same number may be chosen from nums an unlimited number of times. Two combinations are the same if the frequency of each of the chosen numbers is the same, otherwise they are different.
// You may return the combinations in any order and the order of the numbers in each combination can be in any order.


//tutorial solution - utilizes backtracking, first time in 6 months I come across backtracking.

class Solution {
public:
    vector<vector<int>> combos;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> current;
        backtracking_with_depth_first_search(nums, target, current, 0);
        
        return combos;
    }

    void backtracking_with_depth_first_search(vector<int>& nums, int target, vector<int>& current, int i){
        if (target == 0){ //catches when the nums in current are summing to target
            combos.push_back(current); //store in combos vector and reset
            return;
        }

        if (target < 0 || i >= nums.size()){//catches when the sum of nums in current are over what the target is or when index gets to max index of nums
            return;//reset
        }

        current.push_back(nums[i]);//collects a number
        backtracking_with_depth_first_search(nums, target - nums[i], current, i); //subtracts that number from target and recursively iterates until target is 0 (means found a combo) or when target gets < 0 (means not a combo).
        current.pop_back(); //resets 
        backtracking_with_depth_first_search(nums, target, current, i+1); //starts a new "branch" but with eliminating a value from nums to prevent premutation (basically combos with the same numbers but in different order).
    }
};

/****** 
 * WHAT WAS CORE IDEA?
The core idea was to utlize backtracking algorithm method with depth first approach to find 
combos of numbers that sum up to target without having premutations (combos that have same numbers but in different order).

Basically imagine an upside down tree where we are going into two branches and then each branch splits into two.
Left split maintains the starting nums and adds nums[i] to a temp vector to track what numbers we have went through. Right branch resets the same process but with  i + 1, 
eliminating one of the values from original list to prevent premutations. It keeps recursively going until the target reaches or goes over 0. How is that done?
Its done by subtracting nums[i] from target in each recursive pass. Whenever target reaches 0 that temp vector that was tracking added nums[i] is added to solution vector.
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used backtracking and depth first.
 * 
 * Key concepts that I learned were:
 *  I became aware of backtracking algorithm, but I am still not 100% sure I understand how it works.
 * WHAT TIME COMPLEXITY?
 *  -
 * WHAT SPACE COMPLEXITY?
 *  - 
 *  ***/


