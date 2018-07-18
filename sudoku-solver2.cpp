#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
public:
    void solveSudoku(vector<vector<char> >& board) {
        solve(board, 0, 0);
    }

    bool solve(vector<vector<char> >& board, int i, int j) {
        if (i >= 9) {
            return true;
        }
        if (j >= 9) return solve(board, i + 1, 0);
        if (board[i][j] != '.') {
            return solve(board, i, j + 1);
        }
        for (int k = 1; k <= 9; k++) {
            if (check(board, i, j, k + '0')) {
                board[i][j] = k + '0';
                if (solve(board, i, j + 1)) return true;
                board[i][j] = '.';
            }
        }
        return false;
    }

    bool check(vector<vector<char> >&board, int i, int j, char val) {
        for (int k = 0; k < 9; k++) {
            if (board[i][k] == val) return false;
            if (board[k][j] == val) return false;
        }
        int mi = (i / 3);
        int mj = (j / 3);
        for (int ii = 0; ii < 3; ii++) {
            for (int jj = 0; jj < 3; jj++) {
                if (board[mi * 3 + ii][mj * 3 + jj] == val) return false;
            }
        }
        return true;
    }

};

int main() {
    int tmp = 1 << 3;
    tmp |= 1 << 2;
    int a = (tmp & 1 << 2);
    cout << a << endl;
    return 0;
}
