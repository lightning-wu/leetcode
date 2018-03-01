#include <iostream>

class Solution {
    public:
        // dfs use stack
        vector<string> generateParenthesis(int n){
            stack<struct node*> s;
            vector<string> res;
            struct node* root = new node("(", 1, 1);
            s.push(root);
            while (!s.empty()){
                struct node* tmp = s.top();
                s.pop();
                int l = tmp->l;
                int sum = tmp->sum;
                string str = tmp->str;
                // left
                string left_str = str + "(";
                int left_l = l + 1;
                int left_sum = sum + 1;

                // right
                string right_str = str + ")";
                int right_l = l;
                int right_sum = sum - 1;

                if (l == n){
                    if (sum == 0){
                        res.push_back(str);
                        continue;
                    }else if(sum > 0){
                        struct node* right = new node(right_str, right_l, right_sum);
                        s.push(right);
                    }
                }else if (l < n){ 
                    if (sum > 0){
                        struct node* right = new node(right_str, right_l, right_sum);
                        s.push(right);
                    }
                    struct node* left = new node(left_str, left_l, left_sum);
                    s.push(left);
                }
            }
            return res;
        }

        // bfs use queue
        vector<string> generateParenthesis(int n){
            queue<struct node*> s;
            vector<string> res;
            struct node* root = new node("(", 1, 1);
            s.push(root);
            while (!s.empty()){
                struct node* tmp = s.front();
                s.pop();
                int l = tmp->l;
                int sum = tmp->sum;
                string str = tmp->str;
                // left
                string left_str = str + "(";
                int left_l = l + 1;
                int left_sum = sum + 1;

                // right
                string right_str = str + ")";
                int right_l = l;
                int right_sum = sum - 1;

                if (l == n){
                    if (sum == 0){
                        res.push_back(str);
                        continue;
                    }else if(sum > 0){
                        struct node* right = new node(right_str, right_l, right_sum);
                        s.push(right);
                    }
                }else if (l < n){ 
                    if (sum > 0){
                        struct node* right = new node(right_str, right_l, right_sum);
                        s.push(right);
                    }
                    struct node* left = new node(left_str, left_l, left_sum);
                    s.push(left);
                }
            }
            return res;
        }

        struct node{
            int l; // left patenthesis
            int sum;
            string str;
            node(string st, int d, int s){
                str = st;
                l = d;
                sum = s;
            }
        };

        // bfs use queue
        vector<string> generateParenthesis(int n){
            queue<struct node*> s;
            vector<string> res;
            struct node* root = new node("(", 1, 0);
            s.push(root);
            while (!s.empty()){
                struct node* nd = s.front();
                s.pop();
                int left = nd->left;
                int right = nd->right;
                string str = nd->str;
                
                if (left == right && left == n){
                    res.push_back(str);
                    continue;
                }
                if (left < n){
                    struct node* left_node = new node(str + "(", left + 1, right);
                    s.push(left_node);
                } 
                if (left > right && right < n){
                    struct node* right_node = new node(str + ")", left, right + 1);
                    s.push(right_node);
                }
            }
            return res;
        }

        struct node{
            int left; // left patenthesis
            int right;
            string str;
            node(string s, int l, int r){
                str = s;
                left = l;
                right = r;
            }
        };

        vector<string> generateParenthesis(int n){
            vector<string> res;
            dfs(0, 2*n, 1, 0, "(", res);
            return res;
        }

        void dfs(int level, int max_level, int left, int right, string str, vector<string>& res){
            if (level == max_level){
                if (left == right){
                    res.push_back(str); 
                } 
                return; 
            } 
            if (left < max_level / 2){           
                dfs(level + 1, max_level, left + 1, right, str + "(", res);
            }
            if (right < max_level / 2 && left > right){
                dfs(level + 1, max_level, left, right + 1, str + ")", res);
            }
        }
};
