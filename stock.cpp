#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mprofit = 0;
        int buyer = INT32_MAX;
        for (int i = 0; i < prices.size(); i++) {
            mprofit = (mprofit < (prices[i] - buyer)) ? (prices[i] - buyer) : mprofit;
            buyer = (buyer < prices[i]) ? buyer : prices[i];
        }
        return mprofit;
    }
};