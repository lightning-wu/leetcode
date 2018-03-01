//
// Created by Œ‚÷æ±Û on 2018/3/1.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> tmp;
        vector<vector<int>> result;

        accum_sum(1, 0, k, n, tmp, result);
        return result;
    }

    void accum_sum(int min, int level, int k, int n, vector<int>& tmp, vector<vector<int>>& result) {
        if (level >= k) {
            if (n == 0) {
                result.push_back(tmp);
            }
            return;
        }

        for (int num = min; num <= 9; num++) {
            tmp.push_back(num);
            accum_sum(num + 1, level + 1, k, n - num, tmp, result);
            tmp.pop_back();
        }
    }
};