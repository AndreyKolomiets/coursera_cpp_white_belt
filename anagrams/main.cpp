#include <iostream>
#include <map>
#include <string>
using namespace std;


map<char,int> BuildCounter(string word) {
	map<char,int> out;
	for (char c: word) {
		out[c]++;
	}
	return out;
}

bool isMapEqual(map<char,int> a, map<char,int> b) {
	if (a.size() != b.size()) {
		return false;
	}
	for (const auto& item: a){
		if ((b.count(item.first) == 0) || (b[item.first] != item.second)) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		string a, b;
		cin >> a >> b;
		map<char,int> cnt_a, cnt_b;
		cnt_a = BuildCounter(a);
		cnt_b = BuildCounter(b);
		if (isMapEqual(cnt_a, cnt_b)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
