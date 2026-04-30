// You are given an array of distinct integers nums and a target integer target. Your task is to return a list of all unique combinations of nums where the chosen numbers sum to target.
// The same number may be chosen from nums an unlimited number of times. Two combinations are the same if the frequency of each of the chosen numbers is the same, otherwise they are different.
// You may return the combinations in any order and the order of the numbers in each combination can be in any order.


//tutorial solution - utilizes backtracking, first time in 6 months I come across backtracking.

class Solution {
public:
    vector<vector<int>> combos;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        backtracking(target, 0, candidates, curr);

        return combos;
    }

    void backtracking(int target, int i, vector<int>& candidates, vector<int>& curr){
        if(target == 0){
            combos.push_back(curr);
            return;
        }

        if(target < 0 || i >= candidates.size()){
            return;
        }

        curr.push_back(candidates[i]);
        backtracking(target - candidates[i], i, candidates, curr);
        curr.pop_back();//removes last element added
        backtracking(target, i + 1, candidates, curr);
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
 * The DSA/PATTERN I used backtracking and depth first search.
 * 
 * Key concepts that I learned were:
 *  I became aware of backtracking algorithm, but I am still not 100% sure I understand how it works.
 * WHAT TIME COMPLEXITY?
 *  -
 * WHAT SPACE COMPLEXITY?
 *  - 
 *  ***/


