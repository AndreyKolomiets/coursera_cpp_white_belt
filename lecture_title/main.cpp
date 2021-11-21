#include <string>
using namespace std;

struct Specialization{
	explicit Specialization(string new_value) {
		value = new_value;
	}
	string value;
};

struct Course{
	explicit Course(string new_value) {
		value = new_value;
	}
	string value;
};

struct Week{
	explicit Week(string new_value) {
		value = new_value;
	}
	string value;
};

struct LectureTitle {
public:
	LectureTitle(Specialization new_spec, Course new_course, Week new_week) {
		specialization = new_spec.value;
		course = new_course.value;
		week = new_week.value;
	}
  string specialization;
  string course;
  string week;
};


int main() {
	LectureTitle title(
	    Specialization("C++"),
	    Course("White belt"),
	    Week("4th")
	);

	//LectureTitle title("C++", "White belt", "4th");
//	LectureTitle title(string("C++"), string("White belt"), string("4th"));
//
//	LectureTitle title = {"C++", "White belt", "4th"};
//
//	LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};
//
//	LectureTitle title(
//	    Course("White belt"),
//	    Specialization("C++"),
//	    Week("4th")
//	);
//
//	LectureTitle title(
//	    Specialization("C++"),
//	    Week("4th"),
//	    Course("White belt")
//	);
	return 0;
}
