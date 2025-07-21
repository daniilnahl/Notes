// You are given the root of a binary tree root. Invert the binary tree and return its root.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        //assumed constraints: a node could have only a right or left with those branches also having only a left or a right. 
        //correction: such constraint is not possible because to invert a tree like shown in the example they must have the same amount of members on each branch and node.


        //solution idea: have a while loop during which members of left side are saved into temp variables, then are replaced by values from right, then the values from right
        //replaced by values from the temp, ALL THIS WHILE REORDERING THE POINTERS in the correct way.

        //recursively reach the end of a tree when end is reached swap left and right
        if (root == nullptr){
            return root;
        }

        TreeNode* left = invertTree(root->right);
        TreeNode* right = invertTree(root->left);
        
        root->left = left;
        root->right = right;
        return root;
    }

 
};

/****** 
 * WHAT WAS CORE IDEA?
    The core idea was to recursively traverse the binary tree and swapping left and right of each node.
    Its going in post order, so left->right->root.
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used was recursion. 
 * 
 * Key concepts that I learned were:
 *  Reinforced the concept of recursion.
 * WHAT TIME COMPLEXITY?
 * O (n).
 * WHAT SPACE COMPLEXITY?
 * 0 (n) for recursion stack.
 * WHAT IS THE SUMMARY OF THIS?
 * In summary, used recursion to traverse the binary tree swapping left and right children and then returning the root.
 * After root is returned, its left and right are once more swapped to keep the recursion going, it keeps going until the recursion stack is clean.
 *  ***/

