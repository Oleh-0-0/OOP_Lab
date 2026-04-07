#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "InterfaceSystem.h"
#include <string>
#include <iostream>
#include "Course.h"

using namespace std;

class Schedule : public InterfaceSystem {
private:
    string day;
    string time;
    string room;
    Course* course;

public:
    Schedule();
    Schedule(string day, string time, string room);
    Schedule(string day, string time, string room, Course* course);

    Schedule(const Schedule& other);
    Schedule& operator=(const Schedule& other);

    bool canAccess(string zone) const override;
    void showType() const override;
    string getIdentifier() const override;

    virtual ~Schedule();

    virtual void display() const;
};

class ExamSchedule : public Schedule {
private:
    string examType;

public:
    ExamSchedule(string day, string time, string room,
        Course* course, string examType);

    void display() const override;
};

#endif