#include <iostream>
#include <vector>

using namespace std;

class Book {
public:
    vector<string> pages;

    Book(vector<string> pages) {
        this->pages = pages;
    }

    string shortest() {
        string shortest = pages[0];
        for (int i = 0; i < pages.size(); i++)
        {
            if (pages[i].size() < shortest.size()) {
                shortest = pages[i];
            }
        }
        return shortest;
    }

    void operator+(string page){
        pages.push_back(page);
    }

    operator string() {
        string full = "";
        for (int i = 0; i < pages.size() - 1; i++)
        {
            full += pages[i] + "; ";
        }
        full += pages[pages.size() - 1];
        return full;
    }
};

int main()
{
    Book myBook({ "Introduction", "Chapter 1", "Chapter 2", "Conclusion" });
    cout << "content: " << string(myBook) << endl;
    cout << "shortest: " << myBook.shortest() << endl;
    myBook + "Appendix";

    cout << "updated content: " << string(myBook) << endl;
    cout << endl;
    Book secondBook({ "A", "Longer page", "Very long content" });
    cout << "content: " << string(secondBook) << endl;
    cout << "Shortest: " << secondBook.shortest() << endl;
    secondBook + "Short";
    secondBook + "Extremely long page content";
    cout << "updated content " << string(secondBook) << endl;
    cout << "new shortest page: " << secondBook.shortest() << endl;
    return 0;
}