#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;



class Solution {
public:
    Solution() {
        next = NULL;
    }

    int strStr(string haystack, string needle) {
        int ns = haystack.length();
        int ms = needle.length();
        int i = -1, j = -1;
        Next(needle);
        while (j < ns && i < ms) {
            while (i >= 0) {
                if (haystack[j] == needle[i]) {
                    break;
                } else {
                    i = next[i];
                }
            }
            i++;
            j++;
        }
        if (i >= ms) {
            return (j - ms);
        }
        return -1;
    }

    void Next(string needle) {
        int size = needle.length();
        next = new int[size];
        int k, j = 1;
        next[0] = -1;
        while (j < size) {
            k = next[j - 1];
            while (k >= 0) {
                if (needle[k] == needle[j - 1]) {
                    break;
                } else {
                    k = next[k];
                }
            }
            next[j] = k + 1;
            j++;
        }
    }

    int* next;

};


int main() {

    // haystack = "aaaaa", needle = "bba"
    // haystack = "hello", needle = "ll"
    string a = "hello", b = "ll";
    Solution sol;
    cout << sol.strStr(a, b) << endl;
}