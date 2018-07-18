#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;


class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int k) {
        double low = 0;
        double high = 1;
        vector<int> res;
        while (low < high) {
            double mid = (low + high) / 2;
//            cout <<" what" << mid << endl;
            int c = belowct(A, mid, res);
            if (c == k) {
                return res;
            } else if (c > k) {
                high = mid;
            } else {
                low = mid;
            }
        }
        return res;
    }

    int belowct(vector<int>& A, double data, vector<int> &res) {
        int len = A.size();
        int j = len - 2;
        int ct = 0;
        double md = 0;
        int mi,mj;
        res.clear();
        for (int i = len - 2; i >= 0; i--) {
            while (j >= i && p(A, i, j) <= data) {
                if (p(A, i, j) > md) {
                    md = p(A, i, j);
                    mi = A[i];
                    mj = A[j + 1];
                }
                j--;
            }
            ct += (len - 2 - j);
        }
        res.push_back(mi);
        res.push_back(mj);
//        cout << "md " << md << " " << mi << " " << mj <<endl;
        return ct;
    }

    double p(vector<int> &A, int i, int j) {
        // i row, j col
        return A[i] / (A[j + 1] * 1.0);
    }
};

int main() {
    Solution sol;
    int data[] = {1,2,3,5};
    vector<int> vec(data, data + 4);
    vector<int> res = sol.kthSmallestPrimeFraction(vec, 5);
    cout << res[0] << " " << res[1] <<endl;
    return 0;
}

