#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


struct Student {
	string name;
	string surname;
	int day;
	int month;
	int year;
};

int main() {
	int N;
	cin >> N;
	vector<Student> students(N);
	for (Student& item: students) {
		string name, surname;
		int day, month, year;
		cin >> name >> surname >> day >> month >> year;
		item = {name, surname, day, month, year};
	}
	int M;
	cin >> M;
	for (int i=0; i<M; i++) {
		string value;
		int K;
		cin >> value >> K;
		if (((value != "date") && (value != "name")) || (K>N) || (K<1) ) {
			cout << "bad request" << endl;
		} else {
			Student curr_student = students[K-1];
			if (value == "date") {

				cout << curr_student.day << "." << curr_student.month << "." << curr_student.year << endl;
			} else if (value == "name") {
				cout << curr_student.name << " " << curr_student.surname << endl;
			}
		}
	}
	return 0;
}
