#include "Schedule.h"
#include <iostream>

Schedule::Schedule() : Schedule("Monday", "08:00", "101") {}

Schedule::Schedule(string day, string time, string room)
    : day(day), time(time), room(room), course(nullptr) {
}

Schedule::Schedule(string day, string time, string room, Course* course)
    : day(day), time(time), room(room) {
    if (course)
        this->course = new Course(*course);
    else
        this->course = nullptr;
}

Schedule::Schedule(const Schedule& other)
    : day(other.day), time(other.time), room(other.room) {
    if (other.course)
        course = new Course(*other.course);
    else
        course = nullptr;
}

Schedule& Schedule::operator=(const Schedule& other) {
    if (this != &other) {
        day = other.day;
        time = other.time;
        room = other.room;

        delete course;

        if (other.course)
            course = new Course(*other.course);
        else
            course = nullptr;
    }
    return *this;
}

Schedule::~Schedule() {
    delete course;
    cout << "Schedule destroyed" << endl;
}

void Schedule::display() const {
    cout << "Day: " << day << ", Time: " << time  << ", Room: " << room << endl;

    if (course)
        course->display();
}

ExamSchedule::ExamSchedule(string day, string time, string room,
    Course* course, string examType)
    : Schedule(day, time, room, course), examType(examType) {
}

void ExamSchedule::display() const {
    Schedule::display();
    cout << "Exam type: " << examType << endl;
}