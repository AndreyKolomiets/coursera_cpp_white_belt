#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <initializer_list>
#include <algorithm>
using namespace std;

struct Change {
	string first_name;
	string last_name;
};

void PrintDict(const map<int, string>& dct) {
	for (auto& item: dct) {
		cout << item.first << ": " << item.second << " | ";
	}
	cout << endl;
}

void PrintVec(const vector<int>& v) {
	for (auto& item: v) {
		cout << item << " ";
	}
	cout << endl;
}

class Person {
public:
	Person(string first_name, string last_name, int year_of_birth) {
		birth_year = year_of_birth;
		ChangeFirstName(year_of_birth, first_name);
		ChangeLastName(year_of_birth, last_name);

	}
  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
	  if (year >= birth_year) {
		  name_changes[year] = first_name;
		  name_change_years.push_back(year);
		  sort(begin(name_change_years), end(name_change_years));
	  }
//	  PrintDict(name_changes);
//	  PrintDict(last_name_changes);
//	  cout << endl;
//	  cout << "first name change years: ";
//	  PrintVec(name_change_years);
//	  cout << "last name change years: ";
//	  PrintVec(last_name_change_years);
//	  cout << endl;
  }
  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
	  if (year >= birth_year) {
		  last_name_changes[year] = last_name;
		  last_name_change_years.push_back(year);
		  sort(begin(last_name_change_years), end(last_name_change_years));
	  }
//	  PrintDict(name_changes);
//	  PrintDict(last_name_changes);
//	  cout << endl;
//	  cout << "first name change years: ";
//	  PrintVec(name_change_years);
//	  cout << "last name change years: ";
//	  PrintVec(last_name_change_years);
//	  cout << endl;
  }
  string GetFullName(int year) const {
	  if (year < birth_year) {
		  return "No person";
	  }
    // получить имя и фамилию по состоянию на конец года year
	  int min_year_change_first_name = min_key_leq(year, name_change_years);
	  int min_year_change_last_name = min_key_leq(year, last_name_change_years);
	  //cout << year << " " << min_year_change_first_name << " " << min_year_change_last_name << endl;
	  if (min_year_change_first_name==ph_year) {
		  if (min_year_change_last_name !=ph_year) {
			  return last_name_changes.at(min_year_change_last_name) + " with unknown first name";
		  } else {
			  return "Incognito";
		  }
	  } else {
		  if (min_year_change_last_name !=ph_year) {
			  return name_changes.at(min_year_change_first_name) + " " + last_name_changes.at(min_year_change_last_name);
		  } else {
			  return name_changes.at(min_year_change_first_name) + " with unknown last name";
		  }
	  }
	  return " ";
  }
  string GetFullNameWithHistory(int year) const {
	  if (year < birth_year) {
	  		  return "No person";
	  	  }
      // получить все имена и фамилии по состоянию на конец года year
	  vector<int> first_name_prev_years = all_keys_leq(year, name_change_years);
	  vector<int> last_name_prev_years = all_keys_leq(year, last_name_change_years);
	  string out;
	  if ((first_name_prev_years.size()==0) && (last_name_prev_years.size()==0)) {
		  return "Incognito";
	  }
	  if (first_name_prev_years.size()!=0) {

		  out += name_changes.at(first_name_prev_years[0]);
		  out += previous_names(first_name_prev_years, name_changes);
		  if ((last_name_prev_years.size()==0)) {
			  out += " with unknown last name";
		  } else {
			  out += " ";
			  out += last_name_changes.at(last_name_prev_years[0]);
			  out += previous_names(last_name_prev_years, last_name_changes);
		  }
	  }

	  if ((last_name_prev_years.size()!=0) && (first_name_prev_years.size()==0)) {

	  		  out += last_name_changes.at(last_name_prev_years[0]);
	  		  out += previous_names(last_name_prev_years, last_name_changes);
	  		  out += " with unknown first name";
	  	  }
	  return out;

  }

  string previous_names(vector<int> years, map<int, string> names) const {
	  set<string> used_names;
	  //PrintDict(names);
	  string out = " (";
	  if (years.size()>1) {
		  string prev = names[years[0]];
		  for (int i=1; i<years.size(); i++) {
			  if (prev != names[years[i]]) {
				  out += names[years[i]];
				  out += ", ";

			  }
			  prev = names[years[i]];
		  }
		  out = out.substr(0, out.size()-2);
		  if (out.size() == 0) {
			  return "";
		  }
		  out += ")";
		  return out;
	  }
	  else {
		  return "";
	  }
  }
private:
  // приватные поля
  map<int, string> name_changes;
  map<int, string> last_name_changes;
  int birth_year;
  int ph_year = 100000;
  vector<int> name_change_years;
  vector<int> last_name_change_years;
  int min_key_leq(int year, vector<int> vct) const {
	  for (int i=vct.size()-1; i>=0; i--) {
		  if (vct[i]-year <= 0) {
			  return vct[i];
		  }
	  }
	  return ph_year;
  }

  vector<int> all_keys_leq(int year, vector<int> vct) const {
	  vector<int> out;
  	  for (int i=vct.size()-1; i>=0; i--) {
  		  if (vct[i]-year <= 0) {
  			  out.push_back(vct[i]);
  		  }
  	  }
  	  return out;
    }
};

int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}
