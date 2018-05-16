#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;



/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    struct Mid {
        int start;
        int idx;
        Mid(int s, int i) : start(s), idx(i) {}
    };

    struct less_than_key
    {
        inline bool operator() (const Mid& struct1, const Mid& struct2)
        {
            return (struct1.start < struct2.start);
        }
    };


    vector<int> findRightInterval(vector<Interval>& intervals) {
        int idx = -1;
        vector<Mid> vec;
        vector<int> res;
        for (vector<Interval>::iterator itr = intervals.begin(); itr != intervals.end(); itr++) {
            idx++;
            vec.push_back(Mid((*itr).start, idx));
        }
        sort(vec.begin(), vec.end(), less_than_key());
        for (vector<Interval>::iterator itr = intervals.begin(); itr != intervals.end(); itr++) {
            int id = findBelow(vec, (*itr).end);
            res.push_back(id);
        }
        return res;
    }

    int findBelow(vector<Mid>& mids, int data) {
        int size = mids.size();
        int low = 0;
        int high = size - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (mids[mid].start >= data) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        if (mids[high].start < data) return -1;
        return mids[high].idx;
    }
};