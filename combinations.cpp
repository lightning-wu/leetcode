//
// Created by Œ‚÷æ±Û on 2018/3/21.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> tmp;
        CombineChild(res, tmp, 0, 0, k, n);
        return res;
    }

    void CombineChild(vector<vector<int> > &res, vector<int> &tmp, int lasts, int level, int k, int n) {
        if (level >= k) {
            res.push_back(tmp);
            return;
        }
        for (int s = lasts + 1; s <= n; s++) {
            tmp.push_back(s);
            CombineChild(res, tmp, s, level + 1, k, n);
            tmp.pop_back();
        }
    }

};