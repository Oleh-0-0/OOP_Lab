#ifndef SCHEDULE_H
#define SCHEDULE_H
#include <string>
using namespace std;
class Schedule
{
private:
	string day;
	string time;
	int auditorium;
public:
	Schedule();
	Schedule(string day, string time, int auditorium);
	~Schedule();
	void display() const;
};
#endif
