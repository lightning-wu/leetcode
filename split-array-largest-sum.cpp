#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int low = nums[0];
        int high = 0;
        int i = 0;
        int msum = 0, total = 0;
        for (vector<int>::iterator itr = nums.begin(); itr != nums.end(); itr++) {
            if(i < m - 1) {
                msum += (*itr);
                if (high < (*itr)) high = (*itr);
                i++;
            }
            total += (*itr);
        }
        if ((total - msum) > high) high = (total - msum);
        while (low < high) {
//            cout << low << " " << high << endl;
            int mid = low + (high - low) / 2;
            bool f = splitwithdata(nums, mid, m);
            if (f) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    bool splitwithdata(vector<int>& nums, int data, int m) {

        unsigned long sub_total = 0;
        unsigned long sub_num = 0;
        for (vector<int>::iterator itr = nums.begin(); itr != nums.end(); itr++) {
            if (sub_total + (*itr) <= data) {
                sub_total += (*itr);
//                cout << "fsdf " << sub_total << endl;
            } else {
                sub_num++;
                if (*itr > data) return false;
                sub_total = (*itr);
            }
        }
        sub_num++;
//        cout << data << "---" << sub_num << endl;
        return (sub_num <= m);
    }
};

int main() {
    Solution sol;
    int data[] = {1,2147483647};
    vector<int> vec(data, data + 2);
    cout << sol.splitArray(vec, 2) << endl;

    return 0;
}


