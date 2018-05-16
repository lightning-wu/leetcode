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
        return countNode(root);
    }

    int countNode(TreeNode* root) {
        if (root == NULL) return 0;
        int llen = 1, rlen = 1;
        TreeNode* tmp = root;
        while (tmp->left) {
            llen++;
            tmp = tmp->left;
        }
        tmp = root;
        while (tmp->right) {
            rlen++;
            tmp = tmp->right;
        }
        if (llen == rlen) {
            return (1 << llen) - 1;
        }
        return countNode(root->left) + countNode(root->right) + 1;
    }
};

