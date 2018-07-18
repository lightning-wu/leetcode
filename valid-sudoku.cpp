#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int d = board[i][j] - '0';
                int c = cal_corner(i, j);
                if (!set(d, 0, i) || !set(d, 1, j) || !set(d, 2, c)) return false;
            }
        }
        return true;
    }

    int cal_corner(int i, int j) {
        int mi = (i / 3);
        int mj = (j / 3);
        return 3 * mi + mj;
    }

    bool set(int data, int type, int i) {
        // type: 0 row , 1 col , 2 corner
        int tmp = (1 << (type * 9 + i));
        if (htable_get(data, tmp)) return false;
        htable_set(data, tmp);
        return true;
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

    unordered_map<int, int> htable;
};

int main() {
    int tmp = 1 << 3;
    tmp |= 1 << 2;
    int a = (tmp & 1 << 2);
    cout << a << endl;
    return 0;
}
