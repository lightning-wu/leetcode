#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        int len = nums.size();
        if (len == 0) return res;
        // statistic number ct
        for (int i = 0; i < len; i++) {
            int num = nums[i];
            if (_m_num_ct.find(num) == _m_num_ct.end()) {
                _m_num_ct[num] = 1;
            } else {
                _m_num_ct[num]++;
            }
        }

        // permute
        vector<int> tmp;
        Permute(res, 0, len, tmp);
        return res;

    }

    void Permute(vector<vector<int> >& res, int pos, int len, vector<int>& tmp) {
        if (pos >= len) {
            res.push_back(tmp);
            return;
        }
        unordered_map<int, int>::iterator itr;
        for (itr = _m_num_ct.begin(); itr != _m_num_ct.end(); itr++) {
            int num = itr->first;
            if (itr->second <= 0) continue;
            itr->second--;
            tmp.push_back(num);
            Permute(res, pos + 1, len, tmp);
            tmp.pop_back();
            itr->second++;
        }

    }

    unordered_map<int, int> _m_num_ct;
};


int main(int argc, char* argv[]) {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);


    Solution s;
    vector<vector<int> > res = s.permuteUnique(nums);
    for (int i = 0; i < res.size(); i++) {
        vector<int> ele = res[i];
        for (int j = 0; j < ele.size(); j++) {
            std::cout << ele[j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
