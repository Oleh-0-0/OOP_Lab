#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;
class Student
{
private:
	string name;
	string surname;
	int age;
public:
	Student();
	Student(string name, string surname, int age);
	~Student();
	void display() const;
};
#endif