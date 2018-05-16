#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int hIndex2(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int cit = -1;
        int tp = 0;
        int m = 0;
        for (vector<int>::reverse_iterator itr = citations.rbegin(); itr != citations.rend(); itr++) {
            cit = *itr;
            tp++;
            if (min(cit, tp) > m) {
                m = min(cit, tp);
            } else {
                break;
            }

        }
        return m;
    }

    int min(int a, int b) {
        return (a < b) ? a : b;
    }

    int hIndex(vector<int>& citations) {
        int cit = -1;
        int tp = 0;
        int m = 0;
        for (vector<int>::iterator itr = citations.begin(); itr != citations.end(); itr++) {
            cit = *itr;
            tp++;
            if (min(cit, tp) > m) {
                m = min(cit, tp);
            } else {
                break;
            }

        }
        return m;

    }
};


int main() {
    vector<int> vec;
    vec.push_back(0);
    vec.push_back(1);
    Solution sol;
    cout << sol.hIndex(vec) << endl;
    return 0;
}