//1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree


//APPROACH: DFS inorder, iterative
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* cur = cloned;
        stack<TreeNode*> stack;
        while(cur != NULL || !stack.empty()){
            while (cur != NULL){
                if (cur-> val == target->val) return cur;
                stack.push(cur);
                cur=cur->left;
            }

            cur = stack.top();
            stack.pop();

            cur=cur->right;
        }
        return NULL;
    }
};

/****** 
 * WHAT WAS CORE IDEA?
 
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used 
 * 
 * Key concepts that I learned were:
 *  
 * WHAT TIME COMPLEXITY?
 * 
 * WHAT SPACE COMPLEXITY?
 * 
 * WHAT IS THE SUMMARY OF THIS?
 * 
 *  ***/

