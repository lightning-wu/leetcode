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
        if (board[i][j] != '.') {
            int d = board[i][j] - '0';
            if (!isvalid(i, j, d)) return false;
            int newi = i;
            int newj = j + 1;
            if (j == 8) {
                newj = 0;
                newi = i + 1;
            }
            return solve(board, newi, newj);
        }
        for (int k = 1; k <= 9; k++) {
            if (isvalid(i, j, k)) {
                char newc = k + '0';
                char bakc = board[i][j];
                all_set(i, j, k);
                board[i][j] = newc;
                int newi = i;
                int newj = j + 1;
                if (j == 8) {
                    newj = 0;
                    newi = i + 1;
                }
                bool b = solve(board, newi, newj);
                if (b) return true;
                all_unset(i, j, k);
                board[i][j] = bakc;
            }
        }
        return false;
    }

    bool isvalid(int i, int j, int data) {
        int c = cal_corner(i, j);
        if (get(data, 0, i) || get(data, 1, j) || get(data, 2, c)) return false;
        return true;
    }

    void all_set(int i, int j, int data) {
        int c = cal_corner(i, j);
        set(data, 0, i);
        set(data, 1, j);
        set(data, 2, c);
    }

    void all_unset(int i, int j, int data) {
        int c = cal_corner(i, j);
        unset(data, 0, i);
        unset(data, 1, j);
        unset(data, 2, c);
    }

    int cal_corner(int i, int j) {
        int mi = (i / 3);
        int mj = (j / 3);
        return 3 * mi + mj;
    }

    bool get(int data, int type, int i) {
        int tmp = (1 << (type * 9 + i));
        return htable_get(data, tmp);
    }

    bool set(int data, int type, int i) {
        // type: 0 row , 1 col , 2 corner
        int tmp = (1 << (type * 9 + i));
        if (htable_get(data, tmp)) return false;
        htable_set(data, tmp);
        return true;
    }

    void unset(int data, int type, int i) {
        int tmp = (1 << (type * 9 + i));
        htable_unset(data, tmp);
    }

    void htable_set(int data, int value) {
        if (htable.find(data) == htable.end()) {
            htable[data] = value;
        } else {
            htable[data] |= value;
        }
    }

    bool htable_get(int data, int value) {
        if (htable.find(data) != htable.end() && (htable[data] & value) > 0) {
            return true;
        }
        return false;
    }

    void htable_unset(int data, int value) {
        if (htable.find(data) != htable.end() && (htable[data] & value) > 0) {
            htable[data] ^= value;
        }
    }

    unordered_map<int, int> htable;
};

int main() {
    int tmp = 1 << 3;
    tmp |= 1 << 2;
    int a = (tmp & 1 << 2);
    cout << a << endl;
    return 0;
}
