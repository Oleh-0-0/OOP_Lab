#include "Course.h"
#include <iostream>
using namespace std;

Course::Course(string name_course, string teacher, int ball)
	: name_course(name_course), teacher(teacher), ball(ball) {
}

Course::Course() : Course("OOP", "Val", "5") {}

Course::~Course()
{
	cout << "Course deleate\n"
}

void Course::display() const
{
	cout << "Name Course " << name_course << ", Teacher " << teacher << ", Ball " << ball << endl;
}