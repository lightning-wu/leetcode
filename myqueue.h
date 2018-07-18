#include <iostream>
#include <string>
#include <vector>

using namespace std;

class myqueue {
public:
    myqueue() {
        size = 0;
    }

    bool empty() {
        return (size == 0);
    }

    int length() {
        return size;
    }

    void push(int num) {
        data[size++] = num;
        shiftup(size - 1);
    }

    int pop() {
        if (size <= 0) return -1;
        int res = data[0];
        // shift
        data[0] = data[size - 1];
        size--;
        shiftdown(0);
        return res;
    }

    int top() {
        if (size <= 0) return -1;
        return data[0];
    }

    void shiftdown(int i) {
        int l = 2*i + 1;
        int r = 2*(i + 1);
        if (l >= size) {
            if (r < size) {
                if (data[i] > data[r]) {
                    swap(i, r);
                    shiftdown(r);
                }
            }
        } else {
            if (r < size) {
                if (data[i] > min(data[l], data[r])) {
                    if (data[l] == min(data[l], data[r])) {
                        swap(i, l);
                        shiftdown(l);
                    } else if (data[r] == min(data[l], data[r])) {
                        swap(i, r);
                        shiftdown(r);
                    }
                }
            } else {
                if (data[i] > data[l]) {
                    swap(i, l);
                    shiftdown(l);
                }
            }
        }
    }

    void shiftup(int i) {
        if (i == 0) return;
        int p = i / 2;
        if (data[p] > data[i]) {
            swap(p, i);
            shiftup(p);
        }
    }

    void swap(int i, int j) {
        int tmp = data[j];
        data[j] = data[i];
        data[i] = tmp;
    }

    int min(int a, int b) {
        return (a < b) ? a : b;
    }
    vector<int> data;
    int size;
};
