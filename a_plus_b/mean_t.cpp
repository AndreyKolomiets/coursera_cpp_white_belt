#include <iostream>
#include <vector>
using namespace std;

double mean(vector<int>& v) {
	double out = 0;
	int n = v.size();
	for (auto val: v) {
		out += val;
	}
	return out / n;
}

int main() {
	int n;
	cin >> n;
	int val;
	vector<int> v(n);
	for (int i=0; i < n; i++) {
		cin >> val;
		v[i] = val;
	}
	double mean_t = mean(v);
	int count = 0;
	for (int i=0; i<n; i++) {
			if (v[i] > mean_t) {
				count++;
			}
		}
	cout << count << endl;
	for (int i=0; i<n; i++) {
		if (v[i] > mean_t) {
			cout << i << " ";
		}
	}
	return 0;
}
