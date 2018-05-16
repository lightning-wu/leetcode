#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>


using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // tips: find the largest data below or equal x
        vector<int> res;
        int size = arr.size();
        int idx = findIndex(arr, x);
        int ridx = idx + 1;
        int ct = 0;
        while (ct < k) {
            if (idx >= 0 && ridx < size) {
                if (abs(arr[idx] - x) <= abs(arr[ridx] - x)) {
//                    res.push_back(arr[idx]);
                    idx--;
                    ct++;
                } else {
//                    res.push_back(arr[ridx]);
                    ridx++;
                    ct++;
                }
            } else if (idx >= 0) {
//                res.push_back(arr[idx]);
                idx--;
                ct++;
            } else if (ridx < size) {
//                res.push_back(arr[ridx]);
                ridx++;
                ct++;
            }
        }
        for (int i = idx + 1; i < ridx; i++) {
            res.push_back(arr[i]);
        }
        return res;
    }

    int findIndex(vector<int> &arr, int x) {
        int size = arr.size();
        int low = 0;
        int high = size - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] <= x) {
                if (arr[mid + 1] > x) return mid;
                else low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
};

int main() {
    Solution sol;
    int data[] = {2,2,3,4,5};
    vector<int> vec(data, data + 5);
    cout << sol.findIndex(vec, 6) << endl;

    return 0;
}
