// upr2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;

class MyClass {
public:
    int a, b;
    void init() {
        a = 5;
        b = 8;

    }
};

int main()
{
    MyClass c;
    c.init();
    cout << "a = " << c.a << " b = " << c.b << endl;
    return 0;
}
