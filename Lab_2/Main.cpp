#include "Student.h"
#include "Course.h"
#include "Schedule.h"
#include <iostream>

using namespace std;

int main() {
    Student s1("Ivan", 18, 1);
    Student s2("Petro", 19, 2);

    cout << "Students:\n";
    cout << "\nTotal students: " << Student::getCount() << endl;
    s1.display();
    s2.display();

    Student s3 = s1 + s2;
    cout << "\nCombined student:\n";
    s3.display();

    Teacher t1("Dr.Smith", "Math");

    Course c1("Algebra", "OldTeacher", 3);
    Course c2("Physics", &t1, 4);

    cout << "\nCourses:\n";
    c1.display();
    c2.display();

    OnlineCourse oc1("C++", &t1, 5, "Udemy");

    cout << "\nOnline course:\n";
    oc1.display();

    Schedule sch1("Monday", "10:00", "101", &c2);

    cout << "\nSchedule:\n";
    sch1.display();

    ExamSchedule ex1("Friday", "12:00", "202", &c2, "Final");

    cout << "\nExam schedule:\n";
    ex1.display();

    return 0;
}