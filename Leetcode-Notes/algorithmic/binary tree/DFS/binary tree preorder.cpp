#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
 struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int main(){

}

std::vector<int> preorderTraversal(TreeNode* root){
    if (root == nullptr) return {};

    std::vector<int> res;
    std::stack<TreeNode *> stack;
    TreeNode* curr;
    stack.push(root);

    while(!stack.empty()){
        curr = stack.top();
        stack.pop();   

        res.push_back(curr->val);

        if (curr->right != nullptr){
            stack.push(curr->right);
        }

        if (curr->left != nullptr){
            stack.push(curr->left);
        }
    }

    return res;
}