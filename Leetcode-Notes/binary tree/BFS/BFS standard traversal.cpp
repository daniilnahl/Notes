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