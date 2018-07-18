#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int len = nums.size();
        bool *visit = new bool[len + 1];
        for (int i = 0; i < len; i++) visit[i] = false;
        int sum = 0;
        for (vector<int>::iterator itr = nums.begin(); itr != nums.end(); itr++)
            sum += *itr;
        if (sum % k != 0) return false;
        return dfs(nums, k, sum / k, visit, 0, 0, 0, 0);
    }

    bool dfs(vector<int>& nums, int k, int sum, bool* visit, int idx, int start, int cur_k, int cur_sum) {
        int len = nums.size();
        if (cur_k == k) return true;
        if (idx >= len || start >= len) return false;

        for (int i = start; i < len; i++) {
            if (visit[i]) continue;
            visit[i] = true;
            bool s = false;
            if (cur_sum + nums[i] == sum) {
                s = dfs(nums, k, sum, visit, idx + 1, idx + 1, cur_k + 1, 0);
            } else if (cur_sum + nums[i] < sum){
                s = dfs(nums, k, sum, visit, idx, i + 1, cur_k, cur_sum + nums[i]);
            }
            if (s) return s;
            visit[i] = false;
        }
        return false;
    }
};
*/

class Solution {
public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int sum = 0;
        for (vector<int>::iterator itr = nums.begin(); itr != nums.end(); itr++)
            sum += *itr;
        if (sum % k != 0) return false;
        int s = sum / k;
        bool** dp = new bool*[k + 1];
        for (int i = 0; i <= k; i++) {
            dp[i] = new bool[s + 1];
            for (int j = 0; j <= s; j++)
                dp[i][j] = false;
        }
        dp[0][0] = true;
        for (vector<int>::iterator itr = nums.begin(); itr != nums.end(); itr++) {
            cout << "process " << *itr << endl;
            for (int j = k - 1; j >= 0; j--) {

                for (int t = s; t >= *itr; t--) {
                    dp[j][t] |= dp[j][t - *itr];
                    if (dp[j][s]) {
                        dp[j + 1][0] = true;
                    }
                }
                for (int t = s; t >= 0; t--) {
                    cout << j << " " << t << " " << dp[j][t] << endl;
                }
            }
        }
//        cout << "0 16 " << dp[0][16] << endl;
//        cout << "1 16 " << dp[1][16] << endl;
//        for (int i = 0; i <= 16; i++) {
//            cout << "2 " << i << " " << dp[2][i] << endl;
//        }
        return dp[k][0];
    }
};


int main() {
    int a[] = {4,15,1,1,1,1,3,11,1,10};
    vector<int> data(a, a+10);
    Solution sol;

    cout << sol.canPartitionKSubsets(data, 3) << endl;
    return 0;
}