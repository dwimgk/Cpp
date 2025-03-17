#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Visit {
public:
    string date;

    Visit(string date) {
        this->date = date;
    }

};
class Patient {
public:
    string FName, LName;
    string bDate;
    vector<Visit> visits;

    Patient(){}
    Patient(string FName, string LName, string bDate, vector<Visit> visits) {
        this->FName = FName;
        this->LName = LName;
        this->bDate = bDate;
        this->visits = visits;
    }
};
int main()
{
    vector<Visit> visits1 = { Visit("01.01.2024"), Visit("15.02.2024") };
    vector<Visit> visits2 = { Visit("10.03.2023") };
    vector<Visit> visits3 = { Visit("01.01.2024"), Visit("02.01.2024"), Visit("03.01.2024"), Visit("04.01.2024"), Visit("05.01.2024"), Visit("06.01.2024")};

    vector<Patient> patients;

    Patient p1("Damyan", "Chakarov", "13.03.2005", visits1);
    Patient p2("Ilia", "Chakarov", "19.07.1999", visits2);
    Patient p3("Hristina", "Gincheva", "26.01.2005", visits3);

    patients.push_back(p1);
    patients[0].visits.push_back(Visit("20.03.2025"));
    patients.push_back(p2);
    patients.push_back(p3);
    
    cout << "sreden broi poseshteniq: 5" << endl;
    for (Patient p : patients) {
        cout << "Patient: " << p.FName << " " << p.LName << "\n";
        cout << "Birthdate: " << p.bDate << "\n";
        cout << "Visits: ";
        for (Visit visit : p.visits) {
            cout << visit.date << " ";
        }
        cout << endl;
        double avg = p.visits.size();
        cout << "Avg. visits: " << avg / 2 << endl;
        if (avg > 5) {
            cout << "Tova e poveche ot zadadeniq broi poseshteniq.";
        }
        cout << "\n\n";
    }
}