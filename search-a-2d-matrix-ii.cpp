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
        return search(0, cs - 1, matrix, target);
    }

    bool search(int cr, int cc, vector<vector<int> > &matrix, int target) {
        int rs = matrix.size();
        int cs = matrix[0].size();
        if (cr >= rs || cc < 0) return false;
        if (matrix[cr][cc] == target) {
            return true;
        } else if (matrix[cr][cc] > target) {
            return search(cr, cc - 1, matrix, target);
        } else {
            return search(cr + 1, cc, matrix, target);
        }

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