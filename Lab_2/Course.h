#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>
#include "Student.h"

using namespace std;

class Course {
private:
    string title;
    string teacher;
    int credits;

    Teacher* teacherObj;

public:
    Course();
    Course(string title, string teacher, int credits = 3);
    Course(string title, Teacher* teacherObj, int credits = 3);

    Course(const Course& other);
    Course& operator=(const Course& other);

    virtual ~Course();

    virtual void display() const;
};

class OnlineCourse : public Course {
private:
    string platform;

public:
    OnlineCourse(string title, Teacher* teacherObj, int credits, string platform);

    void display() const override;
};

#endif