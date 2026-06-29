// 94. Binary Tree Inorder Traversal
// Given the root of a binary tree, return the inorder traversal of its nodes' values.


//RECURSIVE APPROACH - not recommended because of potential memory errors
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }

    void helper(TreeNode* root, vector<int>& res){
        if (root != nullptr){
            helper(root->left, res);
            res.push_back(root->val);
            helper(root->right, res);
        }
    }

};

//ITERATIVE APPROACH - goated
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack;
        vector<int> res;
        TreeNode* cur = root;

        while(cur != NULL || !stack.empty()){
            while (cur != NULL){
                stack.push(cur);
                cur = cur-> left;
            }

            cur = stack.top();
            stack.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
        return res;
    }
};

/****** 
 * WHAT WAS CORE IDEA?
 The core idea in iterative approach is to loop in a while, collecting addresses of all the addresses that are left from current. Once, that loops gets to the left branch thats empty exit, extract last address from stack, store its value and go to its right branch. 
 Repeat the whole process until stack is empty.
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used was DFS because it goes down as deep as possible until it hits a null.
 * 
 * Key concepts that I learned were:
 *  The core idea behind DFS algoritm and how to correctly do it iteratively.
 * 
 * WHAT TIME COMPLEXITY?
 * Time complexity is O (n) n for all the possible n nodes of the TreeNode.
 * WHAT SPACE COMPLEXITY?
 * Space complexity is O (n) n for all the roots added into stack.
 *  ***/

