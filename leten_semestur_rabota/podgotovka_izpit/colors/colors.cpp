#include <iostream>
#include <cmath>

using namespace std;

class Color {
public:
    int red, green, blue;
    Color(){}
    Color(int red, int green, int blue) {
        this->red = red;
        this->green = green;
        this->blue = blue;
    }

    double returnY() {
        // 1 / 256 (255 + 1 za nulata) -> izchislqvane na kolko bihme razdelili edinicata za da izchislim na kolko procenta ot neq e vsqka edna mqrka ot cvetovata stoinost
        // polucheniq rezultat umnojavame po dadenata stoinost na suotvetniq cvqt, kato po tozi nachin poluchavame stoinostta mejdu 0 i 1
        double singleUnit = 1 / 255;
        double red_linear = pow(singleUnit * this->red, 2.218);
        double green_linear = pow(singleUnit * this->green, 2.218);
        double blue_linear = pow(singleUnit * this->blue, 2.218);

        double Y =  (red_linear * 0.2126) + (green_linear * 0.7156) + (blue_linear * 0.0722);
        double final_result = pow(Y, 0.43) * 100;
        return final_result;
    }
};

int main()
{
    Color black(0, 0, 0);
    Color white(255, 255, 255);
    Color red(255, 0, 0);

    cout << "Brightness of black: " << black.returnY() << endl;
    cout << "Brightness of white: " << white.returnY() << endl;
    cout << "Brightness of red: " << red.returnY() << endl;

    return 0;
}