// You are given a 0-indexed integer array nums and a target element target.
// A target index is an index i such that nums[i] == target.
// Return a list of the target indices of nums after sorting nums in non-decreasing order. If there are no target indices, return an empty list. The returned list must be sorted in increasing order.

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1, mid;
        vector<int> res;

        while (left <= right){
            mid = (left + right) / 2;
            if (nums[mid] == target){
                res.push_back(mid); 
                for (int j = mid - 1; j >= 0; j--){
                    if (nums[j] == target){
                        res.push_back(j);
                    }
                }

                for (int i = mid + 1; i < nums.size(); i++){
                    if (nums[i] == target){
                        res.push_back(i);
                    }
                }

                break;               
            }
            else if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }

        sort(res.begin(), res.end());
        return res;
    }
};

/****** 
 * WHAT WAS CORE IDEA?
 The core idea was to first sort the nums, then using binary search find where target element/s are and from there go left and right collecting all the indices of tha target number.
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used was modified binary search.
 * WHAT TIME COMPLEXITY? it was O (n log n) for the n elements sorted using sort(). 
 * WHAT SPACE COMPLEXITY? It was O (n) for the n elements added to res vector.
 *  ***/

