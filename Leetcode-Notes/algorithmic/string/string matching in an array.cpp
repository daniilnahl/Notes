// Given an array of string words, return all strings in words that are a substring of another word. You can return the answer in any order.


//FIRST APPROACH: timeout, inefficent and might be missing an edge case.
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int i = 0;
        unordered_set<string> set;
        vector<string> res;

        sort(words.begin(), words.end());
        
        while (i < words.size()){
           for (int j = i +1; j < words.size(); j++){
                if (words[j].find(words[i]) != std::string::npos){
                    set.insert(words[i]);
                }
            }
        }

        for (auto& pair : set){
            res.push_back(pair);
        }
        
        return res;
    }
};

//OPTIMAL APPROACH USING KMP