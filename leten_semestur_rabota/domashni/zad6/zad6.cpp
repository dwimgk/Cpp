#include <iostream>
#include <cmath>

using namespace std;

class SquarePyramid;

class Cylinder {
    double radius;
    double height;
public:
    Cylinder(double r, double h) {
        this->radius = r;
        this->height = h;
    }
    double getRadius() {
        return radius;
    }
    double getHeight() {
        return height;
    }

    bool IsHigher(const SquarePyramid& pyr);
};

class SquarePyramid{
    double side;
    double height;
public:
    SquarePyramid(double s, double h) {
        this->side = s;
        this->height = h;
    }
    double getSide() {
        return side;
    }
    double getHeight() {
        return height;
    }
    friend bool Cylinder::IsHigher(const SquarePyramid& pyr);

    double getSideHeight() {
        return sqrt((height * height) + (side / 2) * (side / 2));
    }
    double getLateralArea() {
        double sideHeight = getSideHeight();
        return (4 * (0.5 * side * sideHeight));
    }
    double getFullArea() {
        double latArea = getLateralArea();
        return ((side * side) + latArea);
    }
};

bool Cylinder::IsHigher(const SquarePyramid& pyr) {
    return height > pyr.height;
}

int main()
{
    Cylinder myC(2, 4);
    SquarePyramid mySP(3, 5);

    bool isCylinderHigher = myC.IsHigher(mySP);
    if (isCylinderHigher == true) {
        cout << "The Cylinder is higher" << endl;
    }
    else {
        cout << "The Pyramid is higher" << endl;
    }

    double latArea = mySP.getLateralArea();
    double fullArea = mySP.getFullArea();
    cout << "The declared Square Pyramid has a lateral area of " << latArea << " and a full area of " << fullArea << endl;

    return 0;
}