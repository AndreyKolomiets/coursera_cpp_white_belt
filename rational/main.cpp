#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
#include <exception>

using namespace std;

int gcd(int a, int b) {
	//	int a,b, r1, r2, new_r2;
	//		cin >> a >> b;
		while ((a>0) & (b>0)) {
			if (a > b) {
				a = a%b;
			} else {
				b = b % a;
			}
		}
		return a+b;
}

class Rational {
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
    	this->numerator = 0;
    	this->denominator = 1;
    }

    Rational(int numerator, int denominator) {
        // Реализуйте конструктор
    	if (denominator == 0) {
    		throw invalid_argument("Invalid argument");
    	}
    	int g = gcd(abs(numerator), abs(denominator));
    	if (((numerator < 0) && (denominator < 0)) || (((numerator > 0) && (denominator < 0)))) {
    		numerator *= -1;
    		denominator *= -1;
    	} else if ((numerator == 0) && (denominator < 0)) {
    		denominator *= -1;
    	}
    	this->numerator = numerator / g;
    	this->denominator = denominator / g;
    }

    int Numerator() const {
        // Реализуйте этот метод
    	return numerator;

    }

    int Denominator() const {
        // Реализуйте этот метод
    	return denominator;
    }

private:
    // Добавьте поля
    int numerator;
    int denominator;
};

bool operator==(const Rational& lhs, const Rational& rhs) {
	return (lhs.Numerator()==rhs.Numerator()) && (lhs.Denominator()==rhs.Denominator());
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
	int new_d = lhs.Denominator() * rhs.Denominator();
	int new_n = lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator();
	return Rational{new_n, new_d};
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
	int new_d = lhs.Denominator() * rhs.Denominator();
	int new_n = lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator();
	return Rational{new_n, new_d};
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
	int new_d = lhs.Denominator() * rhs.Denominator();
	int new_n = lhs.Numerator() * rhs.Numerator();
	return Rational{new_n, new_d};
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
	int new_d = lhs.Denominator() * rhs.Numerator();
	int new_n = lhs.Numerator() * rhs.Denominator();
	if (new_d==0) {
		throw domain_error("Division by zero");
	}
	return Rational{new_n, new_d};
}

ostream& operator<<(ostream& stream, const Rational& r) {
	stream << r.Numerator() << "/" << r.Denominator();
	return stream;
}


istream& operator >> (istream& s, Rational& n) {
	int a, b;
	char c;

	s >> a >> c >> b;

	if (s && c == '/')
		n = Rational(a, b);

	return (s);
}

bool operator<(const Rational& lhs, const Rational rhs) {
	Rational diff = rhs - lhs;
	return diff.Numerator() > 0;
}
int main() {
	Rational left, right;
    char op;
    try {
    	cin >> left >> op >> right;
    } catch (invalid_argument& ex) {
    	cout << ex.what();
    	return 1;
    }
    try {
		if (op == '/') {
			 cout << left / right;
		} else if (op=='*') {
			cout << left * right;
		}else if (op == '+') {
			cout << left + right;
		} else if (op == '-') {
			cout << left - right;
		}
    } catch (domain_error& ex) {
    	cout << ex.what();
    	return 2;
    }
    return 0;
}
