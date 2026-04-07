#include "Student.h"
#include "Course.h"
#include "Schedule.h"
#include <iostream>

using namespace std;

int main() {
    Student s1("Ivan", 18, 1);
    Student s2("Petro", 19, 2);
    

    Teacher t1("Dr.Smith", "Math");

    Course c1("Algebra", "Teacher", 3);
    Course c2("Physics", &t1, 4);

    OnlineCourse oc1("C++", &t1, 5, "Udemy");

    Schedule sch1("Monday", "10:00", "101", &c2);

    ExamSchedule ex1("Friday", "12:00", "202", &c2, "Final");

    cout << "Students:\n";
    cout << "\nTotal students: " << Student::getCount() << endl;
    s1.display();
    s2.display();

    Person* test = new Student("Max", 18, 1);
    test->display();

    Student s3 = s1 + s2;
    cout << "\nCombined student:\n";
    s3.display();

    cout << "\nStatus student: \n";

    Person* test2 = new Student("Dima", 19, 2);
    test2->check();

    Person* test3 = new Student("Vova", 18, 1);
    test3->getStatus();

    cout << "\nCourses:\n";
    c1.display();
    c2.display();


    cout << "\nOnline course:\n";
    oc1.display();


    cout << "\nSchedule:\n";
    sch1.display();

    cout << "\nExam schedule:\n";
    ex1.display();

    return 0;
}