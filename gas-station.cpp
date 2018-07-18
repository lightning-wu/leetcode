#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curg = 0, curc = 0, totalg = 0, totalc = 0;
        int num = gas.size();
        int i = 0;
        int idx = -1;
        while (i < num) {
            totalg += gas[i];
            totalc += cost[i];
            curg += gas[i];
            curc += cost[i];
            if (curg < curc) {
                curg = 0;
                curc = 0;
                idx = -1;
            } else {
                if (idx == -1) idx = i;
            }
            i++;
        }
        return (totalg > totalc) ? idx : -1;

    }
};
