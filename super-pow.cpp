#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if (b.size() == 0) return 0;
        int idx = 0;
        int res = 1;
        for (vector<int>::iterator itr = b.begin(); itr != b.end(); itr++) {
            int d = *itr;
            if (idx > 0) {
                res = powmod(res, 10);
            }
            res = (res * powmod(a, d)) % 1337;
            idx ++;
        }
        return res;
    }

    int powmod(int a, int k) {
        // a^k mod 1337
        if (k == 0) return 1;
        if (k == 1) return (a % 1337);
        int r = k % 2;
        int tt = (powmod(a, k >> 1) % 1337);
        return (powmod(a, r) * tt * tt) % 1337;
    }
};