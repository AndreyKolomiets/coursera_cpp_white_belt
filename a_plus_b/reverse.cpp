#include <vector>
using namespace std;

void Reverse(vector<int>& v){
	int n = v.size();
	for (int i=0; i < n/2; i++) {
		int tmp = v[i];
		v[i] = v[n-i-1];
		v[n-i-1] = tmp;
	}
}
