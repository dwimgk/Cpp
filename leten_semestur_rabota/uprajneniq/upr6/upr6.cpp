#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Abstract {
protected:
    int y;
public:
    int x;

    Abstract() {
        cout << "abstract" << endl;
    }

    virtual void something() = 0;
    //kogato ima tazi funkciq, ne moje da se initva obekt ot tozi klas, stava abstrakten
    void stuff() {
        cout << "kotka" << endl;
    }
};

class Child : public Abstract {
public:

    Child() {
        cout << "child" << endl;
        //izvikvat se i bazoviq konstruktor, i child constructora
    }


    //tuk trqbwa da se overridene virtual vunkciqta, i da se implementne, za da ne e abstrakten tozi klas veche
    void something() {
        cout << "Child I am" << endl;
    }
    void test() {
        //tuk moje da se dostupva do protected y, v maina primerno ne moje
    }
    void stuff() {
        cout << "kotka2" << endl;
    }
};
class Child2 : public Abstract {
public:
    void something() {
        cout << "I am child2" << endl;
    }
    void stuff(){
        cout << "kotka2" << endl;
    }
};

class Polygon {
public:
    vector<int> sides;
    int P;
    double S;
    void Perimeter() {
        for (int side : sides) {
            P += side;
        }
        cout << "perim "<< P << endl;
    }
    virtual void Area() = 0;
};

class Triangle : public Polygon {
public:
    double semiP;
    void Area() {
        semiP = (sides[0] + sides[1] + sides[2]) / 2;
        S= sqrt(semiP * (semiP - sides[0]) * (semiP - sides[1]) * (semiP - sides[0]));

        cout << "area " << S << endl;
    }
};
class Rectangle :public Polygon {
public:
    void Area() {
        S = sides[0] * sides[1];
        cout << "area " << S << endl;
    }
};

int main()
{
    //Test t1;
    Child c1;
    Child2 c2;

    vector<Abstract*> neshtosi;
    neshtosi.push_back(&c1);
    neshtosi.push_back(&c2);
    //polimorfizum

    for (Abstract *c : neshtosi) {
        c->something();
        //virtualnite direktno se zamestvat
        c->stuff();
        //vupreki che e abstrakten klas, vse pak ima problem, che ako e initnata, pak se izpolzva bazovata
    }
    cout << "" << endl;
    cout << "Polygons" << endl;
    cout << "" << endl;
    Triangle t;
    t.sides.push_back(3);
    t.sides.push_back(4);
    t.sides.push_back(5);
    t.Perimeter();
    t.Area();
    Rectangle r;
    r.sides.push_back(3);
    r.sides.push_back(4);
    r.Perimeter();
    r.Area();

    return 0;
}