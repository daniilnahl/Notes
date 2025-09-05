// 455. Assign Cookies
// Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
// Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.


//ATEMPT 1: 17/25 test cases passes
//issue with this solution is that what if cookie with 5 meets kid at 2 and then its cooky 4 and kid at 4?. 
//With this implementation only one kid would be fed even though if cookies were assigned properly 2 would be fed.
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0, kid = 0, cookie = 0;
        while (kid < g.size()){
            if (cookie ==  s.size()){
                cookie = 0;
                kid++;
            } else{
                if (s[cookie] >= g[kid]){ 
                    count++;
                    kid++;
                    s.erase(s.begin() + cookie);
                } else{
                    cookie++;
                }                
            }
        }
        return count;
    }
};

//ATEMPT 2
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0, kid = 0, cookie = 0;
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());

        while (kid < g.size() && cookie < s.size()){
            if (s[cookie] >= g[kid]){
                count++;
                kid++;
            }

            cookie++;
        }

        return count;
    }
};
/****** 
 * WHAT WAS CORE IDEA?
 The core idea was to repeat the check process of my first attempt, but to ensure that the issue I described doesn't happen
 both vectors are sorted beforehand, so if a cookie doesn't satisfy a kid it means its not going to satisfy any kid.
 Basically, in each iteration the smallest cookie meets the smallest kid and if cookie doesnt satisfy smallest kid then its not going to satisfy anyone.
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used two pointer method
 * Key concepts that I reinforced was using two pointer method to traverse vectors.
 * WHAT TIME COMPLEXITY?
 * Time complexity is O (n log n + m log m + m) m representing size of kid vector and n representing size of cookie vector.
 * WHAT SPACE COMPLEXITY?
 * Space complexity is O (1) - WRONG
 * Space complexity is O(logn+logm) because sort() uses extra space.
 *  ***/

