class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1 && nums[0] == target) return 0;

        int left = 0; 
        int right = nums.size() - 1;

        while (left <= right){
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            else if (target > nums[mid]) left = mid + 1;
            else right = mid - 1;
        }
        
        return -1;
    }
};

/****** 
 * WHAT WAS CORE IDEA?
    Well the core idea was to implement basic binar search algorithm,=.
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used was binary search.
 * 
 * Key concepts that I learned were:
 *  Didn't learn anything new, but reinforced my understanding of binary search.
 * WHAT TIME COMPLEXITY?
 *  O(log n) time complexity, where n is the number of elements in the array.
 * WHAT SPACE COMPLEXITY?
 *   0(1) space complexity because using constant amount of space.
 * WHAT IS THE SUMMARY OF THIS?
 * In summary implemented a basic binary search.
 *  ***/

