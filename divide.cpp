
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int divide(int dividend, int divisor) {
        int remain = 0;
        if (divisor == -2147483648) {
            if (dividend == -2147483648) return 1;
            else return 0;
        }
        if (dividend == -2147483648) {
            if (divisor == -1) return 2147483647;
            if (divisor == 1) return -2147483648;
        }
        if (dividend == -2147483648) {
            dividend = -2147483647;
            remain = 1;
        }
        int sign = 1;
        if (dividend < 0) {
            dividend = -dividend;
            sign = -sign;
        }
        if (divisor < 0) {
            divisor = -divisor;
            sign = -sign;
        }
        int res = f(dividend, divisor, 1, remain);
        if (sign == 1)
            return res;
        else
            return -res;

    }

    int f(int y, int x, int rate, int remain) {
        if (y == 0 || rate == 0) return 0;
        if (y - x + remain < 0) return f(y, x >> 1, rate >> 1, remain);
        else if (y - x + remain - x >= 0) return f(y, x << 1, rate << 1, remain);
        else if (y -x + remain >= 0) {
//            std::cout << y << "," << x << "," << rate << "," << remain << std::endl;
            if (rate == 2147483647) return 2147483647;
            else return rate + f(y - x + remain, x >> 1, rate >> 1, 0);
        }
        else return 0;
    }
};

int main() {
    Solution sol;
    std::cout << sol.divide(10, 3) << std::endl;
}