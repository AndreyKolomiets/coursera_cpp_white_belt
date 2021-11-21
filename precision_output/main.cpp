#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	ifstream input("input.txt");
	if (input) {
		double num;
		cout << fixed << setprecision(3);
		while (input >> num) {
			//input >> num;
			cout << num << endl;
		}
	}
	return 0;
}
