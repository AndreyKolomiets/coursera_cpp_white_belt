// Реализуйте функции и методы классов и при необходимости добавьте свои
#include <iostream>
#include <string>
#include <exception>
#include <map>
#include <set>
#include <iomanip>
#include <sstream>
using namespace std;

class Date {
public:
	Date(int year, int month, int day) {
		this->year = year;
		this->month = month;
		this->day = day;
	}
	Date() {
		this->year = 1970;
		this->month = 1;
		this->day = 1;
	}
  int GetYear() const {
	  return year;
  };
  int GetMonth() const {return month;};
  int GetDay() const {return day;};
private:
  int year;
  int month;
  int day;
};

bool operator<(const Date& lhs, const Date& rhs){
	int n_days_l = lhs.GetYear()*365+lhs.GetMonth()*30 + lhs.GetDay();
	int n_days_r = rhs.GetYear()*365+rhs.GetMonth()*30 + rhs.GetDay();
	return n_days_l < n_days_r;
}

void EnsureNextIsHyphen(istringstream& stream, string line) {
	if (stream.peek() != '-') {
			throw invalid_argument("Wrong date format: "+line);
	}
}

istream& operator>>(istream& stream, Date& date) {
	string line;
	stream >> line;
	istringstream s(line);
	int day, month, year;
	s >> year;
	EnsureNextIsHyphen(s, line);
	s.ignore(1);
	s >> month;
	if (s.fail()) {
		throw invalid_argument("Wrong date format: "+line);
	}

	EnsureNextIsHyphen(s, line);
	s.ignore(1);
	s >> day;
	if (s.fail()) {
		throw invalid_argument("Wrong date format: "+line);
	}

	string last_s;
	if (s >> last_s) {
		throw invalid_argument("Wrong date format: "+line);
	}
	if ((month < 1) || (month>12)) {
			throw invalid_argument("Month value is invalid: "+to_string(month));
		}
	if ((day < 1) || (day > 31)) {
			throw invalid_argument("Day value is invalid: " + to_string(day));
		}
	date = Date(year, month, day);
	return stream;
}

ostream& operator<<(ostream& stream, const Date& date) {
	stream << setw(4) << setfill('0') << date.GetYear() << "-" << setw(2) << setfill('0') <<  date.GetMonth() << "-" <<  setw(2) << setfill('0') << date.GetDay();
	return stream;
}

class Database {
public:
  void AddEvent(const Date& date, const string& event){
	  base[date].insert(event);
  }
  bool DeleteEvent(const Date& date, const string& event) {
	  if (base[date].count(event) == 1) {
		  base[date].erase(event);
		  cout << "Deleted successfully" << endl;
		  return true;
	  } else {
		  cout << "Event not found" << endl;
	  }
	  return false;
  }
  int DeleteDate(const Date& date) {
	 if (base.count(date) == 1) {
		 int N = base.at(date).size();
		 base.erase(date);
	 	 cout << "Deleted " << to_string(N) << " events" << endl;
	 	 return N;
	 } else {
		 cout << "Deleted 0 events" << endl;
	 }
	 return 0;
  }

  /* ??? */void Find(const Date& date) const {
	  if (base.count(date) == 1) {
		  set<string> events = base.at(date);
		  for (const string& event: events) {
			  cout << event << endl;
		  }
	  }
  }

  void Print() const {
	  for (const auto& item: base) {
		  Date curr_date = item.first;
		  for (const string& event: item.second) {
			  cout << curr_date << " " << event << endl;
		  }
	  }
  }
private:
  map<Date, set<string> > base;
};

int main() {
  Database db;
  string command;
  string cmd;
  while (getline(cin, command)) {
    // Считайте команды с потока ввода и обработайте каждую
	  istringstream s(command);
	  Date date;
	  string event;
	  if (s.str() == "") {
		  continue;
	  }
	  s >> cmd;
	  //cout << cmd << endl;
	  try {
		  if (cmd == "Add") {

			  s >> date >> event;
			  db.AddEvent(date, event);
		  } else if (cmd == "Del") {
			  s >> date >> event;
			  if (event == "") { //здесь мб проверять s.fail()
				  db.DeleteDate(date);
			  } else {
				  db.DeleteEvent(date, event);
			  }

		  } else if (cmd == "Find") {
			  s >> date;
			  db.Find(date);
		  } else if (cmd == "Print") {
			  db.Print();
		  } else {
			  cout << "Unknown command: " << cmd << endl;
		  }
	  } catch (invalid_argument& exc) {
		  cout << exc.what() << endl;
	  }
  }

  return 0;
}
