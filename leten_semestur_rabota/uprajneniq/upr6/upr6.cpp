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

class Polygon abstract {
public:
    void Area();
};

class Triangle : public Polygon {
    void Area() {

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
    return 0;
}