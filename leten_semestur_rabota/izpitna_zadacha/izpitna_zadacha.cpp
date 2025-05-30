#include <iostream>
#include <vector>

using namespace std;

class BankAccount {
public:
    double balance;
    string name, IBAN;

    BankAccount(string name, string IBAN) {
        this->balance = 0.0;
        this->name = name;
        this->IBAN = IBAN;
    }
};

class Bank {
public:
    vector<BankAccount> accounts;

    Bank() {
        vector<BankAccount> accounts = {};
    }

    double fullBalance() {
        double fullBalance = 0.0;
        for (int i = 0; i < accounts.size(); i++)
        {
            fullBalance += accounts[i].balance;
        }

        return fullBalance;
    }
};

int main()
{
    BankAccount first = {"Ivan", "10bg12345678"};
    BankAccount second = {"Damyan", "13bg87654321" };
    second.balance = 250.50;
    BankAccount third = {"Ilia", "19bg87654321" };
    third.balance = 350.88;
    BankAccount fourth = {"John Doe", "88bg87654321" };
    fourth.balance = 100.99;
    BankAccount fifth = {"Hristina", "26bg87654321" };
    fifth.balance = 250;

    Bank DSK;
    DSK.accounts.push_back(first);
    DSK.accounts.push_back(second);
    DSK.accounts.push_back(third);
    DSK.accounts.push_back(fourth);
    DSK.accounts.push_back(fifth);

    double DSKBalance = DSK.fullBalance();
    cout << "DSK ima sumaren balans na vsichki potrebiteli ot " << DSKBalance << " leva." << endl;

    return 0;
}