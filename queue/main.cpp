#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print_vector(vector<int> v) {
	for (auto s: v) {
		cout << s << " ";
	}
}


int main() {
	int q;
	cin >> q;
	vector<int> queue;
	for (int i=0; i<q; i++) {
		string command;
		cin >> command;
		if (command == "WORRY") {
			int ith;
			cin >> ith;
			queue[ith] = 1;
			//print_vector(queue);
		}
		if (command == "QUIET") {
			int ith;
			cin >> ith;
			queue[ith] = 0;
			//print_vector(queue);
		}
		if (command == "COME") {
			int k;
			cin >> k;
			if (k > 0) {
				for (int j = 0; j<k; j++) {
					queue.push_back(0);
				}
			} else {
				for (int u=-k; u>0; u--) {
					queue.pop_back();
				}
			}
			//print_vector(queue);
		}
		if (command == "WORRY_COUNT") {
			int cnt = 0;
			for (int p: queue) {
				cnt += p;
			}
			cout << cnt << endl;
		}
	}
	return 0;
}
