#include "Student.h"
#include <iostream>

using namespace std;

int Student::studentCount = 0;

Student::Student() : Student("Oleh", "Frayuk", 18) {}

Student::Student(string name, string surname, int age)
    : name(name), surname(surname), age(age) {
    studentCount++;
}

Student::Student(const Student& other)
    : name(other.name), surname(other.surname), age(other.age) 
{
    cout << "Student copied\n";
}


Student::Student(Student&& other)
    : name(move(other.name)), surname(move(other.surname)),
    age(other.age)
{
    cout << "Student moved\n"
}

Student::~Student()
{
    studentCount--;
    cout << "Student delete\n";
}

void Student::display() const
{
    cout << "Name: " << name << ", Surname: " << surname << ", Age: " << age << endl;
}

void Student::setAge(int age) 
{
    this->age = age;
}

int Student::getCount()
{
    return studentCount;
}

Student Student::operator+(const Student& other)
{
    return Student(name + "&" + other.name, surname, age);
}

ostream& operator<<(ostream& os, const Student& s)
{
    os << s.name << " " << s.surname "" << s.age;
    return os;
}

istream& operator>>(istream& is, Student& s) 
{
    is >> s.name >> s.surname >> s.age;
    return is;
}