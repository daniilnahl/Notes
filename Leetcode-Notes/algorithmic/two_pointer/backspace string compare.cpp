// 844. Backspace String Compare
// Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
// Note that after backspacing an empty text, the text will continue empty.

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int pt2 = s.size() - 1;
        int counter = 0; //counter for how many # encountered, there will be a check for this being > 0 if passes skip an element
        std::string new_s = "";
        std::string new_tt = "";

        while (pt2 > -1){
            if (s[pt2] != '#' && counter == 0){
                new_s += s[pt2];
                pt2--;
            }else if (s[pt2] != '#' && counter != 0){
                counter--;
                pt2--;
            }else{
                counter++;
                pt2--;
            }
        }

        pt2 = t.size() - 1;
        counter = 0;

        while (pt2 > -1){
            if (t[pt2] != '#' && counter == 0){
                new_tt += t[pt2];
                pt2--;
            }else if (t[pt2] != '#' && counter != 0){
                counter--;
                pt2--;
            }else{
                counter++;
                pt2--;
            }
        }

        return true ? (new_s == new_tt) : false;
    }
};

/****** 
 * WHAT WAS CORE IDEA?
The core idea was to start from the end instead of beginning and count how many times '#' appeared and skip a character if the count was above 0.
If count was 0 and char wasnt a '#' add it to a new string. Repeat the process for both strings and then compare two newly formed strings.

 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used was pointer but in this case just a single pointer.
 * 
 * Key concepts that I learned in this problem was to think outside the box and try to come at a problem from a different angle when
 * it doesnt workout the first time.
 *  
 * WHAT TIME COMPLEXITY?
 * Time complexity is O (n + m) n and m being sizes of s and t respectively.
 * WHAT SPACE COMPLEXITY? O (n + m) n and m being sizes of s and t respectively. Worst case each string has 0 #.
 *  ***/

