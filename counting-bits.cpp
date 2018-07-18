#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        int *ct = new int[num + 1];
        ct[0] = 0;
        res.push_back(0);
        int i = 1;
        while (i <= num) {
            int j = (i >> 1);
            ct[i] = ct[j] + (i & 1);
            res.push_back(ct[i]);
            i++;
        }
        return res;
    }
};