#include <iostream>
#include <vector>

using namespace std;

int NOD(int a, int b) {
    
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

class Rat {
    vector<int> num;
public:
    Rat(vector<int> drob) {
        this->num = drob;
        simplify();
    }
    // operacii chislitel
    int getChis() {
        return num[0];
    }
    void setChis(int chis) {
        num[0] = chis;
    }
    // operacii znamenatel
    int getZnam() {
        return num[1];
    }
    void setZnam(int znam) {
        num[1] = znam;
    }
    // 
    void simplify() {
        int nod = NOD(abs(num[0]), abs(num[1]));
        if (nod != 0) {
            num[0] /= nod;
            num[1] /= nod;
        }
        if (num[1] < 0) {
            num[0] = -num[0];
            num[1] = -num[1];
        }
    }

    void printDrob() {
        cout << "Tazi drob e: " << num[0] << "/" << num[1] << endl;
    }

    //Rat operator+(Rat second) {
    //    vector<int> plusRatVector(0,0);
    //    
    //    Rat plusRat(plusRatVector);
    //    // (a/b) + (c/d) = (ad + bc)/(bd)
    //    plusRat.num[0] = this->num[0] * second.num[1] + second.num[0] * this->num[1];
    //    plusRat.num[1] = this->num[1] * second.num[1];

    //    plusRat.simplify();
    //    return plusRat;
    //}

    
    operator double() const {
        return (num[0] * 1.0) / num[1];
    }
};

Rat doubleToRat(double value) {
    const long long precision = 1000000;
    long long numerator = static_cast<long long>(round(value * precision));
    long long denominator = precision;
    long long gcd = NOD(abs(numerator), denominator);
    numerator /= gcd;
    denominator /= gcd;
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    return Rat({ static_cast<int>(numerator), static_cast<int>(denominator) });
}

Rat operator+(Rat first, Rat second) {
    vector<int> plusRatVector(2, 0);

    Rat plusRat(plusRatVector);
    

    // (a/b) + (c/d) = (ad + bc)/(bd)
    plusRat.setChis(first.getChis() * second.getZnam() + second.getChis() * first.getZnam());
    plusRat.setZnam(first.getZnam() * second.getZnam());

    plusRat.simplify();

    return plusRat;
}
Rat operator-(Rat first, Rat second) {
    vector<int> minusRatVector(2, 0);

    Rat minusRat(minusRatVector);


    // (a/b) - (c/d) = (ad - bc)/(bd)
    minusRat.setChis(first.getChis() * second.getZnam() - second.getChis() * first.getZnam());
    minusRat.setZnam(first.getZnam() * second.getZnam());

    minusRat.simplify();

    return minusRat;
}
Rat operator*(Rat first, Rat second) {
    vector<int> multiplyRatVector(2, 0);

    Rat multiplyRat(multiplyRatVector);


    // (a/b) * (c/d) = ( a * c ) / ( b * d )
    multiplyRat.setChis(first.getChis() * second.getZnam());
    multiplyRat.setZnam(first.getZnam() * second.getZnam());

    multiplyRat.simplify();

    return multiplyRat;
}
Rat operator/(Rat first, Rat second) {
    vector<int> divRatVector(2, 0);
    Rat divRat(divRatVector);

    // (a/b) / (c/d) = (a * d) / (b * c)
    divRat.setChis(first.getChis() * second.getZnam());
    divRat.setZnam(first.getZnam() * second.getChis());

    divRat.simplify();

    return divRat;
}
// -------------------------------------------------------------
Rat operator+(Rat first, double secondRaz) {
    Rat second = doubleToRat(secondRaz);
    vector<int> plusRatVector(2, 0);

    Rat plusRat(plusRatVector);
    

    // (a/b) + (c/d) = (ad + bc)/(bd)
    plusRat.setChis(first.getChis() * second.getZnam() + second.getChis() * first.getZnam());
    plusRat.setZnam(first.getZnam() * second.getZnam());

    plusRat.simplify();

    return plusRat;
}
Rat operator-(Rat first, double secondRaz) {
    Rat second = doubleToRat(secondRaz);

    vector<int> minusRatVector(2, 0);

    Rat minusRat(minusRatVector);


    // (a/b) - (c/d) = (ad - bc)/(bd)
    minusRat.setChis(first.getChis() * second.getZnam() - second.getChis() * first.getZnam());
    minusRat.setZnam(first.getZnam() * second.getZnam());

    minusRat.simplify();

    return minusRat;
}
Rat operator*(Rat first, double secondRaz) {
    Rat second = doubleToRat(secondRaz);

    vector<int> multiplyRatVector(2, 0);

    Rat multiplyRat(multiplyRatVector);


    // (a/b) * (c/d) = ( a * c ) / ( b * d )
    multiplyRat.setChis(first.getChis() * second.getZnam());
    multiplyRat.setZnam(first.getZnam() * second.getZnam());

    multiplyRat.simplify();

    return multiplyRat;
}
Rat operator/(Rat first, double secondRaz) {
    Rat second = doubleToRat(secondRaz);
    vector<int> divRatVector(2, 0);
    Rat divRat(divRatVector);

    // (a/b) / (c/d) = (a * d) / (b * c)
    divRat.setChis(first.getChis() * second.getZnam());
    divRat.setZnam(first.getZnam() * second.getChis());

    divRat.simplify();

    return divRat;
}
//---------------------------------------------------------------
Rat operator+(double firstRaz, Rat second) {
    Rat first = doubleToRat(firstRaz);
    vector<int> plusRatVector(2, 0);

    Rat plusRat(plusRatVector);

    // (a/b) + (c/d) = (ad + bc)/(bd)
    plusRat.setChis(first.getChis() * second.getZnam() + second.getChis() * first.getZnam());
    plusRat.setZnam(first.getZnam() * second.getZnam());

    plusRat.simplify();

    return plusRat;
}
Rat operator-(double firstRaz, Rat second) {
    Rat first = doubleToRat(firstRaz);

    vector<int> minusRatVector(2, 0);

    Rat minusRat(minusRatVector);


    // (a/b) - (c/d) = (ad - bc)/(bd)
    minusRat.setChis(first.getChis() * second.getZnam() - second.getChis() * first.getZnam());
    minusRat.setZnam(first.getZnam() * second.getZnam());

    minusRat.simplify();

    return minusRat;
}
Rat operator*(double firstRaz, Rat second) {
    Rat first = doubleToRat(firstRaz);

    vector<int> multiplyRatVector(2, 0);

    Rat multiplyRat(multiplyRatVector);


    // (a/b) * (c/d) = ( a * c ) / ( b * d )
    multiplyRat.setChis(first.getChis() * second.getZnam());
    multiplyRat.setZnam(first.getZnam() * second.getZnam());

    multiplyRat.simplify();

    return multiplyRat;
}
Rat operator/(double firstRaz, Rat second) {
    Rat first = doubleToRat(firstRaz);
    vector<int> divRatVector(2, 0);
    Rat divRat(divRatVector);

    // (a/b) / (c/d) = (a * d) / (b * c)
    divRat.setChis(first.getChis() * second.getZnam());
    divRat.setZnam(first.getZnam() * second.getChis());

    divRat.simplify();

    return divRat;
}

int main()
{
    Rat r1({ 1, 2 });
    Rat r2({ 1, 3 });
    Rat r3({ -2, 5 });
    Rat r4({ 0, 1 });
    double d1 = 0.25;
    double d2 = -0.5;

    cout << "Drob 1: ";
    r1.printDrob();
    cout << "Drob 2: ";
    r2.printDrob();
    cout << "Drob 3: ";
    r3.printDrob();
    cout << "Drob 4: ";
    r4.printDrob();
    
    cout << endl;

    Rat sum1 = r1 + r2;
    cout << "Sum (1/2 + 1/3): ";
    sum1.printDrob();
    Rat sum2 = r1 + r3;
    cout << "Sum (1/2 + -2/5): ";
    sum2.printDrob();
    Rat sum3 = r4 + r2;
    cout << "Sum (0/1 + 1/3): ";
    sum3.printDrob();

    cout << endl;

    Rat diff1 = r1 - r2;
    cout << "Difference (1/2 - 1/3): ";
    diff1.printDrob();
    Rat diff2 = r3 - r1;
    cout << "Difference (-2/5 - 1/2): ";
    diff2.printDrob();
    Rat diff3 = r1 - r4;
    cout << "Difference (1/2 - 0/1): ";
    diff3.printDrob();

    cout << endl;

    Rat prod1 = r1 * r2;
    cout << "Product (1/2 * 1/3): ";
    prod1.printDrob();
    Rat prod2 = r3 * r2;
    cout << "Product (-2/5 * 1/3): ";
    prod2.printDrob();
    Rat prod3 = r1 * r4;
    cout << "Product (1/2 * 0/1): ";
    prod3.printDrob();

    cout << endl;

    Rat div1 = r1 / r2;
    cout << "Division (1/2 / 1/3): ";
    div1.printDrob();
    Rat div2 = r3 / r1;
    cout << "Division (-2/5 / 1/2): ";
    div2.printDrob();
    Rat div3 = r2 / r1;
    cout << "Division (1/3 / 1/2): ";
    div3.printDrob();

    cout << endl;

    Rat sum4 = r1 + d1;
    cout << "Sum (1/2 + 0.25): ";
    sum4.printDrob();
    Rat diff4 = r1 - d2;
    cout << "Difference (1/2 - -0.5): ";
    diff4.printDrob();
    Rat prod4 = r2 * d1;
    cout << "Product (1/3 * 0.25): ";
    prod4.printDrob();
    Rat div4 = r1 / d1;
    cout << "Division (1/2 / 0.25): ";
    div4.printDrob();

    cout << endl;

    Rat sum5 = d1 + r1;
    cout << "Sum (0.25 + 1/2): ";
    sum5.printDrob();
    Rat diff5 = d2 - r1;
    cout << "Difference (-0.5 - 1/2): ";
    diff5.printDrob();
    Rat prod5 = d1 * r2;
    cout << "Product (0.25 * 1/3): ";
    prod5.printDrob();
    Rat div5 = d1 / r1;
    cout << "Division (0.25 / 1/2): ";
    div5.printDrob();

    cout << endl;

    double convert1 = r1;
    cout << "1/2 converted to double: " << convert1 << endl;
    double convert2 = r3;
    cout << "-2/5 converted to double: " << convert2 << endl;
    double convert3 = r4;
    cout << "0/1 converted to double: " << convert3 << endl;

    return 0;
}