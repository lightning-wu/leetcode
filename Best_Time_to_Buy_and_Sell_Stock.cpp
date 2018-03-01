#include <iostream>

// version 1
int maxProfit(vector<int>& prices) {
    int buyer, seller, profit;
    int max_profit = 0;
    
    buyer = INT_MAX;
    seller = 0;
    for (int i = 0; i < prices.size(); i++){
        if (prices[i] < buyer){
            buyer = prices[i];
            seller = buyer;
        } 
        if (prices[i] > seller){
            seller = prices[i];
            if (seller - buyer > max_profit){
                max_profit = seller - buyer;
            }
        }
    }
    return max_profit;
}

// version 1
int maxProfit(vector<int>& prices) {
    if (prices.size() == 0) return 0;
    int buyer = prices[0];
    int max_profit = 0;
    for (int i = 1; i < prices.size(); i++){
        buyer = (prices[i] < buyer) ? prices[i] : buyer;
        max_profit = (max_profit < (prices[i] - buyer)) ? (prices[i] - buyer) : max_profit;
    }
    return max_profit;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

int maxProfit(vector<int>& prices) {
    if (prices.size() == 0) return 0;
    int days = prices.size();
    int **profit = new int*[days];
    for (int i = 0; i < days; i++){
        profit[i] = new int[2];
    }
    profit[0][0] = 0;
    profit[0][1] = -prices[0];
    int res = profit[0][0];
    for (int i = 1; i < days; i++){
        profit[i][0] = max(profit[i -1][0], profit[i - 1][1] + prices[i]);
        profit[i][1] = max(profit[i - 1][1], -prices[i]);
        res = max(res, profit[i][0]);
    }
    return res;
}

}
// version 2
int maxProfit(vector<int>& prices) {
    int buyer, seller;
    int profit = 0;
    
    buyer = INT_MAX;
    seller = buyer;
    for (int i = 0; i < prices.size(); i++){
        if (prices[i] < seller){
            profit += (seller - buyer);
            buyer = prices[i];
            seller = buyer;
        } 
        if (prices[i] > seller){
            seller = prices[i];
        }
    }
    profit += (seller - buyer);
    return profit;
}

// version 2
int maxProfit(vector<int>& prices) {
    if (prices.size() == 0) return 0;
    int buyer = prices[0];
    int max_profit = 0;
    for (int i = 0; i < prices.size(); i++){
        if (prices[i] < prices[i - 1]){
            max_profit += (prices[i - 1] - buyer);
            buyer = prices[i];
        }
    }
    max_profit += (prices[prices.size() - 1] - buyer);
    return max_profit;
}

// version 3
int maxProfit(vector<int>& prices) {
    int days = prices.size();
    if (days == 0) return 0;
    int k = 2;
    int *** profit = new int**[days];
    // init
    for (int i = 0; i < days; i++){
        profit[i] = new int*[k];
        for (int j = 0; j <= k; j++){
            profit[i][j] = new int[2];
            for (int t = 0; t < 2; t++){
                profit[i][j][t] = INT_MIN;
            }
        }
    }
    profit[0][0][0] = 0; // dont buy any stock
    profit[0][0][1] = -prices[0];
    for (int i = 1; i < days; i++){
        for (int j = 0; j <= k; j++){
            if (j == 0)
                profit[i][j][1] = max(profit[i - 1][j][1], -prices[i]);
            // profit[i][j][0] = max(profit[i - 1][j][0], profit[i - 1][j - 1][1] + prices[i]);
            
            else
                profit[i][j][1] = max(profit[i - 1][j][1], profit[i - 1][j - 1][0] - prices[i]); // 第j次交易后持有股票， 第j-1交易且卖出股票后再持有
            profit[i][j][0] = max(profit[i - 1][j][0], profit[i - 1][j][1] + prices[i]);
            
        }
    }
    return max(profit[days - 1][0][0], profit[days - 1][1][0]);
}

