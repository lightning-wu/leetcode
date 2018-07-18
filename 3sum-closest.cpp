#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[2];
        int size = nums.size();
        for (int i = 0; i < size - 2; i++) {
            int start = i + 1;
            int end = size - 1;
            while (start < end) {
                int tmp = nums[i] + nums[start] + nums[end];
                if (abs(tmp - target) < abs(result - target)) {
                    result = tmp;
                }
                if (tmp > target) {
                    end--;
                } else if (tmp < target) {
                    start++;
                } else {
                    return target;
                }
            }
        }
        return result;
    }
};