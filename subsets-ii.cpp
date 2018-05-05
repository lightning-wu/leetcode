#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        // sort
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int *data = new int[size];
        int *ct = new int[size];
        // count
        bool first = true;
        int id = -1;
        for (vector<int>::iterator itr = nums.begin(); itr != nums.end(); itr++) {

            if (first || (*itr != data[id])) {
                data[++id] = *itr;
                ct[id] = 1;
            } else {
                ct[id]++;
            }
            first = false;
        }

        // subset
        vector<vector<int> > res;
        vector<int> tmp;
        subset(res, 0, id, tmp, data, ct);

        return res;
    }

    void subset(vector<vector<int> > &res, int pos, int size, vector<int>& tmp, int* data, int* ct) {
        if (pos > size) {
            res.push_back(tmp);
            return;
        }
        for (int ict = 0; ict <= ct[pos]; ict++) {
            for (int i = 1; i <= ict; i++) {
                tmp.push_back(data[pos]);
            }
            subset(res, pos + 1, size, tmp, data, ct);
            for (int i = 1; i <= ict; i++) {
                tmp.pop_back();
            }
        }
    }





};



int main() {
    vector<int> data;
    data.push_back(1);
    data.push_back(2);
//    data.push_back(3);
    data.push_back(2);

    vector<vector<int> > res = Solution().subsetsWithDup(data);
    for (int i = 0; i < res.size(); i++) {
        vector<int> ele = res[i];
        for (int j = 0; j < ele.size(); j++) {
            std::cout << ele[j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}