#include <iostream>
using namespace std;

void tiling(double shirina, double duljina) {
    int whole_tiles = (int)shirina * (int)duljina;

    int a_broken = (shirina > (int)shirina) ? (int)shirina : 0;
    int b_broken = (duljina > (int)duljina) ? (int)duljina : 0;

    int total_broken = (a_broken > 0 && b_broken > 0) ? 
        (a_broken + b_broken + 1) :
        (a_broken+b_broken);
    cout << "whole: " << whole_tiles << endl << "broken: " << total_broken << endl;
}

int main()
{
    float a,b;
    cout << "Enter a shirina ( . ): ";
    cin >> a;
    cout << "Enter a duljina: ";
    cin >> b;
    cout << "You entered: " << a << " " << b << endl;
    
    tiling(a, b);
    return 0;
}
