#include "Student.h"
#include <iostream>
#include <utility>

int Student::studentCount = 0;

Student::Student() : Student("Unknown", 18, 1) {}

Student::Student(string name, int age, int year)
    : Person(name), age(age), year(year) {
    studentCount++;
}

Student::Student(const Student& other)
    : Person(other), age(other.age), year(other.year) {
    cout << "Student copied\n";
}

Student::Student(Student&& other) noexcept
    : Person(move(other)), age(other.age), year(other.year) {
    cout << "Student moved\n";
}

Student& Student::operator=(const Student& other) {
    if (this != &other) {
        Person::operator=(other);
        age = other.age;
        year = other.year;
    }
    return *this;
}

Student::~Student() {
    cout << "Student destroyed\n";
}

void Student::display() const {
    cout << "Name: " << name << ", Age: " << age << ", Year: " << year << endl;
}

void Student::check() { cout << "\nExam permit check for student " << name << ": no academic debts found.\n"; }
void Student::getStatus() { cout << "\nStatus: student " << name << " is actively preparing for exams.\n"; }

void Student::setAge(int age) {
    this->age = age;
}

int Student::getCount() {
    return studentCount;
}

Student Student::operator+(const Student& other) {
    return Student(name + "&" + other.name, age, year);
}

ostream& operator<<(ostream& os, const Student& s) {
    os << s.name << " " << s.age << " " << s.year;
    return os;
}

istream& operator>>(istream& is, Student& s) {
    is >> s.name >> s.age >> s.year;
    return is;
}