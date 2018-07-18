#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int* step = new int[amount + 1];
        step[0] = 0;
        int i = 1;
        while (i <= amount) {
            step[i] = -1;
            for (vector<int>::iterator itr = coins.begin(); itr != coins.end(); itr++) {
                int c = *itr;
                if (i >= c && step[i - c] >= 0) {
                    step[i] = (step[i] == -1) ? (step[i - c] + 1) : min2(step[i], step[i - c] + 1);
                }
            }
            i++;
        }
        return step[amount];
    }

    int min2(int a, int b) {
        return (a < b) ? a : b;
    }
};