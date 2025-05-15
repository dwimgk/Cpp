#include <iostream>

using namespace std;

class worker {
    int age;
    string name;
public:
    void get() {
        cout << "Name: ";
        cin >> name;
        cout << "Age: ";
        cin >> age;
    }
    void show() {
        cout << "My name is " << name << " and my age is " << age << endl;
    }
};

class location :public worker {
    string workplace;
    string city;
public:
    void get() {
        worker::get();
        cout << "City: ";
        cin >> city;
        cout << "Workplace: ";
        cin >> workplace;
    }
    void show() {
        worker::show();
        cout << "I live in " << city << " and I work at " << workplace << endl;
    }
};
class manager :public location {
    int now;
public:
    void get() {
        location::get();
        cout << "Number of workers under: ";
        cin >> now;
    }
    void show() {
        location::show();
        if (now == 1) {
            cout << "Only one worker under me. " << endl;
        }
        else cout << "There are " << now << " workers under me. " << endl;
    }
};
class ceo :public manager {
    int nom;
public:
    void get() {
        manager::get();
        cout << "Number of managers under: ";
        cin >> nom;
    }
    void show() {
        manager::show();
        if (nom == 1) cout << "Only one manager under me. " << endl;
        else cout << "There are " << nom << " managers under me. " << endl;
    }
};

int main()
{
    ceo cl;
    cl.get();
    cl.show();

    return 0;
}