#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	map<string, string> vocab;
	for (int i=0; i<n; i++) {
		string command;
		cin >> command;
		if (command=="CHANGE_CAPITAL") {
			string country, new_capital;
			cin >> country >> new_capital;
			if (vocab.count(country)==0) {
				cout << "Introduce new country " <<country<<  " with capital " << new_capital << endl;
			} else {
				if (vocab[country]==new_capital) {
					cout << "Country " << country << " hasn't changed its capital" << endl;
				} else {
					cout << "Country " << country << " has changed its capital from " << vocab[country] << " to " << new_capital << endl;
				}
			}
			vocab[country] = new_capital;
		}
		if (command == "RENAME") {
			string old_country_name, new_country_name;
			cin >> old_country_name >> new_country_name;
			if ((old_country_name==new_country_name) || (vocab.count(old_country_name) == 0) || (vocab.count(new_country_name) == 1)) {
				cout << "Incorrect rename, skip" << endl;
			} else {
				cout << "Country " << old_country_name <<" with capital " << vocab[old_country_name] << " has been renamed to " << new_country_name << endl;
				string capital = vocab[old_country_name];
				vocab.erase(old_country_name);
				vocab[new_country_name] = capital;
			}
		}
		if (command == "ABOUT") {
			string country;
			cin >> country;
			if (vocab.count(country) == 0) {
				cout << "Country "<< country << " doesn't exist" << endl;
			} else {
				cout << "Country " << country << " has capital " << vocab[country] << endl;
			}
		}
		if (command == "DUMP") {
			if (vocab.size() == 0) {
				cout << "There are no countries in the world" << endl;
			} else {
				for (auto item: vocab) {
					cout << item.first << "/" << item.second << " ";
				}

				cout << endl;
			}
		}
	}
	return 0;
}
