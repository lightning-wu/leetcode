#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        int len = num.length();
        if (len == 1) {
            if (target == num[0]) {
                string tmp = "";
                tmp = tmp + num[0];
                res.push_back(tmp);
            }
            return res;
        }

        char preop = '+';
        int predata = num[0] - '0';
        int sum = predata;
        string tmp = "";
        tmp = tmp + num[0];
        cal(num, 1, target, preop, predata, sum, tmp, res);
        return res;
    }

    void cal(string &num, int idx, int target, char preop, int predata, int sum, string tmp, vector<string>& vec) {
        int len = num.length();
        if (idx >= len) {
//            cout << idx << " " << sum << " " << tmp << endl;
            if (sum == target) {
                vec.push_back(tmp);
            }
            return;
        }
//        cout << idx << " " << sum << " " << tmp << endl;
        // +
        cal(num, idx + 1, target, '+', num[idx] - '0', sum + num[idx] - '0', tmp + '+' + num[idx], vec);
        // -
        cal(num, idx + 1, target, '-', num[idx] - '0', sum - num[idx] + '0', tmp + '-' + num[idx], vec);
        int npredata = veropPredata(preop, predata, num[idx] - '0');
        int nsum = veropSum(preop, predata, sum, num[idx] - '0');
        // *
        cal(num, idx + 1, target, preop, npredata, nsum, tmp + '*' + num[idx], vec);
        // null
        cal(num, idx + 1, target, preop, )

    }

    int veropPredata(char preop, int predata, int curdata) {
        return predata * curdata;
    }

    int veropSum(char preop, int predata, int sum, int curdata) {
        int npredata = veropPredata(preop, predata, curdata);
        int tmp = 0;
        if (preop == '-') {
            tmp = (sum + predata - npredata);
        } else if (preop == '+') {
            tmp = (sum - predata + npredata);
        }
        return tmp;
    }

    int nullPredata(char preop, )

};


int main() {
    string str = "123";
    int target = 6;
    Solution sol;
    vector<string> res = sol.addOperators(str, target);
    for (vector<string>::iterator itr = res.begin(); itr != res.end(); itr++)
        cout << *itr << endl;


}