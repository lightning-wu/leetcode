#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {

        int *visit = new int[n + 1];
        vector<vector<string> > res;
        vector<string> tmp;
        solve(0, n, visit, res);
        return res;
    }

    void solve(int level, int n, int* visit, vector<vector<string> > &res) {
        if (level >= n) {
            vector<string> sol;
            for (int i = 0; i < n; i++) {
                string level_str(n, '.');
                level_str[visit[i]] = 'Q';
                sol.push_back(level_str);
            }
            res.push_back(sol);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!test(level, i, visit, level - 1)) continue;
            visit[level] = i;
            solve(level + 1, n, visit, res);

        }
    }

    bool test(int level, int i, int* visit, int maxl) {
        for (int il = 0; il <= maxl; il++) {
            if (visit[il] == i) return false;
            if ((level - il) == abs(i - visit[il])) return false;
        }
        return true;
    }
};


int main() {
    Solution sol;
    vector<vector<string> > res = sol.solveNQueens(4);
    for (vector<vector<string> >::iterator itr = res.begin(); itr != res.end(); itr++) {
        std::cout << "=====" << std::endl;
        for(vector<string>::iterator itr2 = (*itr).begin(); itr2 != (*itr).end(); itr2++) {
            std::cout << *itr2 << std::endl;
        }
    }

    return 0;
}