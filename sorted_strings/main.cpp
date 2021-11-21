#include <vector>
#include <set>
#include <map>
#include <string>
#include <iostream>
using namespace std;


class SortedStrings {
public:
  void AddString(const string& s) {
    // добавить строку s в набор
	  strings[s]++;
  }
  vector<string> GetSortedStrings() {
    // получить набор из всех добавленных строк в отсортированном порядке
	  vector<string> out;
	  for (auto& s_i: strings) {
		  for (int j=0; j<s_i.second; j++) {
			  out.push_back(s_i.first);
		  }
	  }
	  return out;
  }
private:
  // приватные поля
  map<string, int> strings;
};


void PrintSortedStrings(SortedStrings& strings) {
  for (const string& s : strings.GetSortedStrings()) {
    cout << s << " ";
  }
  cout << endl;
}

int main() {
  SortedStrings strings;

  strings.AddString("first");
  strings.AddString("third");
  strings.AddString("second");
  PrintSortedStrings(strings);

  strings.AddString("second");
  PrintSortedStrings(strings);

  return 0;
}
