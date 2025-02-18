// upr3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
using namespace std;



class Angle {
public:
    double degrees, radians;
    void calc(double d) {
        degrees = d;
        radians = degrees * M_PI / 180;
        cout << "sin(" << degrees << ") = " << sin(radians) << endl
            << "cos(" << degrees << ") = " << cos(radians) << endl
            << "tan(" << degrees << ") = " << tan(radians) << endl;
    }
};

int main()
{
    Angle c;
    double deg;
    cout << " Degrees: ";
    cin >> deg;
    c.calc(deg);
    return 0;
}