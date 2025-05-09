#include <iostream>
#include <vector>

using namespace std;

class Budget {
private:
    double uni_budget;
    vector<double> faculty_budget;
    double administry_budget;
public:
    Budget() {}

    Budget(vector<double> FacBud, double UniBud, double AdminBud) {
        this->faculty_budget = FacBud;
        this->uni_budget = UniBud;
        this->administry_budget = AdminBud;
    }


    double getFacBudget(int n) {
        if (n <= faculty_budget.size()) {
            return faculty_budget[n];
        }
        else return -1;
    }
    double getUniBudget() {
        return uni_budget;
    }
    double getAdminBudget() {
        return administry_budget;
    }

    void addFaculty_toUniBudget(double chosenFac) {
        cout << "Previous budget : " << uni_budget << endl;
        uni_budget += chosenFac;
        cout << "Updated Uni budget : " << uni_budget << endl;
        return;
    }
    void addAdmin_toUniBudget() {
        cout << "Previous budget : " << uni_budget << endl;
        uni_budget += administry_budget;
        cout << "Updated Uni budget : " << uni_budget << endl;
        return;
    }
};

int main()
{
    vector<double> facultyBudgets_byID;
    facultyBudgets_byID.push_back(200);
    facultyBudgets_byID.push_back(300);
    facultyBudgets_byID.push_back(400);

    Budget myUNI(facultyBudgets_byID, 5000, 450);

    myUNI.addFaculty_toUniBudget(facultyBudgets_byID[0]);
    cout << endl;
    myUNI.addAdmin_toUniBudget();
    cout << endl;
    double chosenFac = 0;
    chosenFac = myUNI.getFacBudget(0);
    cout << "Chosen Faculty has a budget of " << chosenFac << endl;
    chosenFac = myUNI.getFacBudget(1);
    cout << "Chosen Faculty has a budget of " << chosenFac << endl;
    chosenFac = myUNI.getFacBudget(2);
    cout << "Chosen Faculty has a budget of " << chosenFac << endl;
    cout << endl;
    double adminBudget = myUNI.getAdminBudget();
    cout << "Administry has a budget of " << adminBudget << endl;
    cout << endl;
    cout << endl;
    double UniBudgetOverall = myUNI.getUniBudget();
    cout << "The University has an overall budget of " << UniBudgetOverall << endl;
}