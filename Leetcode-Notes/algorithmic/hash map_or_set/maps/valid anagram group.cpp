//Given an array of strings strs, group the anagrams together. You can return the answer in any order.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        for(auto& A : strs){//making a reference of the value at that address instead of copying it, saves memory
            string S = A;
            sort(S.begin(), S.end());
            anagrams[S].push_back(A);
        }

        vector<vector<string>> groups;

        for (auto& pair : anagrams){ //making a reference of the value at that address instead of copying it, saves memory
            groups.push_back(pair.second);
        }

        return groups;
    }
};


/****** 
 * WHAT WAS CORE IDEA?
 The core idea was to use a hash map with a pair of string and vector to create groups of anagrams. The concept is that a string, 'A' is sorted in alphabetical order, which we call 'S' and then a key is created/accessed at S at which we push its unsorted version A. Repeat the process
 for all elements in strs. This works because all the anagrams in whatever order they would be would always become the S and their A would be put into the vector of that key, creating sublists of anagrams.

 Then a basic for loop to output in vector<vector<>> format.
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used hash map.
 * 
 * Key concepts that I learned were:
 *  - I learned that I can sort a string by calling  sort({var name}.begin(), {var name}.end()); in alphabetical order
 * 
 * WHAT TIME COMPLEXITY?
 *  Time complexity in total is O (n * k log k). k log k comes from sorting the strings and n comes from the original loop where I iterate all the elements. Second loop is O(n) since its a loop of all elements and the insert/access within it is O(1). So, n * k log k + n = O (n * k log k).
 * WHAT SPACE COMPLEXITY?
 * Space complexity is O (m * n). M for hashmap and n for double vector.
 *  ***/

