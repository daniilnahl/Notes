// Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.
// An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

#include <map>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false; //important early exit condition

        std::map<char, int> s_map;
        std::map<char, int> t_map;

        for (int i = 0; i < s.size(); i++){
            s_map[s[i]] += 1;
            t_map[t[i]] += 1;       
        }

        if (s_map == t_map) return true;
        return false;
    }
};


/******
 * WHAT WAS CORE IDEA?
 * The core idea of this solution was to count how many times unique chars appear
 * in both strings to see if they are anagrams. 
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA I used in my solution was a amp to count the frequnecy of chars in each string and then comparing the two maps.
 * Key concepts that I learned were:
 *    I can compare two maps using '=='
 *    I can access non-existing key in a map and it would default initialize it to 0.
 * WHAT IS THE SUMMARY OF THIS?
 * In summary, used hash map to do a TASK and if the outcome of doing TASK matched the wanted results return true.
 //TIME COMPLEXITY is O(N)
 *
 ***/