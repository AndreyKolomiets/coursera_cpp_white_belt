#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
	ifstream input("input.txt");
	if (input) {
		string line;
		ofstream output("output.txt");
		while (getline(input, line)) {
			//cout << line << endl;

			output << line << endl;
		}
	}
	return 0;
}
