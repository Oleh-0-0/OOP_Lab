#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

using namespace std;

class Person {
protected:
    string name;

public:
    Person() {}
    Person(string name) : name(name) {}

    virtual ~Person() {}
     void display() {
        cout << "Name: " << name << endl;
    }

     virtual void check() { cout << "General background check in the university database."; }
     virtual void getStatus() { cout << "Status: the person is present at the facility."; }
};

class Teacher {
private:
    string name;
    string subject;

public:
    Teacher(string name = "Unknown", string subject = "Unknown")
        : name(name), subject(subject) {
    }

    void display() const {
        cout << "Teacher: " << name
            << ", Subject: " << subject << endl;
    }
};

class Student : public Person {
private:
    int age;
    int year;

    static int studentCount;

public:
    Student();
    Student(string name, int age, int year = 1);

    Student(const Student& other);
    Student(Student&& other) noexcept;

    Student& operator=(const Student& other);

    ~Student();

    void display() const;

    void setAge(int age);

    static int getCount();

    void check()  override;

    void getStatus() override;


    Student operator+(const Student& other);

    friend ostream& operator<<(ostream& os, const Student& s);
    friend istream& operator>>(istream& is, Student& s);
};

#endif