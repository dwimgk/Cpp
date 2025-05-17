#include <iostream>
#include <string.h>

using namespace std;

class People {
    char* name;
    char* egn;
public:
    void readPeople(const char*str, const char*num) {
        name = new char[strlen(str) + 1];
        strcpy(name, str);
        egn = new char[11];
        strcpy(egn, num);
    }
    void printPeople() const {
        cout << "Ime: " << name << endl;
        cout << "EGN: " << egn << endl;
    }
};

class Student :public People {  
    long facnum;
    double uspeh;
public:
    void readStudent(const char* str, const char* num, long facn, double uspeh) {
        readPeople(str, num);
        facnum = facn;
        this->uspeh = uspeh;
    }
    void printStudent() const {
        printPeople();
        cout << "Fakulteten nomer: " << facnum << endl;
        cout << "Uspeh: " << uspeh << endl;
    }

};

int main()
{
    Student stud;
    stud.readStudent("Damyan Chakarov", "0543xxxxxx", 14124115, 6.0);
    stud.printStudent();
}