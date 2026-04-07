#ifndef STUDENT_H
#define STUDENT_H

#include "InterfaceSystem.h"
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
    virtual void display() const{
        cout << "Name: " << name << endl;
    }

     virtual void check() const { cout << "General background check in the university database."; }
     virtual void getStatus() const { cout << "Status: the person is present at the facility."; }
};

class Teacher : public InterfaceSystem {
private:
    string name;
    string subject;

public:
    Teacher(string name = "Unknown", string subject = "Unknown")
        : name(name), subject(subject) {
    }

    bool canAccess(string zone) const override {
        return true; 
    }

    void showType() const override {
        cout << "Object_type: Teacher";
    }

    string getIdentifier() const override {
        return "Teacer " + name;
    }

    void display() const {
        cout << "Teacher: " << name
            << ", Subject: " << subject << endl;
    }
};

class Student final : public Person, public InterfaceSystem {
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

    void display() const override;

    void setAge(int age) ;

    static int getCount();

    void check() const override final;

    void getStatus() const override final;

    bool canAccess(string zone) const override;

    void showType() const override;

    string getIdentifier() const override;


    Student operator+(const Student& other);

    friend ostream& operator<<(ostream& os, const Student& s);
    friend istream& operator>>(istream& is, Student& s);
};

#endif