
#include <vector>
#include <iostream>
using namespace std;

class Solution{
    public:
        void perm(int s, vector<int>& nums, vector<vector<int> > &res){
            int len = nums.size();
            if (s == len){
                /*
                int ss = res.size();
                for (int i = 0; i < len; i++){
                    res[ss].push_back(nums[i]); 
                } 
                */
                res.push_back(nums);
                return;
            } 
            int tmp;
            for (int j = s; j < len; j++){
                //swap
                tmp = nums[j];
                nums[j] = nums[s];
                nums[s] = tmp; 

                perm(s + 1, nums, res);

                // swap
                tmp = nums[j];
                nums[j] = nums[s];
                nums[s] = tmp; 
            }
        }


        vector<vector<int> > permute(vector<int>& nums){
            vector<vector<int> > res;
            perm(0, nums, res);
            return res;
        }

};

void output(vector<int>& v){
    int len = v.size();
    for (int i = 0; i < len; i++){
        cout << v[i] << ",";
    }
    cout << endl;
}

int main(){
    vector<int> vec;
    vector<vector<int> > res;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    Solution sol;
    res = sol.permute(vec);
    
    int s = res.size();
    for (int i = 0; i < s; i++){
        output(res[i]);
    }
    return 0;
}
