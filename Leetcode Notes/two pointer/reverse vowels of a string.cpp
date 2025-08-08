// Given a string s, reverse only all the vowels in the string and return it.
// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

#include <string>
#include <algorithm>


class Solution {
public:
    std::string reverseVowels(std::string s) {
        std::string vowels = "aeiouAEIOU";
        //have two pointers
        //check for both pointers to be pointing at a vowel and if yes switch both 
        int i = 0;
        int j = s.size() - 1;

        while (i <= j){
            while (i < j){
                if (vowels.contains(s[i])) break;
                else i++;
            }

            while (j > i){
                if (vowels.contains(s[j])) break; //contains() doesn't exist in c++ 17
                else j--;
            }

            std::swap(s[i], s[j]);
            i++;
            j--;
        }

        return s;
    }
};

/****** 
 * WHAT WAS CORE IDEA?
The core idea was two use two pointers one starting at the beginning and one at end then intiate a while loop which holds smaller loops for each pointer to search for a vowel.
Search breaks when a vowel is found by a pointer. When both pointers find a vowel a swap of the values at the indices that pointers are pointing at occurs.
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used was two pointers.
 * 
 * Key concepts that I learned were:
 *  Key concept I reinforced was utilizing two pointers dsa method.
 *  I learned that contains() function doesn't exist in c++ 17/
 * WHAT TIME COMPLEXITY?
 * Time complexity is O (n) because I have only one loop that is iterating through the string of size n.
 * WHAT SPACE COMPLEXITY?
 * Space complexity is O (1) because the only variables I used were of fixed size.
 * WHAT IS THE SUMMARY OF THIS?
 * In summary utilized two pointer method to traverse a string and swap vowels.
 *  ***/

