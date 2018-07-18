#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


/*
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int times = 0;
        targetSum(nums, S, times, 0, 0);
        return times;
    }

    void targetSum(vector<int>& nums, int S, int& times, int pos, int curs) {
        int len = nums.size();
        if (pos >= len) {
            if (curs == S) {
                times++;
            }
            return;
        }
        for (int i = 0; i < 2; i++) {
            int w = (i == 0) ? 1 : -1;
            targetSum(nums, S, times, pos + 1, curs + nums[pos] * w);
        }
    }
};

*/

class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int S) {

        // dp[i][s][0] = dp[i-1][s-1] + dp[i-1][s+1]
        if (S > 1000 || S < -1000) return 0;
        int len = nums.size();
        int*** dp = new int**[len + 1];
        for (int i = 0; i < len; i++) {
            dp[i] = new int*[1001];
            for (int j = 0; j <= 1000; j++) {
                dp[i][j] = new int[2];
                dp[i][j][0] = 0;
                dp[i][j][1] = 0;
//                dp[i][j][0] = 0;
            }
        }
        if (nums[0] == 0) {
            dp[0][nums[0]][0] = 2;
            dp[0][nums[0]][1] = 2;
        } else {
            dp[0][nums[0]][0] = 1;
            dp[0][nums[0]][1] = 1;
        }

        for (int i = 1; i < len; i++) {
            for (int j = 1000; j >= 0; j--) {
                //dp[i][j][0] = dp[i - 1][j - ]
                if (j > nums[i]) {
                    // 1, 1, 0 => 0, 0, 0  0,0,1
                    if (j + nums[i] > 1000) {
                        dp[i][j][0] = dp[i - 1][j - nums[i]][0];
                        dp[i][j][1] = dp[i - 1][j - nums[i]][1];
                    } else {
                        dp[i][j][0] = dp[i - 1][j - nums[i]][0] + dp[i - 1][j + nums[i]][0];
                        dp[i][j][1] = dp[i - 1][j - nums[i]][1] + dp[i - 1][j + nums[i]][1];
                    }

                } else if (j == nums[i]) {
                    if (j + nums[i] > 1000) {
                        dp[i][j][0] = dp[i - 1][0][0];
                        dp[i][j][1] = dp[i - 1][0][0];
                    } else {
                        dp[i][j][0] = dp[i - 1][0][0] + dp[i - 1][nums[i] + j][0];
                        dp[i][j][1] = dp[i - 1][0][0] + dp[i - 1][nums[i] + j][1];
                    }
                } else {
                    if (j + nums[i] > 1000) {
                        dp[i][j][0] = dp[i - 1][nums[i] - j][1];
                        dp[i][j][1] = dp[i - 1][nums[i] - j][0];
                    } else {
                        dp[i][j][0] = dp[i - 1][j + nums[i]][0] + dp[i - 1][nums[i] - j][1];
                        dp[i][j][1] = dp[i - 1][j + nums[i]][1] + dp[i - 1][nums[i] - j][0];
                    }
                }
//                cout << i << " " << j << " " << dp[i][j][0] << " " << dp[i][j][1] << endl;
            }

        }
//        cout << "err" << endl;
        return (S >= 0) ? dp[len - 1][S][0] : dp[len - 1][-S][1];
    }
};

int main() {
    int a[] = {30,1,5,32,16,17,30,29,48,14,29,4,31,12,40,13,13,20,41,38};
    vector<int> data(a, a+20);
    Solution sol;

    cout << sol.findTargetSumWays(data, 9) << endl;
    return 0;
}