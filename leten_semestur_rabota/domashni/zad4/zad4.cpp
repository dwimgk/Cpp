#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
//const int MaxLengthName = 30;
//const int Patients = 200;

//class Date {
//    int thisDay, thisMonth, thisYear;
//public:
//    Date(int = 1, int = 1, int = 2000); //konstruktor
//    int Day() const;
//    int Month() const;
//    int Year() const;
//    void setDay(int);
//    void setMonth(int);
//    void setYear(int);
//    void print() const;
//};
//
//Date::Date(int d, int m, int y) {
//    thisDay = d;
//    thisMonth = m;
//    thisYear = y;
//}
//int Date::Day() const {
//    return thisDay;
//}
//int Date::Month() const {
//    return thisMonth;
//}
//int Date::Year() const {
//    return thisYear;
//}
//void Date::setDay(int d) {
//    thisDay = d;
//}
//void Date::setMonth(int m) {
//    thisMonth = m;
//}
//void Date::setYear(int y) {
//    thisYear = y;
//}
//
//void Date::print() const {
//    cout << thisDay << "." << thisMonth << "." << thisYear << endl;
//}

class Visit {
public:
    string date;
};
class Patient {
public:
    string FName, LName;
    string bDate;
    vector<Visit> visits;

    Patient(){}
    Patient(string FName, string LName, string bDate) {
        this->FName = FName;
        this->LName = LName;
        this->bDate = bDate;
    }
};
int main()
{
    Patient p1("Damyan", "Chakarov", "13.03.2005");
    vector<Patient> patients;
    
}