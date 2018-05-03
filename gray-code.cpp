#include <iostream>
#include <unordered_map>
#include <vector>


using namespace std;

class Solution {
public:

    Solution() {
        data = 0;
        predata = -1;
    }

    vector<int> grayCode(int n) {
        vector<int> res;
        data = 1 << (n - 1);
        recur(n, 0, res);
        return res;
    }


    void recur(int n, int i, vector<int>& res) {
        if (i >= n) {
            //cout << data[0] << "," << data[1] << "," << data[2] << "," << data[3] << endl;
            return;
        }
        for (int j = 0; j < 2; j++) {
            data = BitXor(data, n - i - 1);
            std::cout << data << std::endl;
            if (IsGrayCode(data, predata) && m_exist.find(data) == m_exist.end()) {
                res.push_back(data);
                m_exist[data] = true;
                predata = data;
            }
            //data[i] = 1 - data[i];
            //cout << data[0] << "," << data[1] << "," << data[2] << "," << data[3] << endl;

            recur(n, i + 1, res);
        }
    }

    int BitXor(int data, int i) {
        int m = (1 << i);
        return data ^ m;
    }

    bool IsGrayCode(int d1, int d2) {
        if (d2 == -1) return true;
        int x = d1 ^ d2;
        return ((x & (x - 1)) == 0);
    }

    int data;
    int predata;
    unordered_map<int, bool> m_exist;
};


int main(int argc, char* argv[]) {
    Solution s;
    vector<int> res = s.grayCode(3);
    for (int j = 0; j < res.size(); j++) {
        std::cout << res[j] << " ";
    }
    return 0;
}