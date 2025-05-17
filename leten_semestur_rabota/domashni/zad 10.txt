#include <iostream>

using namespace std;

class Complex {
    int real, imag;
public:
    Complex(int r, int i) {
        this->real = r;
        this->imag = i;
    }
    Complex operator+(Complex const &second) {
        Complex res(0,0);
        res.real = real + second.real;
        res.imag = imag + second.imag;
        return res;
    }
    void printNum() {
        cout << real << " + i" << imag << endl;
    }
};

int main()
{
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2;
    c3.printNum();
}