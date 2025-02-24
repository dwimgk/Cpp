#include <iostream>
#include <vector>
using namespace std;

class Point {
private:
    int nedostapna;
public:
    friend void neshtosi(Point x);
    friend Point operator+(int b, Point other);
    friend ostream& operator<< (ostream& out, Point p);
    int x, y;

    Point() {
        cout << "kotka" << endl;
    }
    Point(int a, int b) {
        x = a;
        y = b;

        cout << "x: " << x << " y: " << y << endl;
    }
    
    Point operator+ (Point b) {
        return Point(x + b.x, y + b.y);
    }
    Point operator+(int b) {
        x += b;
        y += b;
        return *this;
    }
};
void neshtosi(Point x) {
    cout << x.nedostapna;
    //nedostapna zashtoto ne e friendnata oshte
}
Point operator+(int b, Point other) {
    other.x += b;
    other.y += b;
    return other;
}

ostream& operator<< (ostream& out, Point p) {
    out << p.x << ", " << p.y << endl;
    return out;
}

int main()
{
    Point p1, p2;
    p1.x = 0;
    p2.x = 3;

    p1.y = 0;
    p2.y = 4;

    p2 = 5 + p2;
    Point p5 = p1.operator+(p2);

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
