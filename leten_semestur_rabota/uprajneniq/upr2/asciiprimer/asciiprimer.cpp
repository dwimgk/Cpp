#include <iostream>
#include <vector>
using namespace std;

class Characters {
public:
    int appl_a;
    char appl_b;

    Characters(char b) {
        appl_b = b;
        appl_a = appl_b;
        cout << appl_b << " -> " << appl_a << endl;
    }
    Characters(int a) {
        appl_a = a;
        appl_b = appl_a;
        cout << appl_a << " -> " << appl_b << endl;
    }
};

int main()
{   
    Characters first (66), second ('A');

    return 0;
}
