#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int max(int a, int b){
    return (a > b) ? a : b;
}


int getMaxProfit(vector<int> &prices){
    int res = 0;
    for (int i = 1; i < prices.size(); i++){
        res += (prices[i] > prices[i - 1]) ? prices[i] - prices[i - 1] : 0;
    }
    return res;
}

int maxProfit(int k, vector<int>& prices) {
    int days = prices.size();
    if (days == 0 || k == 0) return 0;
    int *** profit = new int**[days];
    int s,t;
    int res = 0;
    
    if (k > days / 2){
        return getMaxProfit(prices);
    }
    // init
    for (int i = 0; i < days; i++){
        profit[i] = new int*[k];
        for (int j = 0; j < k; j++){
            profit[i][j] = new int[2];
            for (int t = 0; t < 2; t++){
                profit[i][j][t] = INT_MIN;
            }
        }
    }
    profit[0][0][0] = 0; // dont buy any stock
    profit[0][0][1] = -prices[0];
    //profit[]
    for (int i = 1; i < days; i++){
        //s = i % 2;
        //t = (i - 1) % 2;
        for (int j = 0; j < k; j++){
            if (j == 0)
                // profit[s][j][1] = max(profit[t][j][1], -prices[i]);
                profit[i][j][1] = max(profit[i-1][j][1], -prices[i]);
            else
                //profit[s][j][1] = max(profit[t][j][1], profit[t][j - 1][0] - prices[i]);
                profit[i][j][1] = max(profit[i-1][j][1], profit[i-1][j - 1][0] - prices[i]);
            //profit[s][j][0] = max(profit[t][j][0], profit[t][j][1] + prices[i]);
            //res = max(res, profit[s][j][0]);
            profit[i][j][0] = max(profit[i-1][j][0], profit[i-1][j][1] + prices[i]);
            std::cout << "prfex" << i << " " << j << " " << profit[i-1][j][1] << std::endl;
            std::cout << i << " " << j << " " << profit[i][j][0] << std::endl;
            res = max(res, profit[i][j][0]);
        }
    }
    return res;
}


int main(){
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(2);
    vec.push_back(5);
    vec.push_back(7);
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(9);
    vec.push_back(0);
    maxProfit(4, vec);
return 0;
}
