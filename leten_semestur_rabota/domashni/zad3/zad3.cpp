#include <iostream>
using namespace std;

class Employee {
public:
    struct Name {
        string first, last;
    };
    struct Work {
        float hours;
        float salary;
    };
    
    float Zaplata(float hours, float salary) {
        return (hours * salary);
    }
};
int main()
{
    Employee employee1;
    Employee::Name employeeName;
    Employee::Work employeeWork;

    cout << "ime: ";
    cin >> employeeName.first;
    cout << "familiq: ";
    cin >> employeeName.last;

    cout << "hours: ";
    cin >> employeeWork.hours;
    cout << "salary: ";
    cin >> employeeWork.salary;

    float zaplata = employee1.Zaplata(employeeWork.hours, employeeWork.salary);

    cout << "Employee " << employeeName.first << " " << employeeName.last << " has worked " << employeeWork.hours << " hours with an hourly wage of " << employeeWork.salary << endl;
    cout << "They have received this amount: " << zaplata << endl;
}