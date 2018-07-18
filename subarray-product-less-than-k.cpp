
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int size = nums.size();
        long  last_second = -1, second = -1, first = -1;
        int tmpk = 1;
        long num = 0;
        while (true) {
            first++;
            if (first >= size || second >= size) break;
            if (first > 0) {
                tmpk = tmpk / nums[first - 1];
            }
            while ((++second < size) && (tmpk * nums[second] < k)) {
               tmpk = tmpk * nums[second];
            }
            second = second - 1;
            unsigned long tm = (second + last_second - 2*first +3)*(second + 1 - last_second - 1)/2;
//            cout << first << "," << last_second << "," << second << "," << tm << endl;
            num += tm;
            last_second = second;
        }
        return num;
    }
};

int main() {
    /*
     * [10,9,10,4,3,8,3,3,6,2,10,10,9,3]
19
     */
    int d[] = {1,1,1,1,1,1,1,1,1,1,1};
    vector<int> a(d, d + 11);
    Solution sol;
    cout << sol.numSubarrayProductLessThanK(a,19) <<endl;
}
