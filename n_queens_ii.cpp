#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {

        int *visit = new int[n + 1];
        int ct = 0;
        solve(0, n, visit, ct);
        return ct;
    }

    void solve(int level, int n, int* visit, int &ct) {
        if (level >= n) {
            ct++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!test(level, i, visit, level - 1)) continue;
            visit[level] = i;
            solve(level + 1, n, visit, ct);

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
    int ct = sol.totalNQueens(4);
    cout << ct << endl;
    return 0;
}