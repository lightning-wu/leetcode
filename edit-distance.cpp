#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int la = word1.length();
        int lb = word2.length();
        if (lb == 0) return la;
        if (la == 0) return lb;
        int** dis = new int*[la];
        for (int i = 0; i < la; i++)
            dis[i] = new int[lb];

        if (word1[0] == word2[0]) {
            dis[0][0] = 0;
        } else {
            dis[0][0] = 1;
        }

        for (int i = 1; i < la; i++) {
            if (word1[i] == word2[0]) {
                dis[i][0] = i;
            } else {
                dis[i][0] = min2(1 + i, dis[i - 1][0] + 1);
            }
        }

        for (int i = 1; i < lb; i++) {
            if (word1[0] == word2[i]) {
                dis[0][i] = i;
            } else {
                dis[0][i] = min2(1 + i, dis[0][i - 1] + 1);
            }
        }

        for (int i = 1; i < la; i++) {
            for (int j = 1; j < lb; j++) {
                if (word1[i] == word2[j]) {
                    dis[i][j] = dis[i - 1][j - 1];
                } else {
                    dis[i][j] = min2(dis[i][j - 1], dis[i - 1][j]) + 1;
                    dis[i][j] = min2(dis[i][j], dis[i - 1][j - 1] + 1);
                }
            }
        }
        return dis[la - 1][lb - 1];
    }

    int min2(int a, int b) {
        return (a < b) ? a : b;
    }
};