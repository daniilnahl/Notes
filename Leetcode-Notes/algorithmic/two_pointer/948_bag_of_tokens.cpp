#include <vector>
#include <algorithm>
class Solution {
public:
    int bagOfTokensScore(std::vector<int>& tokens, int power) {
        /***ATTEMP 1: 45/152 test cases passed
        //find the first token to get score to 1 then break
        //then find lowest power, lose score and get as many tokens as possible
        //have a check that if vector that holds indices visited - tokens size = 1 it breaks
        int arr[] = {0,0};
        int score = 0, org_size = tokens.size(), temp = 1;
        //find the first token to get score to 1 then break, sort the tokens as well
        for (int i=0; i < tokens.size(); i++){
            if (power > tokens[i]){
                score++;
                arr[0] = score;
                tokens.erase(tokens.begin() + i);
                break;
            }
        }

        std::sort(tokens.begin(), tokens.end(), std::greater<int>());

        if (org_size - temp > 1 && score != 0){
            score--;
            power = tokens[0];
            // instead of erasing just start at element 1 instead of 0; tokens.erase(tokens.begin() + 0);
            for(int i = 1; i < tokens.size(); i++){
                if (power > tokens[i]){
                    score++;
                }
            }
            arr[1] = score;
        }

        if (arr[0] > arr[1]){
            return arr[0];
        }else{
            return arr[1];
        }
        *****/

        //ACTUAL SOLUTION (using two pointer)
        int low = 0, high = tokens.size() - 1, score = 0;
        sort(tokens.begin(), tokens.end());
        while(low<=high){
            if(power>=tokens[low]){
                score+=1;
                power-=tokens[low];
                low +=1;
            } else if(low<high && score>0){
                score -=1;
                power+= tokens[high];
                high-=1;
            } else{
                return score;
            }
        }
        return score;
    }
};

/****** 
 * WHAT WAS CORE IDEA?
 The core idea was to use an actual two pointer approach which I did not use in my approach. Also, I fully misunderstood the question in my first attempt.
 Basically, first sort array in ascending order on left side (flip up tokens) and iff power is not enough for the curr. value at low then go to right pointer where you flip down token and increase your power.
 Proceed with this until low ptr meets high ptr.
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used two pointer approach with simple sort.
 * 
 * Key concepts that I reinforced in this problem is to think more outside the box. Albeit, I knew that this was a 2 ptr question, I still didn't use it.
 * This mistake led to failing to complete the question in given time. Thus, think outside the box and be more open to using different solving approaches.
 *  
 * WHAT TIME COMPLEXITY?
 *  O (n log n) for the sort call.
 * WHAT SPACE COMPLEXITY?
 *  O (log n) for the sort call.
 *  ***/

