// Design a class to find the kth largest integer in a stream of values, including duplicates. E.g. the 2nd largest from [1, 2, 3, 3] is 3. The stream is not necessarily sorted.

// Implement the following methods:

// constructor(int k, int[] nums) Initializes the object given an integer k and the stream of integers nums.
// int add(int val) Adds the integer val to the stream and returns the kth largest integer in the stream.

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//1st attempt - didn't use heap - too slow
class KthLargest {
public:
    int k_;
    vector<int> nums_;
    KthLargest(int k, vector<int>& nums) : k_(k), nums_(nums) {}
    
    int add(int val) {
        nums_.push_back(val);
        sort(nums_.begin(), nums_.end(), greater<int>()); 

        for (int c : nums_){
            cout << c << endl;
        }

        cout << "END OF THIS LIST\n" << endl;

        return nums_[k_-1];
    }
};


//2nd attempt - works but only beats 20% in time complexity - using min_heap
class KthLargest {
public:
    int k_;
    priority_queue<int, std::vector<int>, std::greater<int>> min_heap; //min heap work around (c++ doesnt have built in min heap)
    KthLargest(int k, vector<int>& nums) : k_(k){
        for(int n : nums){
            min_heap.push(n);
        }

        while (min_heap.size() > k_){
            min_heap.pop();
        }
    }
    

    //In this case the root of min_heap is always the kth value because we have kth elements in the heap in ascending order, meaning that if reverse it and start      counting from the
    //end of the heap the last value will be kth largest value(which in this case is the root). 

    //this could be done with an array like I did it before, but it would require constantly sorting it which would make it less efficient.
    int add(int val) {
        min_heap.push(val);

        if (min_heap.size() > k_){
            min_heap.pop();
        }
        
        return min_heap.top();
    }
};

/****** 
 * WHAT WAS CORE IDEA?
 The core idea was to utilize min_heap, data structure that keeps its lowest value at its top. Due to this characterstic I made a kth sized min_heap and its top value is always the kth largest num.
  If min_heap is counted from end to beggining, the last value will be the kth largest value.
  
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used a min_heap.
 * 
 * Key concepts that I learned were:
 *  I learned that a min_heap is a data structure that stores values in ascending order.
 * 
 * WHAT TIME COMPLEXITY?
 * 0 (n log n) - for first function and O (log k) for second function. Accesing values from min heap costs O (log n).
 * 
 * WHAT SPACE COMPLEXITY?
 * O (log k) because only k amount of elements are stored in the heap.

 *  ***/

