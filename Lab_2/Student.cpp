#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(string name, string surname, int age)
	: name(name), surname(surname), age(age) {}

Student::Student() : Student("Oleh", "Frayuk", "18") {}

Student::~Student() 
{
	cout << "User deleate\n"
}

void Student::display() const
{
	cout << "Name " << name << ", Surname " << surname << ", Age " << age << endl;
}