#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    //copy_if():  selectively copy elements from one range to another based on a given condition.
    vector<int> numbers = {1, 2, 3, 4, 5, 6};
    vector<int> evenNumbers;

    /***rearranges elements within a given range based on a specified condition (preserves the order of elements)
    How it works? It rearranges the elements so that all elements for which the predicate returns true are placed before all elements for which the predicate returns false.
    ***/
   vector<int> nums1 = {1, 0, 0, 0, 0, 2, 3, 4, 5, 6};
   for (int num : nums1) { //before
    cout << num << endl;
    }

    cout << endl;

   stable_partition(begin(nums1), end(nums1), [](int i){return i != 0;});

   for (int num : nums1) { //after
    cout << num << " ";
    }
    
    //string swap characters
    std::string s = "03/02";
    std::swap(s[1], s[4]);
    return 0;
}