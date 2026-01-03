// You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.
// A row i is weaker than a row j if one of the following is true:
// The number of soldiers in row i is less than the number of soldiers in row j.
// Both rows have the same number of soldiers and i < j.
// Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.

 class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        std::priority_queue<std::pair<int, int>> maxheap; 
        std::vector<int> res;
        int count = 0, level = 0;

        for (auto row : mat){
            for (int i = 0; i < row.size(); i++){
                if (row[i] == 0) break;
                count++;
            }

            if(k > maxheap.size()){
                maxheap.push({count,level});
            }else{
                auto top = maxheap.top();
                if(count < top.first || (count == top.first && level < top.second)){
                    maxheap.pop();
                    maxheap.push({count,level});
                }
            }
            level++;
            count=0;
        }
    
        while(!maxheap.empty()){
            auto mop = maxheap.top();
            maxheap.pop();
            res.push_back(mop.second);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};

/****** 
 * WHAT WAS CORE IDEA?
 The core idea was to loop through every row in matrix and count how many soliders each one had. Push a pair of solider count and row # into a heap without a check until heap's size reaches k. Then 
 given compare row j with whatever row is at the top of heap using provided constraints, if passes constraints add the new row and pop the old one. Repeat the process for all row. Afterwards, loop through heap
 adding the rows' # into a vector. Reverse that vector and return.
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used was utilizing a heap to store K amount of rows with the least amount of soliders.
 * Key concepts that I reinforced were utilizing a heap for K amount type problem and my understanding of heap.
 *  
 * WHAT TIME COMPLEXITY?
 * Time Complexity is O (N * M + N * log K) N for amount of rows, M for elements in each row, K for k elements in a heap.
 * WHAT SPACE COMPLEXITY?
 * Space complexity is O (K) N for amount of K elements stored in heap and vector
 * 
 * WHAT IS THE SUMMARY OF THIS?
 * 
 *  ***/

