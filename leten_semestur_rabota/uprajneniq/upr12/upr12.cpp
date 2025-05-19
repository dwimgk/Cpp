#include <iostream>
#include <vector>

using namespace std;

class Earring {
public:
	string color, ear;
	double size;

	Earring(string color, double size, string ear) {
		this->color = color;
		this->size = size;
		this->ear = ear;
	}
};

class Drawer {
public:
	vector<Earring> jewelry;
	Drawer(vector<Earring> jewelry) {
		this->jewelry = jewelry;
	}
	int countPairs() {
		int pairs = 0;
		for (int i = 0; i < jewelry.size()-1; i++)
		{
			for (int j = i+1; j < jewelry.size(); j++)
			{
				if (jewelry[i].size == jewelry[j].size) {
					if ((jewelry[i].ear == "left" && jewelry[j].ear == "right") || (jewelry[i].ear == "right" && jewelry[j].ear == "left")) {
						pairs++;
					}
				}
			}
		}
		return pairs;
	}
};

int main()
{
	vector<Earring> earrings = {
		Earring("gold", 2.5, "left"),
		Earring("gold", 2.2, "right"),
		Earring("silver", 3.0, "left"),
		Earring("silver", 3.0, "right"),
		Earring("blue", 1.5, "left"),
		Earring("red", 1.5, "right")
	};

	Drawer drawer(earrings);
	cout << "Number of matching pairs: " << drawer.countPairs() << endl;

	return 0;
}