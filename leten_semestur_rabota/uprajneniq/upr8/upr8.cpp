#include <iostream>
#include <functional>
#include <math.h>
#include <vector>
using namespace std;

typedef int chisla;
//type elias
using cifri = int;
//moje navsqkude

class Base {
public:
    int x;
    Base() {
        cout << "base" << endl;
        cout << this <<endl;
    }
    virtual void test() = 0;
};

class Derived : public Base {
public:
    
    Derived() {
        cout << "derived" << endl;
        cout << this << endl;
    }
    void test() {}
};

vector<int> modify(vector<int> numbers, vector<int> f(vector<int>)) {

    return f(numbers);
}
vector<int> vectorModify(vector<int> numbers, vector<function<vector<int>(vector<int>)>> functions) {
    vector<int> intermediate = numbers;
    for (auto f : functions) {
        intermediate = f(intermediate);
    }
    return intermediate;
}


int main()
{
    //izvikani sa vsichki konstruktori, na edin obekt, na adres
    Derived d;
    int z = 5;

    vector<int> numbers = { 10,20,30,40 };

    //ppc v [] se izvikva promenliva, koqto prosto moje da se izpolzva v lambda funca, ne e smisleno da se promenq vutre, no moje
    // -> e assignvane na return typea, moje i bez nego, shtom izpolzvame auto
    auto square = [&z](vector<int> input) -> vector<int>{
        vector<int> result;
        z += 10;
        for (int x : input) result.push_back(x * x);
        return result;
    };
    auto root = [](vector<int> input) -> vector <int> {
        vector<int> result;
        for (int x : input) result.push_back((int)sqrt(x));
        return result;
    };

    cout << z << endl;
    vector<int> squares = square(numbers);
    cout << z << endl;
    for (int x : squares) cout << x << " ";
    cout << endl;

    vector<int> result = modify(squares, root);
    for (int x : result)cout << x << " ";
    cout << endl;
    cout << endl;
    cout << endl;

    vector<int> multiplefFunc = vectorModify(squares, { square, root });
    for (int x : result)cout << x << " ";
    cout << endl;
    cout << endl;
    cout << endl;
}
