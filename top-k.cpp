#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();
        if ((l1 + l2) % 2 == 1) {
            return topk(nums1,0,l1 - 1, nums2, 0, l2 - 1, (l1 + l2) / 2 + 1);
        } else {
            double d1 = topk(nums1, 0, l1 - 1, nums2, 0, l2 - 1, (l1 + l2) / 2);
            double d2 = topk(nums1, 0, l1 - 1, nums2, 0, l2 - 1, (l1 + l2) / 2 + 1);
            return (d1 + d2) / 2;
        }
    }

    int topk(vector<int> &a, int as, int ae, vector<int> &b, int bs, int be, int k) {
        if (ae < as && be < bs) return -1;
        if (ae < as) {
            int left = be - bs + 1;
            if (left < k) return -1;
            return b[bs + k - 1];
        }
        if (be < bs) {
            int left = ae - as + 1;
            if (left < k) return -1;
            return a[as + k - 1];

        }
        int total = (ae - as + 1) + (be - bs + 1);
        if (total < k) return -1;
        if (k == 1) {
            return min(a[as], b[bs]);
        }
        int ma = min((as + k / 2 - 1), ae);
        int mb = min((bs + k / 2 - 1), be);
//        cout << "---" << ma << "--" << mb <<endl;
        if (a[ma] < b[mb]) {
            return topk(a, ma + 1, ae, b, bs, be, k - (ma - as + 1));
        } else {
            return topk(a, as, ae, b, mb + 1, be, k - (mb - bs + 1));
        }
    }

    int min(int a, int b) {
        return (a < b) ? a : b;
    }
};


int main() {
    Solution sol;
//    int da[6] = {0,2,3,5,6,7};
//    int db[] = {1,3,4,5,8};
    int da[] = {1,2};
    int db[] = {3,4};
    vector<int> a(da, da + 2);
    vector<int> b(db, db + 2);
    cout << sol.findMedianSortedArrays(a,b) << endl;
    return 0;
}