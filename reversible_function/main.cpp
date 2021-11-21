#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//struct Image {
//  double quality;
//  double freshness;
//  double rating;
//};
//
//struct Params {
//  double a;
//  double b;
//  double c;
//};

class FunctionPart {
public:
	FunctionPart(char new_op, double new_value) {
		op = new_op;
		value = new_value;
	}
	double Apply(double source_value) const {
		if (op == '+') {
			return value+source_value;
		} else if (op == '-') {
			return source_value - value;
		} else if (op == '*') {
			return source_value * value;
		} else {
			return source_value / value;
		}
	}
	void Invert() {
		if (op=='+') {
			op = '-';
		} else if (op=='-') {
			op = '+';
		} else if (op == '*') {
			op = '/';
		} else {
			op = '*';
		}
	}
private:
	char op;
	double value;
};

class Function {
public:
	void AddPart(char op, double value) {
		operations.push_back({op, value});
	};
	double Apply(double inp) const {
		for (const auto& part: operations) {
			inp = part.Apply(inp);
		}
		return inp;
	};
	void Invert() {
		for (FunctionPart& part: operations) {
			part.Invert();
		}
		reverse(begin(operations), end(operations));
	};
private:
	vector<FunctionPart> operations;
};

//Function MakeWeightFunction(const Params& params,
//                            const Image& image) {
//  Function function;
//  function.AddPart('-', image.freshness * params.a + params.b);
//  function.AddPart('+', image.rating * params.c);
//  return function;
//}
//
//double ComputeImageWeight(const Params& params, const Image& image) {
//  Function function = MakeWeightFunction(params, image);
//  return function.Apply(image.quality);
//}
//
//double ComputeQualityByWeight(const Params& params,
//                              const Image& image,
//                              double weight) {
//  Function function = MakeWeightFunction(params, image);
//  function.Invert();
//  return function.Apply(weight);
//}
//
//int main() {
//  Image image = {10, 2, 6};
//  Params params = {4, 2, 6};
//  cout << ComputeImageWeight(params, image) << endl;
//  cout << ComputeQualityByWeight(params, image, 46) << endl;
//  return 0;
//}
