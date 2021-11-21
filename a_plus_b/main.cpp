/*
 * main.cpp
 *
 *  Created on: 28 окт. 2021 г.
 *      Author: ak
 */

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

//int main() {
//  int a, b;
//  cin >> a >> b;
//  cout << a + b;
//  return 0;
//}

//int main() {
//	string a, b, c, min;
//	cin >> a >> b >> c;
//	bool ab = a < b;
//	bool ac = a < c;
//	bool bc = b < c;
//	if (ab) {
//		if (bc) {
//			min = a;
//		} else {
//			if (ac) {
//				min = a;
//			} else {
//				min = c;
//			}
//		}
//	} else {
//		if (!bc) {
//			min = c;
//		} else {
//			if (ac) {
//				min = a;
//			} else {
//				min = b;
//			}
//		}
//	}
//	min = a;
//	if (b<min) {
//		min = b;
//	}
//	if (c < min) {
//		min = c;
//	}
//	cout << min;

//	double a, b, c;
//	cin >> a >> b >> c;
//	if (a != 0) {
//		double dsq = b*b-4*a*c;
//		if (dsq >= 0) {
//
//			double d = sqrt(dsq);
//			double x1 = (-b+d)/2/a;
//			double x2 = (-b-d)/2/a;
//
//			if (d != 0) {
//				cout << x1 << " " << x2;
//			} else {
//				cout << x1;
//			}
//		}
//	} else {
//		if (b != 0) {
//			double x = -c / b;
//			cout << x;
//		}
//	}
//	int a, b;
//	cin >> a >> b;
//	if (b==0) {
//		cout << "Impossible";
//	} else {
//		int div = a / b;
//		cout << div;
//	}
//	double N, A, B, X, Y;
//	cin >> N >> A >> B >> X >> Y;
//	double discount;
//	if (N <= A) {
//		discount  = 0;
//	} else {
//		if (N > B) {
//			discount = Y;
//		} else {
//			discount = X;
//		}
//	}
//	double new_price = N * (100-discount) / 100;
//	cout << new_price;
//	int A, B;
//	cin >> A >> B;
//	for (int i=A; i<=B; i++) {
//		if (i%2 == 0) {
//			cout << i << ' ';
//		}
//	}
//	string s;
//	cin >> s;
//	int cnt = 0;
//	int i = 0;
//	while ((i < s.length()) && (cnt < 2)) {
//		if (s[i] == 'f') {
//			cnt++;
//		}
//		i++;
//		//cout << s[i] << ' ' << i << ' ' << cnt << endl;
//	}
//	if (cnt == 0) {
//		cout << -2;
//	}
//	if (cnt == 1) {
//		cout << -1;
//	}
//	if (cnt == 2) {
//		cout << i-1;
//	}


//	r1 = a % b;
//	cout << r1 << endl;
//	if (r1==0) {
//
//		cout << b << " first";
//	}
//	if (r1!=0) {
//		r2 = b % r1;
////		if (r2 == 0) {
////			cout << a<<" second";
////		}
//	}
//	if ((r1!=0)&&(r2!=0)) {
//		while (r2 != 0) {
//			new_r2 = r1 % r2;
//			if (new_r2 == 0) {
//				cout << r2;
//				return 0;
//			} else {
//				r1 = r2;
//				r2 = new_r2;
//			}
//		}
//	}

//	int a,b, r1, r2, new_r2;
//		cin >> a >> b;
//	while ((a>0) & (b>0)) {
//		if (a > b) {
//			a = a%b;
//		} else {
//			b = b % a;
//		}
//	}
//	cout << a+b;

//	int x;
//	cin >> x;
//	vector<int> digits;
//	while (x >= 1) {
//		digits.push_back(x%2);
//		//cout << x << " " << x%2 << endl;
//		x = x / 2;
//	}
//	int n = digits.size();
//	if (digits[n-1] == 1) {
//		cout << 1;
//	}
//	for (int i = n-2; i>=0; --i) {
//		cout << digits[i];
//	}
//	return 0;
//}


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
