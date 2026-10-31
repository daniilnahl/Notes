#include <string>
using namespace std;


//1st approach - works but inefficient - 4 passes!
    void sortColors(vector<int>& nums) {
        //sort the array such that adjacent num/colors are next to each other 
        //0 is red
        //1 is white
        //2 is blue

        //the approach count the appearance of red, white, blue and just append them into a new vector
        int red = 0, white = 0, blue = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0) red++;
            if (nums[i] == 1) white++;
            if (nums[i] == 2) blue++;
        }
    
        nums.clear();

        for (int i = 0; i < red; i++) nums.push_back(0);
        for (int i = 0; i < white; i++) nums.push_back(1);
        for (int i = 0; i < blue; i++) nums.push_back(2);
    }

//2nd approach - the most efficient one - only 1 for loop pass - Dutch National Flag algorithm - niche ass algorithm
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;
        while (mid <= high){
            if(num[mid] == 0){
                swap(num[low], nums[mid]);
                low++;
                mid++;
            } else if(nums[mid] == 1){
                mid++;
            } else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
/****** 
 * WHAT WAS CORE IDEA?
 The core idea was to count the occurrences of each color, then empty out the vector, afterwards fill it up with 0s, 1s and 2s based on the counts within first loop.
 * The DSA/PATTERN I used simple for loop with counting.
*  
 * WHAT TIME COMPLEXITY? Time compelixty was O (n).
 * 
 * WHAT SPACE COMPLEXITY? Space compelixty was O (1).
 * 
 * WHAT IS THE SUMMARY OF THIS?
 * 
 *  ***/

