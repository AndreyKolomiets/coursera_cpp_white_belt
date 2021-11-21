#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

bool cmp_abs(int& x, int& y) {
	return abs(x) < abs(y);
}

int main() {
	int count;
	cin >> count;
	vector<int> x;
	for (int i=0; i<count; i++) {
		int num;
		cin >> num;
		x.push_back(num);

	}
	sort(begin(x), end(x), cmp_abs);
	for (auto c: x) {
		cout << c << " ";
	}
	return 0;
}
