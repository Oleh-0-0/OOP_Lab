#ifndef COURSE_H
#define COURSE_H
#include <string>
using namespace std;
class Course
{
private:
	string name_course;
	string teacher;
	int ball;
public:
	Course();
	Course(string name_course, string teacher, int ball);
	~Course();
	void display() const;
};
#endif
