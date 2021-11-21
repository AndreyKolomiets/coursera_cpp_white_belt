#include <iostream>
#include <set>
using namespace std;

int main() {
	int n;
	cin >> n;
	string word;
	set<string> unique;
	for (int i=0; i<n; i++) {
		cin >> word;
		unique.insert(word);
	}
	cout << unique.size();
}
