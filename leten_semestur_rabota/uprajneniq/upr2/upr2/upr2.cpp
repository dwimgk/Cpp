#include <iostream>
#include <vector>
using namespace std;

class Point {
public:
    int x, y;

    Point() {
        cout << "kotka" << endl;
    }
    Point(int a, int b) {
        x = a;
        y = b;

        cout << "x: " << x << " y: " << y << endl;
    }
};

int main()
{
    Point p1, p2;
    p1.x = 0;
    p2.x = 3;

    p1.y = 0;
    p2.y = 4;
    //double distance = distance(p1,p2);

    Point p3 (0, 0), p4(3, 4);

    vector<Point> pts = { p3,p4 };
    for (Point p : pts) {
        cout << p.x << ", " << p.y << endl;
    }


    // ako ni trqbwa po-skoro impliciten, toest ne ni trqbwa specifichen za
    // nachalni parametri, moje da ostavim i bez konstruktor,
    // toest kompilatora da si napravi svoi
    // zashtoto, ako napravim nqkakuv drug, veche trqbwa da se otgovarq samo na nego
    return 0;
}
