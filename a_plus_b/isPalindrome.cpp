#include <vector>
#include <string>
using namespace std;

bool IsPalindrom(string s){
	int n = s.size();
	for (int i =0; i<n/2; i++) {
		if (s[i] != s[n-i-1]) {
			return false;
		}
	}
	return true;
}


vector<string> PalindromFilter(vector<string> words, int minLength) {
	vector<string> out;
	for (int i=0; i<words.size(); i++) {
		if ((words[i].size() >= minLength) & (IsPalindrom(words[i]))) {
			out.push_back(words[i]);
		}
	}
	return out;
}
