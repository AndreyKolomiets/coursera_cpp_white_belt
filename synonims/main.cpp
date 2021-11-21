#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string command, word1, word2;
	map<string, set<string> > vocab;
	for (int i=0; i<n; i++) {
		cin >> command;
		if (command == "ADD") {
			cin >> word1 >> word2;
			vocab[word1].insert(word2);
			vocab[word2].insert(word1);
		}
		if (command == "COUNT") {
			cin >> word1;
			cout << vocab[word1].size() << endl;
		}
		if (command == "CHECK") {
			cin >> word1 >> word2;
			if (vocab[word1].count(word2)==1) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}
