// version1, bfs with 2 queue
vector<int> largestValues(TreeNode* root) { 
    vector<int> res;
    if (root == NULL) return res;
    queue<TreeNode*> q1, q2;
    q1.push(root);
    while (1){
        if (!q1.empty())
            row_max(q1, q2, res);
        else if (!q2.empty())
            row_max(q2, q1, res);
        else
            break; 
    }
    return res;
}

void row_max(queue<TreeNode*>& q1, queue<TreeNode*>& q2, vector<int>& res){
    int q_max = INT_MIN;
    while (!q1.empty()){
        TreeNode* top = q1.front();
        q1.pop();
        q_max = (top->val > q_max) ? top->val : q_max;
        if (top->left) q2.push(top->left);
        if (top->right) q2.push(top->right);
    }
    res.push_back(q_max); 
}

//version2, bfs with 1 queue
vector<int> largestValues(TreeNode* root) { 
    vector<int> res;
    if (root == NULL) return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        int size = q.size();
        int q_max = INT_MIN;
        while (size--){
            TreeNode* front = q.front();
            q.pop();
            q_max = (front->val > q_max) ? front->val : q_max;
            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right);
        }
        res.push_back(q_max);
    }
    return res;
}


// version3, dfs
vector<int> largestValues(TreeNode* root) { 
    vector<int> res;
    dfs(0, root, res);
    return res;
}

void dfs(int depth, TreeNode* node, vector<int>& res){
    if (node == NULL) return;
    int size = res.size();
    if (depth >= size){
        res.push_back(node->val);
    }else {
        res[depth] = (res[depth] > node->val) ? res[depth] : node->val;
    }
    dfs(depth + 1, node->left, res);
    dfs(depth + 1, node->right, res);
}

