#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>


using namespace std;


class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int> queue;
        sort(courses.begin(), courses.end(), [](vector<int> a, vector<int> b){return (a[1] < b[1]);});
    }
};
