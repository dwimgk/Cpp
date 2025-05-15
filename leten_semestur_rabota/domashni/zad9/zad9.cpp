#include <iostream>
#include <vector>

using namespace std;

class Student {
	string egn;
	string fnum;
	double sr_usp;
public:
	void getData() {
		cout << "EGN: ";
		cin >> egn;
		cout << "Fakulteten nomer: ";
		cin >> fnum;
		cout << "Sreden uspeh (primer 4.49)";
		cin >> sr_usp;
	}
	void putData() {
		cout << "EGN: " << egn << endl;
		cout << "Fakulteten nomer: " << fnum << endl;
		cout << "Sreden uspeh: " << sr_usp << endl;
	}
};

int main()
{
	vector<Student> st;
	int n;
	cout << "Broi studenti: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		Student current;
		current.getData();
		st.push_back(current);
	}
	cout << endl;
	cout << "Infoto za studentite: " << endl;
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		st[i].putData();
		cout << endl;
	}


	return 0;
}