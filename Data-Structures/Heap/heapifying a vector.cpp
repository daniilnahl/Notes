#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <iostream>
using namespace std;

/***
 * make_heap() - tranforms/intializes a heap from existing collection of values.
 * push_heap() is used to add a new element to an existing heap while preserving the heap property.
 * pop_heap() is used to remove the root element (the maximum or minimum) from a heap while maintaining the heap property.
 */

int main() {
std::vector<int> nums = {4, 1, 7, 3, 8, 2, 6};
    
    // 1. make_heap: Converts the vector into a max-heap.
    // The largest element (8) will be at the front.
    std::make_heap(nums.begin(), nums.end());
    std::cout << "After make_heap (max-heap): ";
    for (int n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    // Expected output: After make_heap (max-heap): 8 4 7 3 1 2 6 

    // 2. pop_heap: Moves the largest element to the end of the vector.
    std::pop_heap(nums.begin(), nums.end());
    std::cout << "After pop_heap (8 is now at the end): ";
    for (int n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    // Expected output: After pop_heap (8 is now at the end): 7 4 6 3 1 2 8 

    // Remove the element that was popped to the back.
    nums.pop_back(); 
    std::cout << "After pop_back: ";
    for (int n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    // Expected output: After pop_back: 7 4 6 3 1 2 

    // 3. push_heap: Add a new element and restore the heap property.
    nums.push_back(9);
    std::cout << "After push_back (9 is at the end): ";
    for (int n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    // Expected output: After push_back (9 is at the end): 7 4 6 3 1 2 9 

    std::push_heap(nums.begin(), nums.end());
    std::cout << "After push_heap (9 is now at the root): ";
    for (int n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    // Expected output: After push_heap (9 is now at the root): 9 7 6 3 1 2 4 

    return 0; 
}