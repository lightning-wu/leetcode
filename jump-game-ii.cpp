#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
public:
    Solution() {
        step = NULL;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        step = new int[n];
        int i = n - 2;
        int ct = 0;
        step[ct++] = n - 1;
        while (i >= 0) {
            for (int j = 0; j < ct; j++) {
                if ((i + nums[i]) >= step[j]) {
                    step[j + 1] = i;
                    if (j == ct - 1) ct++;
                    break;
                }
            }
            i--;
        }
        for (int j = 0; j < ct; j++) {
            if (step[j] == 0) return j;
        }
        return -1;
    }

    int max2(int x, int y) {
        return (x > y) ? x : y;
    }

    int min2(int x, int y) {
        return (x > y) ? y : x;
    }
    int* step;
};


int main() {
    // [5,4,0,1,3,6,8,0,9,4,9,1,8,7,4,8]
    int d[] = {5,4,0,1,3,6,8,0,9,4,9,1,8,7,4,8};
    vector<int> a(d, d + 16);
    Solution sol;
    cout << sol.jump(a) << endl;
    return 0;
}