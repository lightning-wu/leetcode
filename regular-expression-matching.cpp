#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
public:
    bool isMatch(string s, string p) {
        s = s + 'a';
        p = p + 'a';
        return subMatch(0, 0, s, p);
    }

    bool subMatch(int i, int j, string s, string p) {
        int ls = s.length();
        int lp = p.length();
        if (i >= ls && j >= lp) return true;
        if ((i - ls) * (j - lp) <= 0) return false;
        if (p[j] == '*') {
            return false;
        } else if (p[j] == '.' || s[i] == p[j]) {
            // match
            if (j + 1 < lp && p[j + 1] == '*') {
                bool f = subMatch(i + 1, j, s, p);
                if (f) {
                    return true;
                } else {
                    return subMatch(i, j + 2, s, p);
                }
            } else {
                return subMatch(i + 1, j + 1, s, p);
            }
        } else if (s[i] != p[j]) {
            if (j + 1 < lp && p[j + 1] == '*') {
                return subMatch(i, j + 2, s, p);
            }
        }
        return false;
    }
};


int main() {
    string s = "abc";
    string p = ".*";
    Solution sol;
    std::cout << sol.isMatch(s, p) << std::endl;
    return 0;
}
