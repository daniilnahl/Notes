/***
 * What is Bread First Search?
 * A way of searching that all nodes on the same level are checked before moving onto the next level.
 * 
 * How to do it?
 * There are two approaches recursive and iterative.
 * 1 - Recursive, well recursion.
 * 2 - Iterative, using a queue.
 * 
 * Time complexity is O (n)
 */

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

//RECURSIVE METHOD
void levelOrderRec(Node* root, int level, vector<vector<int>>& res){
    if (root == nullptr) return;
    if (res.size() <= level){ res.push_back({}); } // create next row of a matrix

    res[level].push_back(root->data);

    levelOrderRec(root->left, level + 1, res); //recurs for left
    levelOrderRec(root->right, level + 1, res);//recurs for right 
}

vector<vector<int>> levelOrder(Node* root){
    vector<vector<int>> res;
    levelOrderRec(root, 0, res);

    return res;
}


//ITERATIVE METHOD
vector<vector<int>> levelOrderIte(Node* root){
    if (root == nullptr) return {};
    queue<Node *> q;
    vector<vector<int>> res;

    //enqueue root
    q.push(root);
    int curr_level = 0;
    while(!q.empty()){
        int len = q.size();
        res.push_back({});

        for (int i = 0; i < len; i++){
            Node *node = q.front();
            q.pop();

            res[curr_level].push_back(node->data);

            if (node->left != nullptr){
                q.push(node->left);
            }

            if (node->right != nullptr){
                q.push(node->right);
            }
        }
        curr_level++;
    }
    return res;
}

int main() {
    //      5
    //     / \
    //   12   13
    //   /  \    \
    //  7    14    2
    // /  \   /  \  / \
    //17  23 27  3  8  11

    Node* root = new Node(5);
    root->left = new Node(12);
    root->right = new Node(13);

    root->left->left = new Node(7);
    root->left->right = new Node(14);

    root->right->right = new Node(2);

    root->left->left->left = new Node(17);
    root->left->left->right = new Node(23);

    root->left->right->left = new Node(27);
    root->left->right->right = new Node(3);

    root->right->right->left = new Node(8);
    root->right->right->right = new Node(11);

    //RECURSIVE METHOD
    auto res = levelOrder(root);
    for (vector<int> level : res) {
        cout << "[";
        for (int i = 0; i < level.size(); i++) {
            cout << level[i];
            if (i < level.size() - 1) cout << ", ";
        }
        cout << "] ";
    }
    cout << "\n\n\n\n\n" << endl;
    
    Node* roott = new Node(10);
    roott->left = new Node(12);
    roott->right = new Node(13);

    roott->left->left = new Node(1);
    roott->left->right = new Node(1);

    roott->right->right = new Node(2);

    roott->left->left->left = new Node(3);
    roott->left->left->right = new Node(3);

    roott->left->right->left = new Node(4);
    roott->left->right->right = new Node(4);

    roott->right->right->left = new Node(5);
    roott->right->right->right = new Node(5);
    //ITERATIVE METHOD
    auto ress = levelOrderIte(roott);
    for (vector<int> level : ress) {
        cout << "[";
        for (int i = 0; i < level.size(); i++) {
            cout << level[i];
            if (i < level.size() - 1) cout << ", ";
        }
        cout << "] ";
    }
}