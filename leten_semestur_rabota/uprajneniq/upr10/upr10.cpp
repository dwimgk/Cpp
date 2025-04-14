#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

/*
Iskame da napravim auto-suggest, baziran na:
-input, koito sme napisali v konzolata;
- informaciq, koqto e predvaritelno skladirana vuv fail

ideqta e da namerim vsichki chasti ot pisanoto, v nqkoi ot redovete na faila
(ako priemem, che vuv faila ima imena na hora, i nie tursim v konzolata po samo chast ot purvo i chast ot familiq, trqvwa da
uspeem da namerim suvpadenie, bez da ima znachenie che sme izpusnali prezimeto)
*/

vector<string> tokenize(string input) {
    vector<string> results;
    string temp;

    int startOfWord = 0;
    for(char c : input)
    {
        if (c != ' ' && c != '\r' && c != '\n') {
            temp += c;
        }
        else {
            results.push_back(temp);
            temp = "";
        }
    }
    results.push_back(temp);
    return results;
}

bool containsEvery(vector<string> in, vector<string> other) {
    vector<bool> found;
    for (string s : in) found.push_back(false);

    for (int i = 0; i < in.size(); i++)
    {
        string tmp = in[i];

        for (string other_word : other) {
            if (other_word.find(tmp) != string::npos) found[i] = true;
        }
    }

    for (bool val : found) {
        if (!val) return false;
    }
    return true;
}

int main()
{
    ifstream in;
    in.open("D:\\C++\\leten_semestur_rabota\\uprajneniq\\upr10\\Names.txt");
    string buffer;
    string userInput;
    cout << "Type in your search: ";
    cin >> userInput;
    vector<string> user_token = tokenize(userInput);

    while (!getline(in, buffer).eof()) {
        vector<string> file_tokens = tokenize(buffer);

        if (containsEvery(user_token, file_tokens)) {
            cout << "Found a match: " << buffer;
        }
        cout << endl;
    }



    /*string x;
    in >> x;
    cout << "kotki" << endl;*/
    in.close();
    return 0;
}