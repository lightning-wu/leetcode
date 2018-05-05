#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution {
public:
    string getPermutation(int n, int k) {
        int *visit = new int[10];
        char tmp[10] = {0};
        bool find = false;
        int ct = 0;
        permutation(0,ct,n,k,tmp, visit, find);
        return tmp;
    }

    void permutation(int pos, int &ct, int n, int k, char* tmp, int* visit, bool &find) {
        if (pos >= n) {
            ct++;
            if (ct == k) find = true;
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (visit[i] == 1) continue;
            visit[i] = 1;
            tmp[pos] = '0' + i;
            permutation(pos + 1, ct, n, k, tmp, visit, find);
            if (find) return;
            visit[i] = 0;
            tmp[pos] = '\0';
        }
    }
};


int main() {
    Solution s;
    string str = s.getPermutation(6,576);
    std::cout << str << std::endl;

}
