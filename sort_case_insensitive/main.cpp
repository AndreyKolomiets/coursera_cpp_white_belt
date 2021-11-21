#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <string>
using namespace std;

string tolower_string(string s) {
	string out;
	for (auto c: s) {
		out.push_back(tolower(c));
	}
	return out;
}

bool cmp_case_insensitive(string x, string y) {
	return tolower_string(x) < tolower_string(y);
}


int main() {
	int N;
	cin >> N;
	vector<string> s(N);
	for (auto& s_i: s) {
		cin >> s_i;
	}
	sort(begin(s), end(s), cmp_case_insensitive);
	for (const auto& s_i: s) {
		cout << s_i << " ";
	}
	return 0;
}
