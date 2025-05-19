#include <iostream>
#include <vector>

using namespace std;

class Book {
public:
    vector<string> pages;
    Book(vector<string> pages) {
        this->pages = pages;
    }

    string shortestPage() {
        string shortest = this->pages[0];
        for (int i = 1; i < pages.size(); i++)
        {
            if (pages[i].length() < shortest.length())
            {
                shortest = pages[i];
            }
        }
        return shortest;
    }

    Book& operator+ (string newPage) {
        this->pages.push_back(newPage);
    }
    
    operator string() {
        string full = "";
        for (int i = 0; i < pages.size(); i++)
        {
            full += pages[i] +"; ";
        }
        return full.substr(0, full.size() - 1);
    }
};

int main()
{
    vector<string> bookVector{ "Zdraveite!", "Az sum Damyan Chakarov.", "Ucha vuv VVMU!" };

    Book b(bookVector);
    string test1Shortest = b.shortestPage();
    cout << test1Shortest << endl;
    string test1 = (string)b;
    cout << test1 << endl;
    cout << endl;

    b + "Goodbye!";
    string test2 = (string)b;
    string test2Shortest = b.shortestPage();
    cout << test2Shortest << endl;
    cout << test2 << endl;

    return 0;
}