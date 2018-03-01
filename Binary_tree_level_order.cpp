#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution{
    public:
        vector<vector<int> > levelOrder(TreeNode* root){
            queue<TreeNode*> q1;
            queue<TreeNode*> q2;
            vector<vector<int> > res;
            if (root == NULL){
                return res;
            }
            q1.push(root);
            while (1){
                if (!q1.empty()){
                    pop_push(q1, q2, res);
                }else if (!q2.empty()){
                    pop_push(q2, q1, res);
                }else {
                    break;
                }
            }
            return res;
        }
        
        void pop_push(queue<TreeNode*>& q1, queue<TreeNode*>& q2, vector<vector<int> >& res){
            vector<int> tmp;
            while (!q1.empty()){
                TreeNode* e = q1.front();
                tmp.push_back(e->val);
                if (e->left){
                    q2.push(e->left);
                }
                if (e->right){
                    q2.push(e->right);
                }
                q1.pop();
            }
            res.push_back(tmp);
        } 
        
        vector<vector<int> > levelOrder(TreeNode* root){ 
            vector<vector<int> > res;
            dfs(root, 0, res);
            return res;
        }

        void dfs(TreeNode* node, int depth, vector<vector<int> > &res){
            // terminator
            if (node == NULL)
                return;
            // current node
            if (depth == res.size()){
                vector<int> cur_vec(1, node->val);
                res.push_back(cur_vec);
            }else {
                res[depth].push_back(node->val);
            }
            // child node
            dfs(node->left, depth + 1, res);
            dfs(node->right, depth + 1, res);    
        }
};


