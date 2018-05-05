#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {

        vector<vector<int> > res;
        vector<int> tmp;
        combination(0, 0, target, candidates, res, tmp);
        return res;
    }

    void combination(int level, int total, int target, vector<int> &candidates, vector<vector<int> > &res, vector<int> &tmp) {
        int max_levl = candidates.size();
        if (level >= max_levl) return;

        for (int ts = 0; ts <= target / candidates[level]; ts++) {
            total += (ts * candidates[level]);
            for (int i = 0; i < ts; i++) {
                tmp.push_back(candidates[level]);
            }
            if (total == target) {
                res.push_back(tmp);
            } else if(total < target) {
                combination(level + 1, total, target, candidates, res, tmp);
            }
            total -= (ts * candidates[level]);
            for (int i = 0; i < ts; i++) {
                tmp.pop_back();
            }
        }
    }
};


int main() {
    // [48,22,49,24,26,47,33,40,37,39,31,46,36,43,45,34,28,20,29,25,41,32,23]
    //69
    Solution sol;
    vector<int> candi;
    candi.push_back(1);
    candi.push_back(2);
    candi.push_back(3);
    vector<vector<int> > res = sol.combinationSum(candi, 7);
    for (vector<vector<int> >::iterator itr = res.begin(); itr != res.end(); itr++) {
        std::cout << "=====" << std::endl;
        for (vector<int>::iterator itr2 = (*itr).begin(); itr2 != (*itr).end(); itr2++) {
            std::cout << *itr2 << ",";
        }
        std::cout << std::endl;
    }

    return 0;
}