#ifndef COURSE_H
#define COURSE_H
#include <string>
using namespace std;
class Course
{
private:
	string name_course;
	string teacher;
	int credits;
public:
	Course();
	Course(string name_course, string teacher, int credits);
	~Course();
	void display() const;
};
#endif
