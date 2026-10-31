// You are given a string s consisting of the following characters: '(', ')', '{', '}', '[' and ']'.

// The input string s is valid if and only if:

// Every open bracket is closed by the same type of close bracket.
// Open brackets are closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
// Return true if s is a valid string, and false otherwise.


#include <stack>
#include <map>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
       if (s.size() % 2 != 0) return false; //necessary to not compute strings with odd amount of elements since those automatically clasify as false.

        std::stack<char> stack; //last in, first out. 
        std::map<char, char> dict = { {')', '('},  {']', '['}, {'}', '{'}};

        for(int i = 0; i < s.size(); i++){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') stack.push(s[i]);
            else{
                if (stack.empty()) return false;
                char top = stack.top();
                if (dict[s[i]] != top) return false;
                else{
                    stack.pop();
                }
            } 
        }
        
        if (stack.empty()) return true;
        return false;
    }


};


/****** - 
 * WHAT WAS CORE IDEA?
 The core idea of this exercise was to use a stack to collect open brackets and when a closed bracket is met to check if its the same type of bracket as the one at the top of the stack. If yes "pop" the top of the stack
 if not return false.
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used was using a stack to keep track of open brackets.
 * Key concepts that I learned were:
 *  I learned how to initialize a stack in c++.
 * WHAT TIME COMPLEXITY?
 * O (n) because I iterated through the whole string once.
 * WHAT SPACE COMPLEXITY?
 * 0 (n) because I populated a stack with open brackets from the string.
 * WHAT IS THE SUMMARY OF THIS?
 * In summary used a stack to keep track of open brackets and when encountered a closed bracket checked it againts the top of the stack, to see if they are the same type, if yes good, continue checking if not return false.
 *  ***/

