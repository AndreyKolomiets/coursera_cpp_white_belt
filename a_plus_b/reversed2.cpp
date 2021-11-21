#include <vector>
using namespace std;


vector<int> Reversed(const vector<int>& v) {
	vector<int> out;
	for (int i = v.size()-1; i>=0; i--) {
		out.push_back(v[i]);
	}
	return out;
}
