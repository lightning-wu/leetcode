#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int end = size - 1;
        int i = end;
        while (i >= 0) {
            if (nums[i] >= (end - i)) {
                end = i;
            }
            i--;
        }
        if (end != 0) {
            return false;
        }
        return true;
    }
};


int main() {
    int d[] = {3,2,1,0,4};
    vector<int> a(d, d + 5);
    Solution sol;
    cout << sol.canJump(a) << endl;
}