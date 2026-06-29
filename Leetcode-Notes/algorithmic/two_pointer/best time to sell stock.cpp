// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

//TWO POINTER SOLUTION
#include <algorithm> 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lower = 0, upper = 1, max_profit = 0;

        while (upper < prices.size()){
            if (prices[upper] > prices[lower]){
                int profit = prices[upper] - prices[lower];
                max_profit = std::max(max_profit, profit);
            } else {
                lower = upper;
            }

            upper++;
        }

        return max_profit;
    }
};

//TIME COMPLEXITY: O(n)

//BRUTE FORCE SOLUTION
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        for (int i = 0; i < prices.size() - 1; i++){
            for (int j = i + 1; j < prices.size(); j++){
                std::cout << "i is at " << i << " and j is at " << j << " The difference is " << prices[i] - prices[j] << std::endl;
                if (prices[j]  - prices[i] > profit) profit = prices[j] - prices[i];
            }
        }

        return profit;
    }
};

//TIME COMPLEXITY: O(n^2)

/****** - for the two pointer solution
 * WHAT WAS CORE IDEA?
 * The core idea was to use two pointers to find the greatest difference between the upper and lower pointer. The loop iterates through the whole vector and inside it the difference is checked, if value at upper is higher than value at lower then record the difference and compare it with the current highest difference.
 * If the value at lower is higher than the value at upper then we set the lower pointer to be the right pointer which makes sense since if at day 1 stock is 100 and at day 2 stock is 10, more profit could be potentially made from buying the stock at day 2, but if it continues to go down the algorithm will just keep moving the lower bound
 * until it finds a value thats higher or hits the limit.
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used in this was a two pointer.
 * 
 * Key concepts that I learned were:
 *    max() is a function to get the maximum of two values.
 * WHAT IS THE SUMMARY OF THIS?
 * In summary used two pointers to iterate through a vector to find the greatest difference between upper and lower pointer. If at some instance value at lower is higher than value at upper then lower going to equal upper.
 * And even if the value keeps decresing at that point, the previously stored value of max_profit will be returned.
 ***/

