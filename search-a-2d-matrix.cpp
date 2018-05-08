#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int rs = matrix.size();
        if (rs == 0) return false;
        int cs = matrix[0].size();
        return binarySearch(0, 0, rs - 1, cs - 1, matrix, target);
    }

    bool binarySearch(int sr, int sc, int er, int ec, vector<vector<int> > &matrix, int target) {
        if (sr > er || (sr == er && sc > ec)) return false;
        if (sr == er && sc == ec) {
            return matrix[sr][sc] == target;
        }
        int rs = matrix.size();
        int cs = matrix[0].size();
        int mr,mc;
        mid(sr, sc, er, ec, rs, cs, mr, mc);
        if (matrix[mr][mc] > target) {
            int br,bc;
            before(mr, mc, rs, cs, br, bc);
            return binarySearch(sr, sc, br,bc, matrix, target);
        } else if (matrix[mr][mc] < target) {
            int ar, ac;
            after(mr, mc, rs, cs, ar, ac);
            return binarySearch(ar, ac, er, ec, matrix, target);
        } else {
            return true;
        }
    }


    void mid(int sr, int sc, int er, int ec, int rs, int cs, int &mr, int &mc) {
        int dist = (er * cs + ec + 1) - (sr * cs + sc + 1);
        int half_dist = dist / 2;
        mr = sr + (half_dist + sc) / cs;
        mc = (half_dist + sc) % cs;
    }

    void before(int r, int c, int rs, int cs, int &br, int &bc) {
        if (c == 0) {
            br = r - 1;
            bc = cs - 1;
        } else {
            br = r;
            bc = c - 1;
        }
    }

    void after(int r, int c, int rs, int cs, int &ar, int &ac) {
        if (c == cs - 1) {
            ar = r + 1;
            ac = 0;
        } else {
            ar = r;
            ac = c + 1;
        }
    }

    int max2(int a, int b) {
        return (a > b) ? a : b;
    }
};



int main() {
    Solution sol;
    vector<vector<int> > matrix;
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(7);
    vector<int> v2;
    v2.push_back(10);
    v2.push_back(11);
    v2.push_back(16);
    v2.push_back(20);
    vector<int> v3;
    v3.push_back(23);
    v3.push_back(30);
    v3.push_back(34);
    v3.push_back(50);
    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);


    std::cout << sol.searchMatrix(matrix, 7) << std::endl;


    return 0;
}