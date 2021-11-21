#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

void PrintVec(vector<string> v) {
	for (auto v_i: v) {
		cout << v_i << " ";

	}
	cout << endl;
}

void PrintVecWoElement(vector<string> v, string elem) {
	for (auto v_i: v) {
		if (v_i != elem) {
			cout << v_i << " ";
			}
		}
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	string command;
	map<string, vector<string> > buses;
	map<string, vector<string> > stops;
	for (int i=0; i<n; i++) {
		cin >> command;
		if (command == "NEW_BUS") {
			string bus;
			cin >> bus;
			int stop_count;
			cin >> stop_count;
			for (int j=0; j<stop_count; j++) {
				string stop_j;
				cin >> stop_j;
				buses[bus].push_back(stop_j);
				stops[stop_j].push_back(bus);
			}
		}
		if (command == "BUSES_FOR_STOP") {
			string stop;
			cin >> stop;
			if (stops.count(stop) == 0) {
				cout << "No stop" << endl;
			} else {
				PrintVec(stops[stop]);
			}
		}
		if (command == "STOPS_FOR_BUS") {
			string bus;
			cin >> bus;
			if (buses.count(bus) == 0) {
				cout << "No bus" << endl;
			} else {
				for (string stop: buses[bus]) {
					cout << "Stop " << stop << ": ";
					if (stops[stop].size() > 1) {
						PrintVecWoElement(stops[stop], bus);
					} else {
						cout << "no interchange" << endl;
					}
				}

			}
		}
		if (command == "ALL_BUSES") {
			if (buses.size() ==0) {
				cout << "No buses" << endl;

			} else {
				for (auto item: buses) {
					cout << "Bus " << item.first << ": ";
					PrintVec(item.second);
				}
			}
		}
	}

	return 0;
}
