#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>


using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int size = nums.size();
        int low = 1;
        int high = size - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            int c = below(nums, mid);
            if (c <= mid) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return high;
    }

    int below(vector<int>& nums, int data) {
        int ct = 0;
        for (vector<int>::iterator itr = nums.begin(); itr != nums.end(); itr++) {
            if (*itr <= data) ct++;
        }
        return ct;
    }
};

int main() {


    return 0;
}
