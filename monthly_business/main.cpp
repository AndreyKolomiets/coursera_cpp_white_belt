#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void PrintVec(vector<string> v) {
	for (auto v_i: v) {
		cout << v_i << " ";

	}
	cout << endl;
}

int main() {
	vector<int> month_lengths(12);
	//month_lengths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	month_lengths[0] = 31;
	month_lengths[1] = 28;
	month_lengths[2] = 31;
	month_lengths[3] = 30;
	month_lengths[4] = 31;
	month_lengths[5] = 30;
	month_lengths[6] = 31;
	month_lengths[7] = 31;
	month_lengths[8] = 30;
	month_lengths[9] = 31;
	month_lengths[10] = 30;
	month_lengths[11] = 31;
	int Q;
	cin >> Q;
	vector<vector<string> > calendar(31);
	int month_num = 0;
	for (int i=0; i<Q; i++) {
		string op;
		cin >> op;
		if (op=="ADD") {
			int day;
			string business;
			cin >> day >> business;
			calendar[day-1].push_back(business);
			//cout << "ADD succesfull" << endl;

		}
		if (op=="NEXT") {
			month_num++;
			if (month_num == 12) {
				month_num = 0;
			}
			int n_days = month_lengths[month_num];
			vector<vector<string> > new_calendar(n_days);
			for (int j=0; j<min(calendar.size(), new_calendar.size()); j++) {
				new_calendar[j] = calendar[j];
			}
			if (new_calendar.size() < calendar.size()) {
				for (int k=n_days; k<calendar.size(); k++) {
					new_calendar[n_days-1].insert(end(new_calendar[n_days-1]), begin(calendar[k]), end(calendar[k]));
				}


			}
			calendar = new_calendar;
			//cout << "NEXT succesfull" << endl;
		}
		if (op=="DUMP") {
			int day;
			cin >> day;
			//cout << "DUMP day cin succesfull" << endl;
			cout << calendar[day-1].size() << " ";
			//cout << "Size of calendar=" << calendar.size();
			//cout << "DUMP n_businesses succesfull" << endl;
			for (string b: calendar[day-1]) {
				cout << b << " ";
				//cout << "! ";
			}
			cout << endl;
			//cout << "DUMP succesfull" << endl;
		}
	}
	return 0;
}
