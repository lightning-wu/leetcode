//
// Created by Œ‚÷æ±Û on 2017/12/31.
//
#include <vector>
using namespace std;

class Solution {
public:
    Solution() {
        h = new short[5]{-1,0,1,0,0};
        w = new short[5]{0,-1,0,1,0};

    }

    ~Solution() {
        delete[] h;
        delete[] w;
    }

    bool getnextdir(vector<vector<char>>& board, int i, int j, int dir, int& ni, int& nj) {
        int lh = board.size();
        int lw = board[0].size();
        ni = i + w[dir];
        nj = j + h[dir];
        bool bi = (ni >= 0 && ni < lw);
        bool bj = (nj >= 0 && nj < lh);
        return (bi && bj && !visit[nj][ni]);
    }

    bool check(vector<vector<char>>& board, int i, int j, const string& word, int index) {
        visit[j][i] = true;
        if (board[j][i] == word[index]) {
            // go
            if (index == word.length() - 1) return true;
            for (int ii = 0; ii < 4; ii++) {
                int ni,nj;
                if (getnextdir(board, i, j, ii, ni, nj) && check(board, ni, nj, word, index + 1)) {
                    return true;
                }
            }
        }
        visit[j][i] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int lh = board.size();
        if (lh == 0) {
            return false;
        }
        int lw = board[0].size();
        visit = new bool*[lh + 1];
        for (int ii = 0; ii < lh; ii++) {
            visit[ii] = new bool[lw + 1];
        }
        int ci = 0;
        for (int jj = 0; jj < lh; jj++) {

            for (int ii = 0; ii < lw; ii++) {
                if (check(board, ii, jj, word, ci)) return true;
            }
        }
        return false;
    }

    bool **visit;
    short *h;
    short *w;
};


