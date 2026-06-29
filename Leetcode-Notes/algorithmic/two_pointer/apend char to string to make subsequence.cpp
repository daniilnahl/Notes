// 2486. Append Characters to String to Make Subsequence
// You are given two strings s and t consisting of only lowercase English letters.
// Return the minimum number of characters that need to be appended to the end of s so that t becomes a subsequence of s.
// A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

class Solution {
public:
    int appendCharacters(string s, string t) {
        int t_pt = 0, s_pt = 0, count = 0;
        while (s_pt < s.size()){
            if (s[s_pt] == t[t_pt]){
                count++;
                t_pt++;
                s_pt++;
            } else{
                s_pt++;
            }
        }

        return t.size() - count;
    }
};

/****** 
 * WHAT WAS CORE IDEA?
 The core idea was to iterate over string s and to count how many times its elements appear in t and return difference
 of t.size and count. 
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used two pointers to iterate over s and once an equal element is found increment t pointer.
 * Key concepts that I reinforced was using two pointers.
 * WHAT TIME COMPLEXITY? Time complexity is O (n), for n elements within string s.
 * WHAT SPACE COMPLEXITY? Space complexity is O (1), because there is a fixed amount of variables.
 * WHAT IS THE SUMMARY OF THIS?
 * In summary iterated over string s using pointer 1 to find same characters in string t. Once, a same element is found increment
 * count by 1 to track how many times s's element occured in t, increment t pointer by 1 to not repeat over same elements, 
 * and increment s pointer to not accidentally re-use an already used element of s.
 *  ***/

