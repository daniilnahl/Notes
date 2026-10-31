// A sentence is a string of single-space separated words where each word consists only of lowercase letters.

// A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

// Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.

//FIRST APPROACH: extremely inefficient time complexity
#include <iostream>
#include <sstream>
#include <string>
 
//The approach is to count how many times each word occurs and then return words that only occur once.
//1. use a hashmap to count. - YES
//2. count words from both strings. - STRUGGLE
//3. find and return words that occured only once. - YES
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> words;
        vector<string> unique_words;

        //loop for s1
        string temp = "";
        for (int i =0; i <s1.size(); i++){
            if (s1[i] != ' '){
                temp += s1[i];
            }else{
                words[temp] += 1;
                temp = "";
            }
        }

        words[temp] += 1;
        temp = "";
        
        //loop for s2
        for (int k =0; k <s2.size(); k++){
            if (s2[k] != ' '){
                temp += s2[k];
            }else{
                words[temp] += 1;
                temp = "";
            }
        }
        words[temp] += 1;

        for (auto& pair : words){
            cout << pair.first << " " << pair.second << endl;
            if (pair.second == 1){
                unique_words.push_back(pair.first);
            }
        }

        return unique_words;
    }
};


//SECOND APPROACH - a bit more efficient
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> words;
        vector<string> unique_words;

        stringstream ss1(s1), ss2(s2);
        string word;

        // Count occurrences of words in sentence A
        while (ss1 >> word) {
            words[word]++;
        }

        // Count occurrences of words in sentence B
        while (ss2 >> word) {
            words[word]++;
        }


        for (auto& pair : words){
            cout << pair.first << " " << pair.second << endl;
            if (pair.second == 1){
                unique_words.push_back(pair.first);
            }
        }

        return unique_words;
    }
};

/****** 
 * WHAT WAS CORE IDEA?
 The core idea was to count how many times each word occured and the only return the words that occured once.
 I did that by looping through each sentence and storing every word from it into a dictionary with a count.
 Both approaches do that, but the second one is a bit more efficient with it.
 Then I loop through the dictionary and store words that occured only once in a vector.
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used hashmaps and string manipulation (of sort).
 * 
 * Key concepts that I learned were:
 *  I learned of sstream library and that with it I can make data types that can parse through strings
 * the same way cin and cout with terminal and files.
 * 
 * WHAT TIME COMPLEXITY?
 * Time complexity is O (n + m) for n and m being words in s1 and s2.
 * WHAT SPACE COMPLEXITY?
 * Space complexity is O (d) d for all words added to the hashmap. 
 * WHAT IS THE SUMMARY OF THIS?
 * 
 *  ***/

