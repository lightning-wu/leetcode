#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int i = 0, j = size - 1;
        int m = 0;
        while (i < j) {
            int left = height[i], right = height[j];
            int tmp = min(right,left) * (j - i);
            if (tmp > m) m = tmp;
            if (left < right) {
                i++;
            } else {
                j--;
            }
        }
        return m;
    }

    int min(int a, int b) {
        return (a < b) ? a : b;
    }
};