//
// Created by Œ‚÷æ±Û on 2018/3/9.
//


#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int> > res;
        vector<vector<int> > tmp;
        res.push_back(vector<int>());
        for (int i = 0; i < size; i++) {
            tmp = res;
            int len = tmp.size();
            for (int j = 0; j < len; j++) {
                vector<int> ele = tmp[j];
                ele.push_back(nums[i]);
                res.push_back(ele);
            }

        }
        return res;
    }

    vector<vector<int> > subsets2(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> tmp;
        subset(res, nums, 0, tmp);
        return res;
    }

    void subset(vector<vector<int> > &res, vector<int>& nums, int pos, vector<int>& tmp) {
        if (pos >= nums.size()) {
            res.push_back(tmp);
            return;
        }
        subset(res, nums, pos + 1, tmp);
        tmp.push_back(nums[pos]);
        subset(res, nums, pos + 1, tmp);
        tmp.pop_back();
    }


};

int main(int argc, char* argv[]) {
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

