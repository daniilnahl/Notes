// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and 
// removing all non-alphanumeric characters, it reads the same forward and backward. 
// Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.

#include <cctype> 
#include <string>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int start = 0, end = s.size() - 1;

        while (start < end){
            //checks for non alphanumeric characters based on ascii value in a loop.
            while(start < end){
                if ((s[start] > 64  && s[start] < 91) || (s[start] > 96 && s[start] < 123) || (s[start] > 47 && s[start] < 58)){
                    break;
                }
                start++;
            }

            while (end > start){
                if ((s[end] > 64  && s[end]  < 91) || (s[end] > 96 && s[end]  < 123) || (s[end]  > 47 && s[end] < 58)){
                    break;
                }
                end--;
            }

            //check for equality while also converting to lower case
            if (tolower(s[start]) != tolower(s[end])) return false;

            start++;
            end--;
        }

        return true;
    }
};

/******
 * WHAT WAS CORE IDEA?
 * The core idea of this solution was to set up two pointers, one starting at the beginning and one at the end, then inrementing first one and decrementing the second one until they are equal.
 * While doing that, the value at the pointers would be chedked for alphanumeric char, if it is one its value would be comprared with the other pointer.
 * If it was not then it would get incremented/decremented and loop until it is an alphanumeric char.
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used in this was a two pointer.
 * Key concepts that I learned were:
 *    I don't need to do 's[start] - 0' to convert a char into an int, I only need to do that if s[start] was a number and I wanted to convert it into its int equivalent.
 *    I can access non-existing key in a map and it would default initialize it to 0.
 * WHAT IS THE SUMMARY OF THIS?
 *  In summary, big loop with two pointers, with two small loops on the inside to find a valid value for either of the pointers. If those values equal then pass, if not break and return false. 
 * Repeat until pointers are equal. 
 //TIME COMPLEXITY is O(N)
 ***/

