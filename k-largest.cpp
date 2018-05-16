#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include "myqueue.h"

using namespace std;



class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //priority_queue<int, vector<int>, greater<int> > q;
        myqueue q;
        for (vector<int>::iterator itr = nums.begin(); itr != nums.end(); itr++) {
            int num = *itr;
            if (q.empty()) {
                q.push(num);
            } else {
                int top = q.top();
                int size = q.length();
                if (size < k || num > top) {
                    q.push(num);
                    if (size == k) {
                        q.pop();
                    }
                }
            }
        }
        return q.top();
    }
};

int main() {
    int d[] = {2,5,1,3,4,6,2};
    vector<int> a(d, d + 7);
    Solution sol;
    cout << sol.findKthLargest(a, 4) <<endl;
    return 0;
}
