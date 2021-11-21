#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

void PrintVec(const vector<int>& v) {
	for (auto val: v) {
		cout << val << " ";

	}
	cout << endl;
}

int main() {
	ifstream input("input.txt");
	int n_rows, n_cols;
	input >> n_rows >> n_cols;
	input.ignore(1);
	string new_line;
//	getline(input, new_line);
//	cout << new_line;
	//cout << "n_rows=" << n_rows << ", n_cols=" << n_cols << endl;
	for (int i=0; i<n_rows; i++) {
		for (int j=0; j < n_cols; j++) {
			if (j<n_cols-1) {
				getline(input, new_line, ',');
				cout << setw(10) << new_line << " ";
			} else {
				getline(input, new_line, '\n');
				cout << setw(10) << new_line;
			}
			//cout << new_line << endl;

		}
		if (i != n_rows -1) {
			cout << endl;
		}
		//input.ignore(1);
	}
	return 0;
}
