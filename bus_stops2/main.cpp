#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
	int Q;
	cin >> Q;
	int curr_num=1;
	map<vector<string>, int> buses;
	for (int i=0; i<Q; i++) {
		vector<string> stops;
		int count;
		cin >> count;
		for (int j=0; j<count; j++) {
			string stop;
			cin >> stop;
			stops.push_back(stop);
		}
		if (buses.count(stops) == 1) {
			cout << "Already exists for " << buses[stops] << endl;
		} else {
			buses[stops] = curr_num;
			cout << "New bus " << curr_num << endl;
			curr_num++;
		}
	}
	return 0;
}
