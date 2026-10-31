// A sentence is a list of words that are separated by a single space with no leading or trailing spaces.

// For example, "Hello World", "HELLO", "hello world hello world" are all sentences.
// Words consist of only uppercase and lowercase English letters. Uppercase and lowercase English letters are considered different.

// A sentence is circular if:

// The last character of each word in the sentence is equal to the first character of its next word.
// The last character of the last word is equal to the first character of the first word.
// For example, "leetcode exercises sound delightful", "eetcode", "leetcode eats soul" are all circular sentences. However, "Leetcode is cool", "happy Leetcode", "Leetcode" and "I like Leetcode" are not circular sentences.

// Given a string sentence, return true if it is circular. Otherwise, return false.

class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        if (sentence[0] != sentence[n- 1]){
            return false;
        }else{
            for (int i = 0; i < n; i++){
                if (sentence[i] == ' '){
                    if (sentence[i-1] != sentence[i+1]) return false;
                } else{
                    continue;
                }
            }
            return true;
        }
    }
};

/****** 
 * WHAT WAS CORE IDEA?
 The core idea was to return false if edge cases were not passed. 98% of test cases on leetcode (261/266) passed with the simple check of first and last character of the string. 
 In the loop I check for the last char of a word to be the first char of the next word. I don't need to worry about going out of bound since in this problem if a space appears a character before and after the indice at which the space appeared is guaranteed. 
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used was simple string manipulation.
 * WHAT TIME COMPLEXITY?
 * Time complexity is O (n) n being the size of 'sentence'
 * WHAT SPACE COMPLEXITY?
 * Space complexity is O (1) 1 being the single variable I declared.
 * WHAT IS THE SUMMARY OF THIS?
 * Very easy leetcode problem.
 *  ***/

