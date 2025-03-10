#include <iostream>

class SquarePyramid;

class Cylinder {
    double radius, height;
public:
    Cylinder(double, double);//constructor
    double getRadius();
    double getHeight();
    bool IsHigher(const SquarePyramid&);
};
Cylinder::Cylinder(double r, double h) {
    radius = r;
    height = h;
}
double Cylinder::getRadius() {
    return radius;
}
double Cylinder::getHeight() {
    return height;
}
class SquarePyramid {
    double side, height;
public:
    SquarePyramid(double, double);
    double getSide();
    double getHeight();
    double getsideHeight();//za dostup do visochinata na okolnata
    double getsideArea();//lice na okolna povurhnina

    double getArea();//lice na pulna povurhnina

    friend bool Cylinder::IsHigher(const SquarePyramid&);
};
SquarePyramid::SquarePyramid(double s, double h) {
    side = s;
    height = h;
}
double SquarePyramid::getSide() {
    return side;
}
double SquarePyramid::getHeight() {
    return height;
}
bool Cylinder::IsHigher(const SquarePyramid& obj) {

    return height > obj.height;
}
double SquarePyramid::getsideHeight() {
    return sqrt((height * height) + (side / 2) * (side / 2));
}
int main()
{
    std::cout << "Hello World!\n";
}