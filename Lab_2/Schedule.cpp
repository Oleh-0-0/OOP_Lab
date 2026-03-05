#include "Schedule.h"
#include <iostream>
using namespace std;

Schedule::Schedule(string day, string time, int auditorium)
	: day(day), time(time), auditorium(auditorium) {
}

Schedule::Schedule() : Schedule("Monday", "8:20", 212 ) {}

Schedule::~Schedule()
{
	cout << "Schedule deleate\n";
}

void Schedule::display() const
{
	cout << "Day " << day << ", Time " << time << ", Auditorium " << auditorium << endl;
}