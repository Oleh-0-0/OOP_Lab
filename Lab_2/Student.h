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

	static int studentCount;

public:

	Student();
	Student(string name, string surname, int age);
	Student(const Student& other);
	Student(Student&& other);
	~Student();

	void display() const;
	void setAge(int age);

	static int getCount();

	Student operator+(const Student& other);


	friend ostream& operator<<(ostream& os, const Student& s);
	friend istream& operator>>(istream& is, Student& s);
};
#endif