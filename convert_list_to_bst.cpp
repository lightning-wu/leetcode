
/*
 * struct ListNode{
 *      int val;
 *      ListNode* left;
 *      ListNode* right;
 *      ListNode(int x) : val(x), next(NULL) {}
 * }
 *
 * struct TreeNode{
 *      int val;
 *      TreeNode *left;
 *      TreeNode *right;
 *      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *
 * }
 */
class Solution{


    public:
        ListNode* find_mid(ListNode* from, ListNode* to){
            ListNode* p, *q;
            if (from == NULL || from == to){
                return NULL;
            }
            p = from;
            q = from;
            while (q != to){
                q = q->next;
                if (q == to || q == NULL){
                    break;
                }
                q = q->next;
                p = p->next;
            }
            return p;
        }
        
        TreeNode* search(ListNode* from, ListNode* to){
            if (from == NULL){
                return NULL;
            }
            ListNode* mid;
            TreeNode *left, *right;
            mid = find_mid(from, to);
            if (mid == NULL){
                return NULL;
            }
            TreeNode *root = new TreeNode(mid->val);
            left = search(from, mid);
            right = search(mid->next, to);
            root->left = left;
            root->right = right;
            return root;
        }

        TreeNode* sortedListToBST(ListNode* head){
            TreeNode* root = search(head, NULL); 
            return root;
        }

};
