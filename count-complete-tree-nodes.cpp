#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        queue<int> qe;
        if (!root) return 0;
        root->val = 1;
        qe.push(root);
        bool f1 = false;
        int mval = -1;
        while (!qe.empty()) {
            TreeNode* t = qe.front();
            qe.pop();
            if (!t->right) {
                f1 = true;
                mval = t->val;
            }
            if (t->right) {
                t->right->val = 2 * t->val + 1;
                if (f1) {
                    return t->right->val;
                } else {
                    qe.push(t->right);
                }
            }
            if (t->left) {
                t->left->val = 2 * t->val;
                if (f1) {
                    return t->left->val;
                } else {
                    qe.push(t->left);
                }
            }
        }
        if (f1) {
            return mval;
        }

        return 0;
    }
};

