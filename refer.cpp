#include <iostream>
#include <utility>

using namespace std;


class Demo{
public:
    Demo() {
        v = 0;
        cout << "default empty construct" << endl;
    }

    Demo(const Demo& d) {
        cout << "copy construct" << endl;
        v = d.v;
    }

    Demo& operator=(const Demo& d) {
        if (this != &d) {
            int a;
        }
        v = d.v;
        cout << "operator=" << endl;
        return *this;
    }
    Demo(Demo&& d) {
        v = d.v;
        cout << "rvalue copy construct" << endl;
    }
    Demo& operator=(Demo&& d)  {
        cout << "rvalue operator=" << endl;
        v = d.v;
        return *this;
    }

    int v;

};
void ch(Demo& d);
void fun(Demo&& d) {
    cout << "fun with &&" << endl;
    ch(d);
}

void fun(Demo& d) {
    cout << "fun with &" << endl;
}

void test(Demo d) {
    cout << "test " << endl;
}

void ch(Demo& d) {
    d.v = 1;
}

/*
void test(Demo& d) {
    cout << "test &" << endl;
}
 */

int main() {

    Demo d;
    fun(d);
    fun(Demo());
    fun(move(d));
    Demo&& a = Demo();
    Demo&& b = move(a);
    // test(a);  // error, 同时命中test
    test(move(d));
    test(d);
    test(Demo());
    Demo e = move(d);
    Demo f;
    fun(move(f));
    cout << f.v << endl;
    return 0;
}