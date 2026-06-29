// Given a string s consisting of words and spaces, return the length of the last word in the string.
// A word is a maximal substring consisting of non-space characters only.
class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string temp;
        while(ss >> temp){
        }
        return temp.size();
    }
};

/****** 
 * WHAT WAS CORE IDEA?
 The core idea was using stringstream to iterate over all the words in s and whatever word 
 was last outputed from string stream would be the last word, thus just get that word's size and return.
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used was utilizing string stream around solving a stirng style problem.Basically, simple whitespace tokenization with stringstream.
 * Key concepts that I learned were:
 *  Thet concept I reinforced my undersntading of was utilizing string stream to traverse strings.
 
 * WHAT TIME COMPLEXITy?
 *  Time complexity is O (n) n being the size of s.
 * WHAT SPACE COMPLEXITY?
 * space complexity is O (n) n being the size of s. Temp is also extra space complexity of O (k) but since k < n its just O (n).
 * WHAT IS THE SUMMARY OF THIS?
 * In summary used string stream to iterate over words in s and then whatever is the last value in temp is the last word, so return its size.
 *  ***/

