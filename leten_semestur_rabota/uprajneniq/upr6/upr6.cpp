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
    int Perimeter() {
        for (int side : sides) {
            P += side;
        }
        return P;
    }
    virtual double Area() = 0;
};

class Triangle : public Polygon {
public:
    Triangle(){}
    Triangle(int a, int b, int c) {
        sides.push_back(a);
        sides.push_back(b);
        sides.push_back(c);
    }
    
    double Area() {
        double semiP = (sides[0] + sides[1] + sides[2]) / 2;
        S= sqrt(semiP * (semiP - sides[0]) * (semiP - sides[1]) * (semiP - sides[0]));

        return S;
    }
};
class Rectangle :public Polygon {
public:
    Rectangle(){}
    Rectangle(int a, int b) {
        sides.push_back(a);
        sides.push_back(b);
    }
    double Area() {
        S = sides[0] * sides[1];

        return S;
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
    Triangle t(3,4,5);
    double tP = t.Perimeter();
    cout << "Perim " << tP << endl;
    double tA = t.Area();
    cout << "Area " << tA << endl;

    Rectangle r(3,4);
    double rP = r.Perimeter();
    cout << "Perim " << rP << endl;
    double rA = r.Area();
    cout << "Area " << rA << endl;

    return 0;
}