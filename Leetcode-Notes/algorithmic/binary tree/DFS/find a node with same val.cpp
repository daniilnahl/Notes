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
 The core idea was to traverse the whole tree inorder depth first, checking each nodes value to be the same to the target. If yes, return cur node.
 Why I used DFS? I was more familiar with it. A BFS might be more efficient in this problem. 
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used was DFS inorder traversal.
 * 
 * Key concepts that I reinforced was how to traverse a binary tree using DFS inorder.
 *  
 * WHAT TIME COMPLEXITY?
 * Time complexity is O (N) for N nodes in the cloned tree.
 * WHAT SPACE COMPLEXITY?
 * Space complexity is O (N) for N nodes in the cloned tree added to the stack.
 *  ***/

