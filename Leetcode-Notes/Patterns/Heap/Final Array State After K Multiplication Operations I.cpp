// You are given an integer array nums, an integer k, and an integer multiplier.

// You need to perform k operations on nums. In each operation:

// Find the minimum value x in nums. If there are multiple occurrences of the minimum value, select the one that appears first.
// Replace the selected minimum value x with x * multiplier.
// Return an integer array denoting the final state of nums after performing all k operations.


//BRUTE FORCE APPROACH: time complexity is O(n^2) NOT GOOD
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int index = 101, lowest_num = 1000000001, i = 0;
        //priority_queue<int, vector<int>, greater<int>> heap; 
        
        while (i < k){
            for (int j = 0; j < nums.size(); j++){
                if (nums[j] < lowest_num){
                    lowest_num = nums[j];
                    index = j;
                }
            }
            nums[index] = lowest_num * multiplier;            
            index = 101;
            lowest_num = 1000000001;
            i++;
        }
        
        return nums;
    }
};

//HEAP APPROACH
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<pair<int, int>> heap;
        for (int i = 0; i < nums.size(); i++){
            heap.push_back({nums[i], i});
        }

        make_heap(heap.begin(), heap.end(), greater<>()); //heapifies the vector to make it min-heap

        while(k--){
            pop_heap(heap.begin(), heap.end(), greater<>()); //moves smallest element to the end of vector and rearranges everything
            auto [value, i] = heap.back();
            heap.pop_back();

            nums[i] *= multiplier;
            heap.push_back({nums[i], i});
            push_heap(heap.begin(), heap.end(), greater<>()); //
        }

        return nums;
    }
};

/****** 
 * WHAT WAS CORE IDEA?
 The core idea was to create a vector of pairs and fill it up with values and their indices, so after the values would me modified I know where the value must go.
 Then heapify the vector go into a loop where each iteration the smallest value is moved to the end of heapfied vector and is modified by the multiplier. Last 
 function restores the heapified order after adding new element.
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used was using a priority queue.
 * 
 * Key concepts that I learned were:
 *  I can heapify a vector using STL functions.
 * 
 * WHAT TIME COMPLEXITY?
 *  Time complexity is  O (N + k * log N)
 * WHAT SPACE COMPLEXITY?
 *  Space complexity is O (log N)

 *  ***/

