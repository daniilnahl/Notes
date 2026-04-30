// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
// A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_pointer = 0, t_pointer = 0;
        int count = 0;
        int needed_count = s.size();

        while (s_pointer < s.size()){
            for (int i = t_pointer; i < t.size(); i++){

                if (s[s_pointer] == t[i]){
                    t_pointer = i + 1;
                    count++;
                    break;
                }
            }

            s_pointer++;
        }

        if (count == needed_count) return true;
        else return false;
    }
};

/****** 
 * WHAT WAS CORE IDEA?
 The core idea was to utilize two pointers, 1st to navigate the subsequnce and the 2ns to navigate the full sequence. Within while loop the 1st pointer is incremented, so all the subsequence elements are checked.
 Inside the for loop, the full subsequence is iterated over using the 2nd pointer. In that for loop there's a check which checks for 1st and 2nd pointer to be the same element and if true 2nd pointer is moved to the next element in the
 full sequence, element count is updated and the for loop is broken, so the 1st pointer can be incremented. 

 After the loops are finished count is checked to be equal to the size of subsequence to ensure all the subsequence elements were found in proper order within the sequence.
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used was two pointers
 * Key concepts that I learned were:
 *  I didn't learn a new concept, but I did reinforce utilizing two pointers to traverse different elements.
 *  
 * WHAT TIME COMPLEXITY?
 *  Best case (when for loop is broken after 1 increment) is O (n), worst case is O(n * m), n being s.size and m being t.size.
 * WHAT SPACE COMPLEXITY?
 * Space complexity is O(1) since all inited variables are of constant size.
 *  ***/

