#include <iostream>
#include <vector>

using namespace std;

class Contact {
public:
    string name;
    string phone;
    string email;

    Contact(){}
    Contact(string name, string phone, string email) {
        this->name = name;
        this->phone = phone;
        this->email = email;
    }
};

ostream& operator<<(ostream& o, Contact& c) {
    o << c.name << ", " << c.phone << ", " << c.email << endl;
    return o;
}

class PhoneBook {
public:
    vector<Contact> contacts;

    PhoneBook operator+(Contact& c) {
        contacts.push_back(c);
        return *this;
    }
    bool operator==(string name) {
        for (Contact c : contacts) {
            if (c.name == name) return true;
        }
        return false;
    }

    vector<Contact> findByEmail(string m) {
        vector<Contact> results;

        for (Contact c : contacts) {
            int at_pos = -1; //@naval.acad-bg zaradi takuv keis, zashtoto tuk i 0 e validno, zatova zadavame default stoinost da e nqkakva nevalidna
            for (int i = 0;i < c.email.length();i++) {
                if (c.email[i] == '@') at_pos = i;
            }

            string domain = c.email.substr(at_pos + 1, c.email.length() - at_pos);
            if (domain == m) results.push_back(c);
        }
        return results;
    }
};


int main()
{
    Contact c1("ivan", "12345", "abc@def.com");
    Contact c2("dragan", "56789", "xyz@google.com");
    Contact c3("pesho", "56789", "xyzab@google.com");
    Contact c4("misho", "56789", "def@google.com");
    Contact c5("mariq", "56789", "1234@google.com");
    PhoneBook book;
    book.contacts = { c1,c2,c3 };
    book = book + c4;
    book = book + c5;
    if (book == "dragan") cout << "ima dragan" << endl;

    for (Contact c : book.findByEmail("google.com")) {
        cout << c;
    }



    //tipizaciq na tipa (s drugi dumi)
    //neshtosi e promenliva tip vector, ot tip int
    //
    //vector e bezkraen masiv kinda
    //vector<int> neshto_si;

    //int matrix[10][10];
    //vector<vector<int>> matrix2;

    //neshto_si.push_back(10); //dobavqne
    //neshto_si[0]; //0 element, 10kata
    //neshto_si.size(); //goleminata
    //neshto_si.pop_back(); // premahvane na posledniq
    ////
    return 0;
}