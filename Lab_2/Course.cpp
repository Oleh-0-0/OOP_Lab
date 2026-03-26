#include "Course.h"
#include <iostream>

Course::Course() : Course("Unknown", "Unknown", 3) {}

Course::Course(string title, string teacher, int credits)
    : title(title), teacher(teacher), credits(credits), teacherObj(nullptr) {
}

Course::Course(string title, Teacher* teacherObj, int credits)
    : title(title), teacher(""), credits(credits) {
    if (teacherObj)
        this->teacherObj = new Teacher(*teacherObj);
    else
        this->teacherObj = nullptr;
}

Course::Course(const Course& other)
    : title(other.title),
    teacher(other.teacher),
    credits(other.credits) {
    if (other.teacherObj)
        teacherObj = new Teacher(*other.teacherObj);
    else
        teacherObj = nullptr;

    cout << "Course copied" << endl;
}

Course& Course::operator=(const Course& other) {
    if (this != &other) {
        title = other.title;
        teacher = other.teacher;
        credits = other.credits;

        delete teacherObj;

        if (other.teacherObj)
            teacherObj = new Teacher(*other.teacherObj);
        else
            teacherObj = nullptr;
    }
    return *this;
}

Course::~Course() {
    delete teacherObj;
    cout << "Course destroyed" << endl;
}

void Course::display() const {
    cout << "Course: " << title << ", Teacher: " << teacher << ", Credits: " << credits << endl;

    if (teacherObj)
        teacherObj->display();
}

OnlineCourse::OnlineCourse(string title, Teacher* teacherObj, int credits, string platform)
    : Course(title, teacherObj, credits), platform(platform) {
}

void OnlineCourse::display() const {
    Course::display();
    cout << "Platform: " << platform << endl;
}