#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // sort
        sort(nums);
        int size = nums.size();
        int *data = new int[size];
        int *ct = new int[size];
        // count
        bool first = true;
        int id = -1;
        for (vector::iterator itr = nums.begin(); itr != nums.end(); itr++) {

            if (first || (*itr != data[id])) {
                data[++id] = *itr;
                ct[id] = 1;
            } else {
                ct[id]++;
            }
            first = false;
        }

        // subset


    }


};



int main() {
    vector<int> data;

    for (int i = 0; i < 3; i++) {
        data.push_back(i);
    }
    vector<vector<int> > res = Solution().subsets2(data);
    for (int i = 0; i < res.size(); i++) {
        vector<int> ele = res[i];
        for (int j = 0; j < ele.size(); j++) {
            std::cout << ele[j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}