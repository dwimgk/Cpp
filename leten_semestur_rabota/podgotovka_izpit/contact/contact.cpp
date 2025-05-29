#include <iostream>
#include <vector>

using namespace std;

class Contact {
public:
    string name, number, workplace;
};

class Phonebook {
public:
    vector<Contact> contacts;

    void operator+(const Contact& c) {
        bool name_repeat = false;
        for (int i = 0; i < contacts.size(); i++)
        {
            if (contacts[i].name == c.name) {
                name_repeat = true;
                contacts[i].number = c.number;
                contacts[i].workplace = c.workplace;
            }
        }
        if (!name_repeat) {
            contacts.push_back(c);
            return;
        }
    }
};

int main()
{
    Phonebook book;
    Contact c1{ "John", "123456", "Tech Corp" };
    Contact c2{ "John", "789012", "VVMU" };
    Contact c3{ "Alice", "345678", "School" };

    book + c1;
    book + c2;
    book + c3;

    for (Contact contact : book.contacts) {
        cout << contact.name << ": " << contact.number << ", " << contact.workplace << endl;
    }
    return 0;
}