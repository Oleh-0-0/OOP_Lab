#ifndef MENU_H
#define MENU_H

#include "Repository.h"
#include "HistoryLogger.h"
#include <iostream>
#include <limits>

using namespace std;

class Menu {
private:
    Repository repo;
    HistoryLogger logger;

    void adminLoop();
    void userLoop();
    void adminCoursesMenu();
    void adminSchedulesMenu();

public:
    Menu() = default;
    void run();
};

inline static void clearInput() {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

inline void Menu::adminLoop() {
    cout << "Enter admin password: ";
    string pwd;
    cin >> pwd;
    if (pwd != "123") {
        cout << "Invalid password.\n";
        return;
    }
    logger.log("admin", "login");

    while (true) {
        cout << "\nAdmin menu:\n";
        cout << "1) Add student\n2) Remove student\n3) List students\n4) Courses menu\n5) Schedules menu\n6) Save\n7) Logout\nChoose: ";
        int choice;
        if (!(cin >> choice)) { clearInput(); continue; }

        if (choice == 1) {
            clearInput();
            cout << "Name: "; string name; getline(cin, name);
            cout << "Age: "; int age; cin >> age;
            cout << "Year: "; int year; cin >> year;
            repo.addStudent(name, age, year);
            logger.log("admin", "added student: " + name);
            cout << "Added.\n";
        } else if (choice == 2) {
            cout << "Index to remove (0-based): "; size_t idx; cin >> idx;
            if (repo.removeStudentByIndex(idx)) {
                logger.log("admin", "removed student index: " + to_string(idx));
                cout << "Removed.\n";
            } else cout << "Invalid index.\n";
        } else if (choice == 3) {
            const auto& v = repo.getStudents();
            for (size_t i = 0; i < v.size(); ++i) {
                cout << i << ") "; v[i]->display();
            }
        } else if (choice == 4) {
            adminCoursesMenu();
        } else if (choice == 5) {
            adminSchedulesMenu();
        } else if (choice == 6) {
            if (repo.saveStudents() && repo.saveCourses() && repo.saveSchedules()) cout << "Saved.\n"; else cout << "Save failed.\n";
        } else if (choice == 7) {
            logger.log("admin", "logout");
            break;
        }
    }
}

inline void Menu::adminCoursesMenu() {
    while (true) {
        cout << "\nCourses menu:\n1) Add course\n2) Remove course\n3) List courses\n4) Back\nChoose: ";
        int c; if (!(cin >> c)) { clearInput(); continue; }
        if (c == 1) {
            clearInput();
            cout << "Title: "; string title; getline(cin, title);
            cout << "Teacher name: "; string t; getline(cin, t);
            cout << "Credits: "; int cr; cin >> cr;
            repo.addCourse(title, t, cr);
            logger.log("admin", "added course: " + title);
        } else if (c == 2) {
            cout << "Index to remove: "; size_t idx; cin >> idx;
            if (repo.removeCourseByIndex(idx)) cout << "Removed.\n"; else cout << "Invalid index.\n";
        } else if (c == 3) {
            const auto& v = repo.getCourses();
            for (size_t i = 0; i < v.size(); ++i) { cout << i << ") "; v[i]->display(); }
        } else if (c == 4) break;
    }
}

inline void Menu::adminSchedulesMenu() {
    while (true) {
        cout << "\nSchedules menu:\n1) Add schedule\n2) Remove schedule\n3) List schedules\n4) Back\nChoose: ";
        int c; if (!(cin >> c)) { clearInput(); continue; }
        if (c == 1) {
            clearInput();
            cout << "Day: "; string day; getline(cin, day);
            cout << "Time: "; string time; getline(cin, time);
            cout << "Room: "; string room; getline(cin, room);
            cout << "Course index (or -1): "; int ci; cin >> ci;
            size_t cidx = (ci >= 0) ? static_cast<size_t>(ci) : std::numeric_limits<size_t>::max();
            if (cidx != std::numeric_limits<size_t>::max()) repo.addSchedule(day, time, room, cidx);
            else repo.addSchedule(day, time, room, 0);
            logger.log("admin", "added schedule: " + day + " " + time);
        } else if (c == 2) {
            cout << "Index to remove: "; size_t idx; cin >> idx;
            if (repo.removeScheduleByIndex(idx)) cout << "Removed.\n"; else cout << "Invalid index.\n";
        } else if (c == 3) {
            const auto& v = repo.getSchedules();
            for (size_t i = 0; i < v.size(); ++i) { cout << i << ") "; v[i]->display(); }
        } else if (c == 4) break;
    }
}

inline void Menu::userLoop() {
    logger.log("user", "entered user menu");
    while (true) {
        cout << "\nUser menu:\n1) List students\n2) View student details\n3) Back\nChoose: ";
        int choice;
        if (!(cin >> choice)) { clearInput(); continue; }
        if (choice == 1) {
            const auto& v = repo.getStudents();
            for (size_t i = 0; i < v.size(); ++i) {
                cout << i << ") "; v[i]->display();
            }
        } else if (choice == 2) {
            cout << "Index: "; size_t idx; cin >> idx;
            const auto& v = repo.getStudents();
            if (idx < v.size()) v[idx]->display(); else cout << "Invalid index.\n";
        } else if (choice == 3) {
            break;
        }
    }
}

inline void Menu::run() {
    repo.loadStudents();
    repo.loadCourses();
    repo.loadSchedules();

    while (true) {
        cout << "\nMain menu:\n1) Login as Admin\n2) Use as User\n3) Exit\nChoose: ";
        int choice;
        if (!(cin >> choice)) { clearInput(); continue; }
        if (choice == 1) adminLoop();
        else if (choice == 2) userLoop();
        else if (choice == 3) {
            repo.saveStudents();
            repo.saveCourses();
            repo.saveSchedules();
            break;
        }
    }
}

#endif
