// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
// Return the sorted string. If there are multiple answers, return any of them.

//FIRST APPROACH: VERY SLOW -> Time complexity is O (N log N) which comes from sort() since it is the slowest part of the algo.
class Solution {
public:
    string frequencySort(string s) {
        sort(s.begin(), s.end());
        int count = 1, i;
        char c;
        string res;

        priority_queue<pair<int, char>> minheap;
        for (i = 1; i < s.size(); i++){
            c = s[i-1];
            if (s[i] != c){
                minheap.push({count, c});
                count = 1;
            }else{
                count++;
            }
        }

        c = s[i-1];
        if (s[i] != c){
            minheap.push({count, c});
            count = 1;
        }else{
            count++;
        }

        while(!minheap.empty()){
            auto top = minheap.top();
            minheap.pop();
            res.append(top.first, top.second);
        }
        
        return res;
    }
};

/****** 
 * WHAT WAS CORE IDEA?
 Core idea was to first sort a string so all repeating chracters are placed together making them easier to count. Then store all of them in a maxheap pair(ignore the var name, i was too lazy to change it).
In next loop add the characters * their frequency to a solution string and return it.
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used I was a heap, in this instance max heap.
 * Key concepts that I reinforced was my understanding of how a hepa works.
 *  
 * WHAT TIME COMPLEXITY?
 * Time complexity is O (n log n + n + log n), but because n log n is the longest here, its just n log n.
 * WHAT SPACE COMPLEXITY?
 * Space complexity is O (log n + log n) for sort() and heap. 
 *  ***/

