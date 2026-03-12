#include "Course.h"
#include <iostream>
using namespace std;

Course::Course(string name_course, string teacher, int credits)
	: name_course(name_course), teacher(teacher), credits(credits) {
}

Course::Course() : Course("OOP", "Val", 5 ) {}

Course::~Course()
{
	cout << "Course delete\n";
}

void Course::display() const
{
	cout << "Name Course " << name_course << ", Teacher " << teacher << ", Credits " << credits << endl;
}