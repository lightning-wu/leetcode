#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (vector<int>::iterator itr = nums.begin(); itr != nums.end(); itr++)
            sum += *itr;
        bool* v = new bool[sum + 1];
        for (int i = 0; i <= sum; i++)
            v[i] = false;
        v[0] = true;
        int cur_sum = 0;
        for (vector<int>::iterator itr = nums.begin(); itr != nums.end(); itr++) {
            cur_sum += *itr;
            for (int i = cur_sum; i >=(*itr); i--) {
                    v[i] |= v[i - *itr];
            }
        }
        return (sum % 2 == 0) ? v[sum / 2] : false;
    }
};

int main() {
    int a[] = {1,5, 11,3};
    vector<int> data(a, a+4);
    Solution sol;
    cout << sol.canPartition(data) << endl;
    return 0;
}
