// There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.
// You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.
// The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.
// Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> minheap;
        for (int i = 0; i < classes.size(); i++){ //in a minheap store class index and the pass ratio increase from adding a student, so at the top of the heap would be a class with biggest increase
            double val = ((1.0 *(classes[i][0]+1.0)) / (classes[i][1]+1.0)) - ((1.0 *classes[i][0]) / classes[i][1]);
            minheap.push({val, i});
            //cout << "The increase from adding 1 student to class " << i << " will give this % increase to pass ratio " << val << endl;
        }
        cout << endl;
        //loop where a class with lowest pass ratio is popped and its student count is increased with extraStudents, loop until 0 extra students
        while(extraStudents != 0){
            auto top = minheap.top();
            minheap.pop();

            //cout << "Adding a student to class " << top.second << " because it gives the highest return " << top.first << endl;

            classes[top.second][0] +=1;
            classes[top.second][1] +=1;

            double val = ((1.0 *(classes[top.second][0]+1.0)) / (classes[top.second][1]+1.0)) - ((1.0 *classes[top.second][0]) / classes[top.second][1]);

            //cout << "AFTER Adding a student to class " << top.second << " because it gives the highest return, its return now is " << val << endl;

            minheap.push({val,top.second});
            extraStudents--;
        }

        /** here count the actual pass ratios, get their sum and then the average which you return **/
        double res = 0.000000000000000000000000000000000;
        for (int i = 0; i < classes.size(); i++){ 
            //cout << "dividing this " << classes[i][0] << "/" << classes[i][1] << endl; 
            res += ((1.0 * classes[i][0]) / classes[i][1]);
            //cout << res << endl;
        }
        res = res / classes.size();
        
        return res;
        
    }
};

/****** 
 * WHAT WAS CORE IDEA?
 The core idea was to store an indice and percent increase from adding a single 100% pass student into a specific class. In the heap the highest return class would be at the top. Through this process, the extra students would be added
 to classes that would increase the overall pass % the highest.
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used was maxheap.
 * WHAT TIME COMPLEXITY? Time complexity is O((N + L) log N) L for extra students. Log N for accessing heap within the first two loops.
 * WHAT SPACE COMPLEXITY? Space complexity is O (log N) for the heap.
 *  ***/

